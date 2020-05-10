#include "chess.h"

////
//// Includes
////

#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>


#include "mersenne.h"
#include "movegen.h"
#include "movepick.h"
#include "position.h"
#include "notation.h"
#include "tt.h"
#include "uci.h"

//enum Piece
//{
//	EMPTY = 0,  // ���������
//	RKING = 1, RSHI = 2, RXIANG = 3, RMA = 4, RCHE = 5, RPAO = 6, RPAWN = 7,
//	_X_X = 8,
//	BKING = 9, BSHI = 10, BXIANG = 11, BMA = 12, BCHE = 13, BPAO = 14, BPAWN = 15,
//};


template<PieceType Pt>
PieceType Position::min_attacker(const Bitboard* bb, Square to, Bitboard stmAttackers,
	Bitboard& occupied, Bitboard& attackers, Piece delta) {
	
	Bitboard b = m_and(stmAttackers, bb[Pt + delta]);

	if (!m_have_bit(b)) {
		switch (Pt) {
		case PAWN:
			return min_attacker<SHI>(bb, to, stmAttackers, occupied, attackers, delta);
			break;
		case SHI:
			return min_attacker<XIANG>(bb, to, stmAttackers, occupied, attackers, delta);
			break;
		case XIANG:
			return min_attacker<MA>(bb, to, stmAttackers, occupied, attackers, delta);
			break;
		case MA:
			return min_attacker<PAO>(bb, to, stmAttackers, occupied, attackers, delta);
			break;
		case PAO:
			return min_attacker<CHE>(bb, to, stmAttackers, occupied, attackers, delta);
			break;
		default:
			return min_attacker<KING>(bb, to, stmAttackers, occupied, attackers, delta);
		}
	}

	clear_bit(occupied, first_1(b));

	switch (Pt) {
	case CHE:
	case PAO:
	case PAWN:
		// ��
		attackers = m_or(attackers,
			m_and(Pao_Eat_bb(to, occupied),
				m_or(pieces(RPAO), pieces(BPAO))));

		// ��
		attackers = m_or(attackers,
			m_and(Rook_attacks_bb(to, occupied),
				m_or(pieces(RCHE), pieces(BCHE))));
		break;
	case SHI: // 
		attackers = m_or(attackers,
			m_and(king_to_ma_attacks_bb(to, occupied),
				m_or(pieces(RMA), pieces(BMA))));
	default:
		break;
	}

	attackers = m_and(attackers, occupied);
	return Pt;
}

template<>
PieceType Position::min_attacker<KING>(const Bitboard* bb, Square to, Bitboard stmAttackers,
	Bitboard& occupied, Bitboard& attackers, Piece delta) {
	return KING;
}

using std::string;

static const Value seeValues[8] = {
	VALUE_ZERO,  // EMPTY
	CHE_VAL * 10, SHI_VAL, XIANG_VAL, MA_VAL, CHE_VAL, PAO_VAL, XIANG_VAL // was PAWN_VAL
};

bool Position::see_ge(Move m, Value v){
	
	assert(is_ok(m));

	// Castling moves are implemented as king capturing the rook so cannot be
	// handled correctly. Simply assume the SEE value is VALUE_ZERO that is always
	// correct unless in the rare case the rook ends up under attack.
	//if (type_of(m) == CASTLING)
	//	return VALUE_ZERO >= v;

	Square from = from_sq(m), to = to_sq(m);
	PieceType nextVictim = type_of(piece_on(from));
	Color stm = ~color_of(piece_on(from)); // First consider opponent's move
	Value balance; // Values of the pieces taken by us minus opponent's ones
	Bitboard occupied, stmAttackers;

	balance = PieceValueMidgame[piece_on(to)];
	occupied = occupied_squares();

	if (balance < v)
		return false;

	if (nextVictim == KING)
		return true;

	balance -= PieceValueMidgame[nextVictim];

	if (balance >= v)             // С�ӳԴ��ӣ���ƽ���໥�ԣ��ͻ���OK��
		return true;

	bool relativeStm = true; // True if the opponent is to move
	clear_bit(occupied, from);
	// set_bit(occupied, to);

	// Find all attackers to the destination square, with the moving piece removed,
	// but possibly an X-ray attacker added behind it.
	//Bitboard attackers = m_and(
	//	m_or(m_and(attacks_by_rpawn_rk(to), m_or(pieces(RPAWN),pieces(RKING))),
	//	m_or(m_and(attacks_by_bpawn_bk(to), m_or(pieces(BPAWN),pieces(BKING))),
	//	m_or(m_and(shi_attacks(to), m_or(pieces(RSHI), pieces(BSHI))),
	//	m_or(m_and(xiang_attacks_bb(to, occupied), m_or(pieces(RXIANG), pieces(BXIANG))),
	//	m_or(m_and(king_to_ma_attacks_bb(to, occupied), m_or(pieces(RMA), pieces(BMA))),
	//	m_or(m_and(Pao_Eat_bb(to, occupied), m_or(pieces(RPAO), pieces(BPAO))),
	//	m_and(Rook_attacks_bb(to, occupied), m_or(pieces(RCHE), pieces(BCHE))))))))),occupied);


	Bitboard attackers = m_and(
		m_or(m_and(attacks_by_rpawn_rk(to), pieces(RPAWN)),
			m_or(m_and(attacks_by_bpawn_bk(to), pieces(BPAWN)),
				m_or(m_and(shi_attacks(to), m_or(pieces(RSHI), pieces(BSHI))),
					m_or(m_and(xiang_attacks_bb(to, occupied), m_or(pieces(RXIANG), pieces(BXIANG))),
						m_or(m_and(king_to_ma_attacks_bb(to, occupied), m_or(pieces(RMA), pieces(BMA))),
							m_or(m_and(Pao_Eat_bb(to, occupied), m_or(pieces(RPAO), pieces(BPAO))),
								m_and(Rook_attacks_bb(to, occupied), m_or(pieces(RCHE), pieces(BCHE))))))))), occupied);

	while (true) {
		stmAttackers = m_and(attackers, pieces_of_color(stm));

		Piece delta = COLOR_BY_SIDE_ADD[stm];

		// Don't allow pinned pieces to attack pieces except the king as long all
		// pinners are on their original square. ��ȥ�˲����ߵ����� 
		//if (!(st->pinnersForKing[stm] & ~occupied))
		//	stmAttackers &= ~st->blockersForKing[stm];		

		if (!m_have_bit(stmAttackers))
			return relativeStm;		

		// Locate and remove the next least valuable attacker
		nextVictim = min_attacker<PAWN>(byChessBB, to, stmAttackers, occupied, attackers, delta);

		if (nextVictim == KING) {
			return relativeStm == have_bit(attackers, pieces_of_color(~stm));
		}

		balance += relativeStm ? PieceValueMidgame[nextVictim]
			: -PieceValueMidgame[nextVictim];

		relativeStm = !relativeStm;

		if (relativeStm == (balance >= v))
			return relativeStm;

		stm = ~stm;
	}

	//return false;
}

/// Position::see() is a static exchange evaluator: It tries to estimate the
/// material gain or loss resulting from a move. There are three versions of
/// this function: One which takes a destination square as input, one takes a
/// move, and one which takes a 'from' and a 'to' square. The function does
/// not yet understand promotions captures.
//
/*
Value Position::see_sign(Move m) {

	ASSERT(is_ok(m));

	// Early return if SEE cannot be negative because captured piece value
	// is not less then capturing one. Note that king moves always return
	// here because king midgame value is set to 0.
	if (PieceValueMidgame[piece_on(to_sq(m))] >= PieceValueMidgame[piece_on(from_sq(m))])
		return VALUE_KNOWN_WIN;

	return see(m);
}



// ȥ��˫���Ľ����������һЩ��
Value Position::see(Move m)  {

	Square from = from_sq(m);
	Square to   = to_sq(m);

	Bitboard scc, attackers, stmAttackers, b;
	Value swapList[32];
	int slIndex = 1;
	PieceType capturedType;
	Color stm;

	ASSERT(square_is_ok(from));
	ASSERT(square_is_ok(to));

	capturedType = type_of(piece_on(to));
	swapList[0] = seeValues[capturedType];
	stm = color_of(b90[from]);
	scc = occupied_squares();

	// Find all attackers to the destination square, with the moving piece
	// removed, but possibly an X-ray attacker added behind it.
	clear_bit(scc, from);

	//////////////////////////////////////////////////////////////////////////	

	// �õ��Է��ı�,���Ĺ������, ������һ��õ��������Ҫ��˫���Ľ��ˣ�������һЩ
	// ���
	attackers = m_or(m_and(attacks_by_rpawn_rk(to),pieces(RPAWN)),
		        m_or(m_and(attacks_by_bpawn_bk(to),pieces(BPAWN)),
				m_or(m_and(shi_attacks(to),m_or(pieces(RSHI),pieces(BSHI))),
				m_or(m_and(xiang_attacks_bb(to,scc),	m_or(pieces(RXIANG),pieces(BXIANG))),
				m_or(m_and(king_to_ma_attacks_bb(to,scc),m_or(pieces(RMA),pieces(BMA))),
				m_or(m_and(Pao_Eat_bb(to,scc),m_or(pieces(RPAO),pieces(BPAO))),
				     m_and(Rook_attacks_bb(to,scc),m_or(pieces(RCHE),pieces(BCHE)))))))));

	// If the opponent has no attackers we are finished
	stm = ~stm;
	stmAttackers = m_and(attackers,pieces_of_color(stm));
	if (!m_have_bit(stmAttackers))
		return swapList[0];

	// The destination square is defended, which makes things rather more
	// difficult to compute. We proceed by building up a "swap list" containing
	// the material gain or loss at each stop in a sequence of captures to the
	// destination square, where the sides alternately capture, and always
	// capture with the least valuable piece. After each capture, we look for
	// new X-ray attacks from behind the capturing piece.
	 capturedType = type_of(b90[from]);

	 do {

		 ASSERT(slIndex < 32);

		 // Add the new entry to the swap list		 
		 swapList[slIndex] = -swapList[slIndex - 1] + seeValues[capturedType];

		 Piece delta = COLOR_BY_SIDE_ADD[stm];

		 // ��
		 Piece pc = RPAWN + delta; 
		 if(have_bit(stmAttackers, pieces(pc))){
			 goto S_SEE_NEXT_A;
		 }

		 // ��
		 pc = RSHI + delta;
		 if(have_bit(stmAttackers, pieces(pc))){
			 goto S_SEE_NEXT_A;
		 }

		 // ��
		 pc = RXIANG + delta;
		 if(have_bit(stmAttackers, pieces(pc))){
			 goto S_SEE_NEXT_A;
		 }

		 // ��
		 pc = RMA + delta;
		 if(have_bit(stmAttackers, pieces(pc))){
			 goto S_SEE_NEXT_A;
		 }

		 // ��
		 pc = RPAO + delta;
		 if(have_bit(stmAttackers, pieces(pc))){
			 goto S_SEE_NEXT_A;		 
		 }

		 // ��
		 pc = RCHE + delta;
		 if(have_bit(stmAttackers, pieces(pc))){
			 goto S_SEE_NEXT_A;
		 }

		 //// ��
		 pc = RKING + delta;
		 //if(have_bit(stmAttackers, pieces(pc))){
			// goto S_SEE_NEXT_A;
		 //}

S_SEE_NEXT_A:

		b = m_and(stmAttackers,pieces(pc));  // �õ����ֳԶԷ������ӵ�����λ����
		Square sq = first_1(b);
		clear_bit(scc,sq);

		// Remove the attacker we just found from the 'attackers' bitboard,
		// and scan for new X-ray attacks behind the attacker.
		//b = stmAttackers & pieces(pt);
		//occ ^= (b & (~b + 1));


		// �ټ��Ͽ��ܳ��ֵ���������,�п�������,��,��//
		//attackers |=  (rook_attacks_bb(to, occ)   & pieces(ROOK, QUEEN))
		// | (bishop_attacks_bb(to, occ) & pieces(BISHOP, QUEEN));
		// ��
		switch(type_of(pc)){
		case CHE:
		case PAO:
		case PAWN:
			// ��
			attackers = m_or(attackers,
				m_and(Pao_Eat_bb(to,scc),
				m_or(pieces(RPAO),pieces(BPAO))));

			// ��
			attackers = m_or(attackers,
				m_and(Rook_attacks_bb(to,scc),
				m_or(pieces(RCHE),pieces(BCHE))));
			//attackers = _mm_andnot_si128(canNotMove,attackers);  // ȥ�˲����ߵ���
			break;
		case SHI: // 
			attackers = m_or(attackers,
				m_and(king_to_ma_attacks_bb(to,scc),
				m_or(pieces(RMA),pieces(BMA))));
			//attackers = _mm_andnot_si128(canNotMove,attackers);  // ȥ�˲����ߵ���
			break;
		default:
			break;
		}
		 //attackers &= occ; // Cut out pieces we've already done
		 attackers = m_and(attackers,scc);
	
		 // Remember the value of the capturing piece, and change the side to move
		 // before beginning the next iteration
		 capturedType = type_of(pc); // capturedType = pt;

		 if (capturedType == KING){
			 if (m128_is_same(stmAttackers, attackers))
				 ++slIndex;

			 break;
		 }
		 stm = ~stm;
		 stmAttackers = m_and(attackers, pieces_of_color(stm)); // stmAttackers = attackers & pieces_of_color(stm);
		 ++slIndex;

	 } while (m_have_bit(stmAttackers));

	 // Having built the swap list, we negamax through it to find the best
	 // achievable score from the point of view of the side to move
	 while (--slIndex)
		 swapList[slIndex-1] = std::min(-swapList[slIndex], swapList[slIndex-1]);

	 return swapList[0];
}

*/