#ifndef END_my_m_MT_R_1che2pao1ma3pawn_B_1che1pao1ma1pawn
#define END_my_m_MT_R_1che2pao1ma3pawn_B_1che1pao1ma1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1��2��1��3����1��1��1��1��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//const int _3pawn1paopawn_PawnShiAdd[3] = {96,48,24};

void my_m_MT_R_1che2pao1ma3pawn_B_1che1pao1ma1pawn(typePOS &POSITION, EvalInfo &ei){


	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square ypao = S90_from_piecelist(POSITION,your_pao,0);

	//my_m_MT_R_1che1pao2ma3pawn_B_1che1pao1ma1pawn
	//�Է��ı�û�й���
	if(!have_bit(MyLowBB[MY_RANK4],bb_your_pawn)){
		MY_EV_ADD(32);
		//�Է�����û�й���


		if(StoY(yma) MY_SMALL_EQL MY_RANK3){
			MY_EV_ADD(32);  // �Է������������
			if(StoY(ypao) MY_LARGE_EQL MY_RANK5){
				MY_EV_ADD(32);
			}
		}

	}

}