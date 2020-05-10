#ifndef END_my_m_MT_R_1PAO2PAWN_B_1MA
#define END_my_m_MT_R_1PAO2PAWN_B_1MA
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1��1��5����1��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//���о����������

void my_m_MT_R_1pao1ma_5pawn_B_1ma(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * ADD_1Pao1MaXPawn_1Ma[your_shi_num]);

	Square mma = S90_from_piecelist(POSITION,my_ma,0);

	if(StoY(mma) MY_SMALL MY_RANK5){
		MY_EV_ADD(MaPaoXPawn_Vs_Ma_PaoMao_Over_River);
	}

	MY_EV_ADD(MaPaoXPawn_Ma);
}

