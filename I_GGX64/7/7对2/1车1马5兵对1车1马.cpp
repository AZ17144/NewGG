#ifndef END_my_m_MT_R_1che1ma5pawn_B_1che1ma
#define END_my_m_MT_R_1che1ma5pawn_B_1che1ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1��1��5����1��1��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//�ҷ�1��1��5�����Է�1��1��
void my_m_MT_R_1che1ma5pawn_B_1che1ma(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	// ADD 
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheMaPawn_CheMa_ByPawnByShi[your_shi_num]);
}

