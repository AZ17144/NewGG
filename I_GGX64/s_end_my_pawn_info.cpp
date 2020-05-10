#ifndef BUILD_qsearch
#define BUILD_qsearch
#include "chess.h"
#include "s_end_my_pawn_info.cpp"
#include "white.h"
#else
#include "black.h"
#endif


Bitboard My_get_connect_Pawn(typePOS &POSITION){
	//Bitboard blb = _mm_setzero_si128();

	Bitboard byp = bb_my_pawn;
	Bitboard blp_l;
	Bitboard blp_r;
	// ȥ������,

	blp_l = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),byp);	    // ȥ��������ı�		
	m_Rsf(blp_l,1);                    // ���б�����һ��	


	blp_r = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),byp);	    // ȥ��������ı�
	m_Lsf(blp_r,1);                   // ���б�����һ��

	return(m_and(m_or(blp_l,blp_r),byp));
}

// �ҷ��ı��Ѿ����ӵ���Ŀ
int My_pawn_already_over_river(typePOS &POSITION){

	Bitboard myp = m_and(bb_my_pawn,MyUpBB[MY_RANK5]);
	return count_1s(myp);
}


