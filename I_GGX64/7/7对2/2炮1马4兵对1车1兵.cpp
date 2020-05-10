#ifndef END_my_m_MT_R_2pao_1ma4pawn_B_1che1pawn
#define END_my_m_MT_R_2pao_1ma4pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2��1��4����1��1��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//2��1��4����1��, ����Ҫ�ӷ�

void my_m_MT_R_2pao_1ma4pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

	if(StoY(ypawn) MY_SMALL MY_RANK5 || my_shi_num > 0){
		MY_EV_ADD(Add_2��1���1��1��);
	}

	//
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * Add_2��1���1��1��_byPawn_Shi[your_shi_num]);
	//
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(my_king_pos)]);
	MY_EV_SUB((sint16)count_1s(ymp) * Add_2��1���1��1��_byPawn_Shi[my_shi_num]);
}


