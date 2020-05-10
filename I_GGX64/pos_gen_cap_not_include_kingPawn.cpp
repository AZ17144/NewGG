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

#define SERIALIZE_MOVES(from,to)  (*mlist++).move = make_move(from, to);

/// �������������ͽ��ƶ��ĳ��Ӳ�

ExtMove* Position::cattura_not_include_pawn_king(ExtMove* mlist, Color c) {
	
	Piece delt = COLOR_BY_SIDE_ADD[c];
	Bitboard cel = byChessBB[_X_X - delt]; // �Է������ bitboard_occ_black

	Bitboard pawnKingAtt;  //  = _mm_setzero_si128();

	// �������ɳԵ�λ����
	if (c == WHITE){
		pawnKingAtt = OneRpawnOrRking_AttackBB[piece_list(RKING, 0)];

		Bitboard bbMyPawn = pieces(RPAWN);
		//
		Bitboard btmp = bbMyPawn;
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)Rank0BB), btmp);
		m_Rsf(btmp, 9); //���б���ǰһ��
		pawnKingAtt = m_or(pawnKingAtt, btmp);
		Bitboard ghp = m_and(bbMyPawn, _mm_load_si128((__m128i*)RpawnOverBB));// �õ����ӱ�
		if (m_have_bit(ghp)){
			btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB), ghp);  //ȥ��������ı�	
			m_Rsf(btmp, 1);                                         //���к������һ��			
			pawnKingAtt = m_or(pawnKingAtt, btmp);
			btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB), ghp);  //ȥ��������ı�
			m_Lsf(btmp, 1);                                               //���к������һ��	
			pawnKingAtt = m_or(pawnKingAtt, btmp);
		}
	}
	else{
		pawnKingAtt = OneBpawnOrBking_AttackBB[piece_list(BKING, 0)];

		Bitboard bbMyPawn = pieces(BPAWN);
		//
		Bitboard btmp = bbMyPawn;
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)Rank9BB), btmp);
		m_Lsf(btmp, 9); //���б���ǰһ��
		pawnKingAtt = m_or(pawnKingAtt, btmp);
		Bitboard ghp = m_and(bbMyPawn, _mm_load_si128((__m128i*)BpawnOverBB));// �õ����ӱ�
		if (m_have_bit(ghp)){
			btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB), ghp);  //ȥ��������ı�	
			m_Rsf(btmp, 1);                                         //���к������һ��			
			pawnKingAtt = m_or(pawnKingAtt, btmp);
			btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB), ghp);  //ȥ��������ı�
			m_Lsf(btmp, 1);                                               //���к������һ��	
			pawnKingAtt = m_or(pawnKingAtt, btmp);
		}
	}


	//***********************************************************
	// ����������ĳ����߲�
	//***********************************************************
	for(int i = 0; i < piece_count(RXIANG + delt); i++){
		Square from = piece_list(RXIANG + delt,i);	
		Bitboard att = m_and(cel,xiang_attacks_bb(from));
		att = _mm_andnot_si128(pawnKingAtt, att);
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// �������к��˵ĳ����߲�
	//***********************************************************
	for(int i = 0; i < piece_count(RSHI + delt); i++){
		Square from = piece_list(RSHI + delt,i);	
		Bitboard att = m_and(cel,shi_attacks(from));
		att = _mm_andnot_si128(pawnKingAtt, att);
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// ���������ڵĳ����߲�
	//***********************************************************
	for(int i = 0; i < piece_count(RPAO + delt); i++){
		Square from = piece_list(RPAO + delt,i);	
		Bitboard att = m_and(cel,Pao_Eat_bb(from));
		att = _mm_andnot_si128(pawnKingAtt, att);
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// ����������ĳ����߲�
	//***********************************************************
	for(int i = 0; i < piece_count(RMA + delt); i++){
		Square from = piece_list(RMA + delt,i);	
		Bitboard att = m_and(cel,ma_to_king_attacks_bb(from));
		att = _mm_andnot_si128(pawnKingAtt, att);
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}

	//***********************************************************
	// �������г��ĳ����߲�
	//***********************************************************
	for(int i = 0; i < piece_count(RCHE + delt); i++){
		Square from = piece_list(RCHE + delt,i);	
		Bitboard att = m_and(cel,Rook_attacks_bb(from));
		att = _mm_andnot_si128(pawnKingAtt, att);
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	return mlist;
}

