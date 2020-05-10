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

using std::string;


/// CheckInfo constructor

CheckInfo::CheckInfo(Position& pos) {


	const Color us   = pos.side_to_move();
	const Color them = ~us;

	ksq = pos.king_square(them);                                               // �Է��Ľ���λ��.
	dcCandidates = pos.discovered_check_candidates(us);                        // �ҳ����пɳ齫������.
	PaoNull      = pos.findPaoNullBiboard(us,ksq);                             // �ҳ����пɵ��ڽ��ĸ���.

	Piece delt = COLOR_BY_SIDE_ADD[us];	
	checkSq[RCHE + delt]  = pos.Rook_attacks_bb(ksq);                           // �ҷ��ĳ��ܽ��������
	checkSq[RMA + delt]   = pos.king_to_ma_attacks_bb(ksq);                     // �ҷ������ܽ��������
	checkSq[RPAO + delt]  = pos.Pao_Eat_bb(ksq);                                // �ҷ������ܽ��������	
	checkSq[RPAWN + delt] = (us == WHITE ? 
		attacks_by_rpawn_rk(ksq) : attacks_by_bpawn_bk(ksq));                   // �ҷ��ı��ܽ��������	
	// ���������һ��. ����Ҫ�Ѳ���ֱ�ӽ�������ȥ�ˡ�
    // checkSq[RKING + delt] = checkSq[RSHI + delt] = checkSq[RXIANG + delt] = _mm_setzero_si128();
}



/// Position:discovered_check_candidates() returns a bitboard containing all
/// pieces for the given side which are candidates for giving a discovered
/// check. Contrary to pinned_pieces() here there is no need of checkersBB
/// to be already updated.
// �ҳ��ɳ齫������. 
Bitboard Position::discovered_check_candidates(Color c)  {

	//return hidden_checkers_FindPinned_false(c);

	Bitboard result  = _mm_setzero_si128();
	Bitboard occ      = occupied_squares();

	Square ksq = king_square(~c);
	Piece delt = COLOR_BY_SIDE_ADD[c];

	//1. ����. 
	Bitboard pin = m_and(pieces(RCHE + delt),ChePseudoMask_FR[ksq]);
	Square s;
	while (pop_1st_bit_sq(pin, s)) {
		Bitboard bb = m_and(squares_between(s,ksq),occ);
		if(count_1s(bb) == 1){
			result = m_or(result,m_and(bb,pieces_of_color(c)));
		}
	}

	//2. �ڵ�
	pin = m_and(pieces(RPAO + delt),ChePseudoMask_FR[ksq]);
	//Square s;
	while (pop_1st_bit_sq(pin, s)) {
		Bitboard bb = m_and(squares_between(s,ksq),occ);
		if(count_1s(bb) == 2){
			result = m_or(result,m_and(bb,pieces_of_color(c)));
		}
	}

	//3. ����.
	pin = m_and(pieces(RMA + delt),Ma_Pseudo_Att[ksq]);
	//Square s;
	while (pop_1st_bit_sq(pin, s)) {
		Square leg = maleg(s,ksq);
		if(color_of(b90[leg]) == c){
			set_bit(result,leg);
		}
	}

	return result;
}

Bitboard Position::sq_attack_by_color(Square sq, Color side) {


	if(side == WHITE){
        return m_or(m_and(Attack_By_Rpawn_Rking[sq],m_or(pieces(RPAWN),pieces(RKING))),
               m_or(m_and(Rook_attacks_bb(sq),	pieces(RCHE)),
               m_or(m_and(king_to_ma_attacks_bb(sq,byWhiteBlack), pieces(RMA)),
			   m_or(m_and(Pao_Eat_bb(sq), pieces(RPAO)),
			   m_or(m_and(shi_attacks(sq), pieces(RSHI)),
			        m_and(xiang_attacks_bb(sq,byWhiteBlack), pieces(RXIANG)))))));
	}
	else{
		return m_or(m_and(Attack_By_Bpawn_Bking[sq],m_or(pieces(BPAWN),pieces(BKING))),
			   m_or(m_and(Rook_attacks_bb(sq),	pieces(BCHE)),
			   m_or(m_and(king_to_ma_attacks_bb(sq,byWhiteBlack), pieces(BMA)),
			   m_or(m_and(Pao_Eat_bb(sq), pieces(BPAO)),
			   m_or(m_and(shi_attacks(sq), pieces(BSHI)),
			        m_and(xiang_attacks_bb(sq,byWhiteBlack), pieces(BXIANG)))))));
	}
}

/// Position::attackers_to() computes a bitboard containing all pieces which
/// attacks a given square.

Bitboard Position::attackers_to(Square sq){

	Bitboard occ = occupied_squares();
	return m_or(m_and(Attack_By_Rpawn_Rking[sq],m_or(pieces(RPAWN),pieces(RKING))),
		   m_or(m_and(Attack_By_Bpawn_Bking[sq],m_or(pieces(BPAWN),pieces(BKING))),
		   m_or(m_and(Rook_attacks_bb(sq),m_or(pieces(RCHE),pieces(BCHE))),
		   m_or(m_and(king_to_ma_attacks_bb(sq,occ), m_or(pieces(RMA),pieces(BMA))),
		   m_or(m_and(Pao_Eat_bb(sq),m_or(pieces(RPAO),pieces(BPAO))),
		   m_or(m_and(shi_attacks(sq), m_or(pieces(RSHI),pieces(BSHI))),
		   m_and(xiang_attacks_bb(sq,occ),m_or(pieces(RXIANG),pieces(BXIANG)))))))));
	// ����Խ�ҲҪ����??
}



Bitboard Position::attacks_from_occ(Piece p, Square s, Bitboard occ){
	
	ASSERT(square_is_ok(s));

	switch (p){
	case RCHE: // ��
	case BCHE:{
				 return Rook_attacks_bb(s, occ); //  Rook_attacks_bb(sq);
	}
	case RMA:  // ��
	case BMA:{
		         return ma_to_king_attacks_bb(s,occ);
	}
	case RPAO: // ��
	case BPAO:
		return Pao_Eat_bb(s,occ);
	case RPAWN: // ��
	case RKING:
		return one_rpawn_rk_attacks(s);
	case BPAWN:
	case BKING:
		return one_bpawn_bk_attacks(s);
	case RSHI:
	case BSHI:
		return shi_attacks(s);
	case RXIANG:
	case BXIANG:{
				return xiang_attacks_bb(s,occ);
	}
	default:
		break;
	}

	return _mm_setzero_si128();
}

/// Position::attacks_from() computes a bitboard of all attacks
/// of a given piece put in a given square.
Bitboard Position::attacks_from(Piece p, Square sq)  {

	ASSERT(square_is_ok(sq));

	switch(p){
	case RCHE: // ��
	case BCHE:
		return Rook_attacks_bb(sq);
	case RMA:  // ��
	case BMA:{
		return ma_to_king_attacks_bb(sq);
			 }
	case RPAO: // ��
	case BPAO:
		return Pao_Eat_bb(sq);
	case RPAWN: // ��
	case RKING:
		return one_rpawn_rk_attacks(sq);
	case BPAWN:
	case BKING:
		return one_bpawn_bk_attacks(sq);
	case RSHI:
	case BSHI:
		return shi_attacks(sq);
	case RXIANG:
	case BXIANG:{
		return xiang_attacks_bb(sq);
				}
	default:
		break;
	}

	return _mm_setzero_si128();
}

/// Position::move_attacks_square() tests whether a move from the current
/// position attacks a given square. 
/// ����߷���û����, Ҫ����֮�����ж�. ����ǲ���׽�Ӳ�? ����жϺü���. 
//bool Position::move_attacks_square(Move m, Square s) {
//
//	ASSERT(is_ok(m));
//	ASSERT(square_is_ok(s));
//
//	Square f = from_sq(m), t = to_sq(m);
//
//	ASSERT(!square_is_empty(f));
//
//	// ֱ�ӿ��ԳԵ�
//	if(bit_is_set(attacks_from(piece_on(f),t),s))
//		return true;
//
//	// Move the piece and scan for X-ray attacks behind it
//	Bitboard occ = occupied_squares();
//	Color us = color_of(b90[f]);
//
//	clear_bit(occ,f);
//	set_bit(occ,t);
//
//	Bitboard xray; 
//
//	Piece delt = COLOR_BY_SIDE_ADD[us];
//
//
//	//1, ��һ�������ǲ��Ǹ����ǵĳ�,������,
//	xray = m_and(Rook_attacks_bb(s,occ),pieces(RCHE + delt));
//	//2, �����ǲ��Ǹ����ǵ�������.
//	xray = m_or(xray,
//		m_and(king_to_ma_attacks_bb(s,occ),pieces(RMA + delt)));
//	//3, �����ǲ��Ǹ����ǵ��ڹ�����. 
//	xray = m_or(xray,
//		m_and(Pao_Eat_bb(s,occ),pieces(RPAO + delt)));
//
//
//	// If we have attacks we need to verify that are caused by our move
//	// and are not already existent ones.
//	// ��������ڹ����Է�,����ҪУ��һ��,�ǲ���ԭ�Ⱦ��ڵĹ���. 
//	// return xray && (xray ^ (xray & attacks_from<QUEEN>(s)));
//	if(m_have_bit(xray)){ // �����г�,����,���� �ڹ��� s 		
//		//1. �õ�ԭ�ȵĳ�,��,�ڹ���ͼ.
//		Bitboard org;	
//
//		org =  m_and(Rook_attacks_bb(s),   pieces(RCHE + delt));
//		org = m_or(org,
//			m_and(king_to_ma_attacks_bb(s,occ), pieces(RMA + delt)));
//		org = m_or(org,
//			m_and(Pao_Eat_bb(s),    pieces(RPAO + delt)));		
//
//		org = m_and(org,xray);
//		xray = m_xor(org,xray); // (xray & attacks_from<QUEEN>(s)));
//
//		if(m_have_bit(xray)){
//			return true;  // ������׽��.
//		}
//	}
//
//	return false;
//}

/////////////////////////////////////////////////////////////////////////
// 

//void Position::find_checkers() { // �ҵ��Է��������ˡ�
//
//	Color Us = side_to_move();
//	const Piece delt = COLOR_BY_SIDE_ADD[Us];
//	Square mk = king_square(Us);
//
//	st->checkersBB = m_or(m_and(pieces(BPAWN - delt), 
//		Us == WHITE? Attack_By_Bpawn_Bking[mk] : Attack_By_Rpawn_Rking[mk]),m_or(
//		m_and(Rook_attacks_bb(mk),pieces(BCHE - delt)),m_or(
//		m_and(Pao_Eat_bb(mk),pieces(BPAO - delt)),
//		m_and(king_to_ma_attacks_bb(mk),pieces(BMA - delt)))));
//}

Bitboard Position::findPaoNullBiboard(Color c, Square ksq) {

	Bitboard result = _mm_setzero_si128();	
	// �ҵ�����֮��Ŀո�.
	Piece delt = COLOR_BY_SIDE_ADD[c];
	if(have_bit(ChePseudoMask_FR[ksq],pieces(RPAO + delt))){
		// �ҵ��ҷ����еĿ���
		for(int i = 0; i < piece_count(RPAO + delt); i++){
			Square pao =  piece_list(RPAO + delt,i);
			Bitboard bet = BetweenBB[pao][ksq];
            if(!have_bit(bet,byWhiteBlack)){
				result = m_or(result,bet);
			}
		}
	}

	return result;
}

