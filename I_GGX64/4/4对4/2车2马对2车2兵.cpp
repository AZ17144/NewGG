#ifndef END_my_m_MT_R_2che2ma_B_2che2pawns
#define END_my_m_MT_R_2che2ma_B_2che2pawns
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "2��2���2��2��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int ADD_2CheXPawn_1Che1Pao1Ma1Pawn_ByPawnShi[3]    = {96, 64, 32};            //2��x����1��1��1��1��, �����ļӷ�
//const int ADD_1Che1Pao1Ma1Pawn_2CheXPawn_ByPawnShi[3]    = {96, 64, 32};            //1��1��1��1����2��x��, �����ļӷ�

void my_m_MT_R_2che2ma_B_2che2pawn(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// fen 3ak4/3Ra4/2R1b4/8p/9/9/1p6r/B3N4/4K4/3N1r3 w - - 0 1
	if(your_shi_num == 2 && MY_SQ04 == yk){
		if(my_shi_num == 0 && my_xiang_num <= 1){
			MY_EV_SUB(32);
			if(!have_bit(bb_my_ma,MyUpBB[MY_RANK6])){
				MY_EV_SUB(EV_YOUR_CAN * 64);
			}
		}
	}
}