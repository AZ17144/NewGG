#ifndef END_my_m_MT_R_1che2pao2pawn_B_2che
#define END_my_m_MT_R_1che2pao2pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"
#include "1��2��2����2��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//#define ADD_���ڱ��Զ���_by_Pawn_Safe   32             //���ڱ��Զ���,�ڷ���ȫʱ���ļӷ�



//�췽����2�� �� �ڷ�2��
void my_m_MT_R_1che2pao2pawn_B_2che(typePOS &POSITION, EvalInfo &ei){
	// fen 3ak4/4a4/2C1b4/6R2/2b1r4/P7P/r8/4B4/4A4/2BAK1C2 w - - 0 1
	// ����Է�����ȫ, �ҷ�һ����Ҳû�й���, Ҫ����
	if((your_shi_num + your_xiang_num) == 4){
		Bitboard bmp = m_and(bb_my_pawn,MyLowBB[MY_RANK4]);
		if(count_1s(bmp) == 2){
			MY_EV_SUB(128);
		}
	}

	//Square yk = your_king_pos;
	//your_m_MT_R_2CHE_B_1CHE1PAO(POSITION,ei);

	//if(ei.mul <= 2){
	//	EV_MY_SAFE = TRUE;
	//}

	//// ADD 
	//Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	//if(EV_MY_SAFE){
	//	MY_EV_ADD((sint16)count_1s(bmp) * ADD_���ڱ��Զ���_by_Pawn__Safe_Shi[your_shi_num] * 3/2);
	//}
	//else{
	//	MY_EV_ADD((sint16)count_1s(bmp) * ADD_���ڱ��Զ���_by_Pawn__Safe_Shi[your_shi_num]);
	//}

}
