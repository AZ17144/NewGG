#ifndef END_my_m_MT_R_1che5pawn_B_2che
#define END_my_m_MT_R_1che5pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1��5����2��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//�췽1������ �ڷ� 2��

void my_m_MT_R_1che5pawn_B_2che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ����췽������ȫ,����ȫ, ��췽Ҫ�ӷ�

	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * Add_��x��_2��_by_Pawn_Safe_Shi[your_shi_num]);

	if((my_shi_num + my_xiang_num) == 4 && PB90(MY_SQ55) == my_king){
	    RETRUN_MUL(4);
	}
	
}

//
//void m_MT_B_1che5pawn_R_2che(typePOS &POSITION, EvalInfo &ei){
///*	
//	//if(board->b256[0xb7] != BPAWN){
//	//	return m_MT_B_1che2pawn_R_2che(board);
//	//}
//
//	//����췽������ȫ,����ȫ, ��췽Ҫ�ӷ�
//
//	for(Square bpawn = PieceListStart(board,BPAWN); bpawn > 0x32; bpawn = NextPiece(board,bpawn)){
//		if(StoY(bpawn) < 0xc){
//			board->mulScore -= Add_��x��_2��_by_Pawn_Safe_Shi[board->R_shi];
//		}
//	}
//
//	if(board->B_shi == 2 && board->B_xiang == 2){
//		if(board->b256[0x57] == BXIANG){
//			return 4;
//		}
//	}
//
//	*/
//}