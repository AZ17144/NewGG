#ifndef END_my_m_MT_R_1che5pawn_B_1pao1pawn
#define END_my_m_MT_R_1che5pawn_B_1pao1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1��5����1��1��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


// fen 9/3P5/4k4/9/2b3b2/6B2/9/3AB4/r3Ap3/C3K4 w - - 44 44

//const int ADD_PaoXPawn_To_ChePawnByShi_WpaoSafe[3]  =  { 80, 48, 16};  //�ڱ��Գ���,�ڷ���ȫ��,�б��ļӷ� 

//�������ڱ�
void my_m_MT_R_1che5pawn_B_1pao1pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_CheXPawn_To_PaoPawn_PawnByShi[your_shi_num]);

	MY_EV_ADD(ADD_CheXPawn_To_PaoPawn);
}

