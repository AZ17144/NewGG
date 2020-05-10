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

#ifndef NDEBUG
bool Position::pl_move_is_legala(Move m) {

	ASSERT(is_ok(m));

	Square from = from_sq(m);
	Square to   = to_sq(m);
	Color Us = color_of(piece_on(from));  // side_to_move();
	const Piece delt = COLOR_BY_SIDE_ADD[Us];
	//ASSERT(color_of(piece_on(from)) == us);

	Bitboard occ = byWhiteBlack;
	clear_bit(occ,from);
	set_bit(occ,to);

	Square mk = king_square(Us);
	if(mk == from){
		mk = to;
	}

	Bitboard KFR = ChePseudoMask_FR[mk];
	//////////////////////////////////////////////////////////////////////////
	if(have_bit(KFR,m_or(pieces(BKING - delt),pieces(BCHE - delt)))){
		// 2.1.1. �ǲ��Ǹ��Է��� ��,�� ����, ** �����������˶Է�����.ͬʱȥ�˶Է�������
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],
			m_or(pieces(BKING - delt),pieces(BCHE - delt))),
			Rook_attacks_bb(mk,occ)))) {    // ���Ҫ���룬��Ϊ��Ҫ���˺�
				return false; 
		}
	}
	//////////////////////////////////////////////////////////////////////////
	if(have_bit(KFR,pieces(BPAO - delt))){
		// 2.1.2. �ǲ��ǻ����Է����ڽ���
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],pieces(BPAO - delt)),
			Pao_Eat_bb(mk,occ)))){
				return false;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	if(have_bit(Ma_Pseudo_Att[mk],pieces(BMA - delt))){
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],pieces(BMA - delt)),
			king_to_ma_attacks_bb(mk,occ)))){
				return false;
		}
	}
	// 2.1.4 �ǲ��ǻ����Է��ı�����
	if(have_bit(Us == WHITE? attacks_by_bpawn_bk(mk): attacks_by_rpawn_rk(mk),pieces(BPAWN - delt))){
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],pieces(BPAWN - delt)),
			Us == WHITE? attacks_by_bpawn_bk(mk): attacks_by_rpawn_rk(mk)))){
				return false;
		}
	}	

	return true;	
}
#endif

bool Position::legal(Move m) {

	// ASSERT(color_of(piece_on(from_sq(m))) == sideToMove);

	if(in_check()){

		Square from = from_sq(m);
		Color Us = color_of(piece_on(from));  // side_to_move();
		if (Us != sideToMove){
			return false;
		}

#ifndef NDEBUG
		ASSERT(pl_move_is_legala(m));
#endif

		return true;
	}

	ASSERT(is_ok(m));

	Square from = from_sq(m);
	Square to   = to_sq(m);
	Color Us = color_of(piece_on(from));  // side_to_move();
	const Piece delt = COLOR_BY_SIDE_ADD[Us];
	//ASSERT(color_of(piece_on(from)) == us);

	Bitboard occ = byWhiteBlack;
	clear_bit(occ,from);
	set_bit(occ,to);

	Square mk = king_square(Us);
	if(mk == from){
		mk = to;
	}

	Bitboard KFR = ChePseudoMask_FR[mk];
    //////////////////////////////////////////////////////////////////////////
	if(have_bit(KFR,m_or(pieces(BKING - delt),pieces(BCHE - delt)))){
		// 2.1.1. �ǲ��Ǹ��Է��� ��,�� ����, ** �����������˶Է�����.ͬʱȥ�˶Է�������
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],
			m_or(pieces(BKING - delt),pieces(BCHE - delt))),
			Rook_attacks_bb(mk,occ)))) {    // ���Ҫ���룬��Ϊ��Ҫ���˺�
				return false; 
		}
	}
	//////////////////////////////////////////////////////////////////////////
	if(have_bit(KFR,pieces(BPAO - delt))){
		// 2.1.2. �ǲ��ǻ����Է����ڽ���
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],pieces(BPAO - delt)),
			Pao_Eat_bb(mk,occ)))){
				return false;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	if(have_bit(Ma_Pseudo_Att[mk],pieces(BMA - delt))){
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],pieces(BMA - delt)),
			king_to_ma_attacks_bb(mk,occ)))){
				return false;
		}
	}
	// 2.1.4 �ǲ��ǻ����Է��ı�����
	if(have_bit(Us == WHITE? attacks_by_bpawn_bk(mk): attacks_by_rpawn_rk(mk),pieces(BPAWN - delt))){
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],pieces(BPAWN - delt)),
			Us == WHITE? attacks_by_bpawn_bk(mk): attacks_by_rpawn_rk(mk)))){
				return false;
		}
	}	

	return true;	
}


bool Position::pseudo_legal(Move move) {

	Square from  = from_sq(move);
	Square to    = to_sq(move);
	Piece piece  = b90[from];
	Piece cap    = b90[to];

	Color us = side_to_move();

	// If the from square is not occupied by a piece belonging to the side to
	// move, the move is obviously not legal.
	if (color_of(piece) != us)
		return false;

	if (color_of(cap) == us)
		return false;

	switch(piece){
	case RMA:
	case BMA:{
		//�õ���������߲�			
		return (bit_is_set(king_to_ma_attacks_bb(to),from));
			 }
			 break;
	case RXIANG:
	case BXIANG:{
		 return (bit_is_set(xiang_attacks_bb(to),from));
				}
				break;
	case BSHI:
	case RSHI:			{
		return (bit_is_set(shi_attacks(to),from));
						}
						break;
	case RCHE:
	case BCHE:{ //�����������
		return (bit_is_set(Rook_attacks_bb(to),from));
			  }
			  break;
	case RPAO:
	case BPAO:{//������
		if(cap == EMPTY){
			return (bit_is_set(Rook_attacks_bb(to),from));
		}
		else{
			return (bit_is_set(Pao_Eat_bb(to),from));
		}
			  }
			  break;
	case RPAWN:
	case RKING:	{
		return (bit_is_set(attacks_by_rpawn_rk(to),from));
			   }
			   break;
	case BPAWN:
	case BKING: {
		return (bit_is_set(attacks_by_bpawn_bk(to),from));
			   }
			   break;
	default:
		return false;
	}

	//return false;
}

static const  bool AlwaysZhouJiang[16] = {
	false,  // ���������
	false,  true, true, true, false, false, false,
	false,
	false,  true, true, true, false, false, false,		

};



bool Position::gives_check(Move m, CheckInfo& ci) {

	//ASSERT(pos_is_ok());
	ASSERT(is_ok(m));
	ASSERT(m128_is_same(ci.dcCandidates, discovered_check_candidates(side_to_move())));
	ASSERT(color_of(b90[from_sq(m)]) == side_to_move());


	Square from = from_sq(m);
	Square to   = to_sq(m);
	Piece  pc   = piece_on(from);
	Square yk   = ci.ksq;
	

	// Direct check ? ֱ�ӽ�.
	if (ChessCanDirectCheck[pc]){
		if (bit_is_set(ci.checkSq[pc], to)){ // ��,��������ڽ���.
			// fen 2bak2r1/4a4/4b1n2/p3pNR1p/2p6/5NP2/P3P3P/4B3C/3cK2c1/2r2A1R1 b - - 0 1
			if (type_of(pc) == PAO && bit_is_set(ChePseudoMask_FR[yk], from)){  // ��Ҳ�ڽ�������
				Bitboard occ = occupied_squares();
				clear_bit(occ, from);
				set_bit(occ, to);
				Bitboard paoeat = Pao_Eat_bb(yk, occ);
				Bitboard pao = pieces(pc);
				clear_bit(pao, from);
				set_bit(pao, to);
				if (have_bit(paoeat, pao)){
					return true;
				}
			}
			else{
				return true;
			}
		}
	}

	// Discovery check ? �齫, �й��������ڳ齫,���鳵,��齫������ʽ.
	//if (m_have_bit(ci.dcCandidates) && bit_is_set(ci.dcCandidates, from)){
	if (bit_is_set(ci.dcCandidates, from))	{		
		if(bit_is_set(ChePseudoMask_FR[yk],from)){
			// 1, ���ĳ齫.
			// 2, �ڵĳ齫.
			// ���������,һֱ����. ����һ���ǳ��м�����ӽ�. �� a b ��, a���Գ�b������. 
			// �������,��,��,��һ���ǽ�������
			if(AlwaysZhouJiang[piece_on(from)]){
				return true;
			}
			// ���ж�һ��, �ø��ӵķ���. 
			if(direction_between_squares(from, yk) != direction_between_squares(to, yk)){
					return true;
			}
			// �ٿ�һ���ǲ�����,��,���ȳ��ӽ�. 
			if(piece_on(to) != EMPTY){
				return true;
			}
		}
		else{  // 3, ��ĳ齫.			 
			return true;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	// �ߵ������м�Ľ�
	if(bit_is_set(ci.PaoNull,to)){ // ��Ҫ�������,��������ڲ�����.
		if(type_of(pc) == PAO && bit_is_set(ChePseudoMask_FR[yk],from)){			
			return false; // ����������ٽ���. 			
		}
		return true;
	}

	//��Ҫ�ڳ�������������.
	// fen r1bakab1r/9/7c1/p1p1C1p1p/4n4/4n4/P1P3P1P/9/9/RNBAKABNR w - - 0 1
	// e6e2 ���ڳ��ӽ�?? ��ʱ��Ҳ������. 
	// fen rnbakabr1/9/4c2c1/p1p1C1p1p/9/9/P1P1P1P1P/9/9/RNBAKABNR b - - 0 1 // ������ǽ�
	if(type_of(pc) == PAO && b90[to] != EMPTY 
		&& bit_is_set(ChePseudoMask_FR[yk],from)
		&& bit_is_set(ChePseudoMask_FR[yk],to)){

		Color Us = color_of(piece_on(from));  // side_to_move();
		const Piece delt = COLOR_BY_SIDE_ADD[Us];
        // ��һ���ǲ��������ڽ���.
		Bitboard occ = occupied_squares();
		clear_bit(occ,from);
		set_bit(occ,to);
		//Bitboard paoeat = pao_eat_attacks_bb(ci.ksq,occ);
		Bitboard paoeat = Pao_Eat_bb(yk,occ);
		Bitboard pao = pieces(RPAO + delt);

		clear_bit(pao,from);
		set_bit(pao,to);

		if(have_bit(paoeat,pao)){
			return true;
		}
	}

	return false;
}


bool Position::test_Is_True_Cap(Square from, Square to, Color which){
	
	PieceType to_id;
	//Bitboard bb;
	Color oldside;
	Piece undo_capture;
	bool isP;

	to_id = type_of(b90[to]);

	//---------------------------------------------------------------------------
	//1, �Ǳ����ڳ�, �ͷ��� FALSE ,���������, ��Ϊǰ�����ȥ����
	//---------------------------------------------------------------------------


	//---------------------------------------------------------------------------
	//2, �ж�������ܲ�����, ���������,Ҳ�Ͳ�����ȥ�ԶԷ���
	//---------------------------------------------------------------------------
	//if(Is_Can_Move_To_Eat(board,from,to) == FALSE){  //׽�����Ӳ��ܶ�.
	//	return;
	//}

	//�����Ҳ����,��Ϊ����ǰ�������.

	//---------------------------------------------------------------------------
	//3, ���ж�һ�����׽����ļ�ֵ�ǲ��Ǳȱ�׽����ļ�ֵС
	//---------------------------------------------------------------------------
	if(PieceValueMidgame[b90[from]] >= PieceValueMidgame[b90[to]]){
		//---------------------------------------------------------------------------
		//4, ���˫����������ͬ,��Ҫ�ж� 1, ��������ܲ�����, 2, ������ܲ��ܷ��ԶԷ�(��)
		//---------------------------------------------------------------------------
		if(type_of(b90[from]) == to_id){
			//�ж��ǲ�����׽
			//if(Is_Can_Move_To_Eat(board,to,from) == TRUE){
			if(legal(MOVE_FromTo(to,from)) == true){
				if(to_id != MA) return false;
				// fen 3ak4/4a4/2ncb4/4N4/2p1P1b2/6B2/2P6/1N7/9/3AKAB2 b - - 157 157 �������
				// fen 3ak4/4a4/2ncb4/4N4/2p3b2/6B2/2P6/1N7/9/3AKAB2 b ����ǳ�׽
				//�ٿ�һ��������ܲ��ܷ��Ե��Լ�.
				//king_to_ma_attacks(bb,board,sq);
				//BB_and_BB(bb,board->byChessBB[BMA]);
				//BB_or_BB(att,bb);	
				Bitboard bb = king_to_ma_attacks_bb(from,byWhiteBlack);
				if(bit_is_set(bb,to)){         //board_display(board,"cap too");
					return false;
				}
			}
		}
		//---------------------------------------------------------------------------
		//5, �ٿ�һ���������û�����������ӱ�����
		//---------------------------------------------------------------------------

		oldside = sideToMove;
		sideToMove = color_of(b90[from]);
		move_do_test(MOVE_FromTo(from,to),&undo_capture);

		//b, �ٿ�һ����û�����������ӱ�����
		isP = isPretecte_TrueCap(which,to);	
		move_undo_test(MOVE_FromTo(from,to),undo_capture);	
		sideToMove = oldside;

		if(isP == true) return false;
	}

	return true;
}

