#ifndef END_my_m_MT_R_1che2pawn_B_2che
#define END_my_m_MT_R_1che2pawn_B_2che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1��2����2��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//�췽һ���������Ժڷ�����
void my_m_MT_R_1che2pawn_B_2che(typePOS &POSITION, EvalInfo &ei){
	Square yk = your_king_pos;
	//����췽������ȫ,����ȫ, ��췽Ҫ�ӷ�
	Square mche = S90_from_piecelist(POSITION,my_che,0);
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	int pmok = (int)count_1s(bmp);
	MY_EV_ADD(pmok * Add_��x��_2��_by_Pawn_Safe_Shi[your_shi_num]);

	//1, �췽������ȫ, ��췽�ǰ�ȫ��
	if((my_shi_num + my_xiang_num) == 4 && (PB90(MY_SQ43) == my_xiang || StoY(mche) == MY_RANK7)){
		if(PB90(MY_SQ55) == my_king){
			RETRUN_MUL(3);
		}
		RETRUN_MUL(8);
	}
	
}


//�ڷ�һ���������Ժ췽����
//void m_MT_B_1che2pawn_R_2che(typePOS &POSITION, EvalInfo &ei){
///*
//	//if(board->b256[0xb7] != BPAWN){
//	//	return m_MT_R_2CHE_B_1CHE1PAWN(board);
//	//}
//
//	Square bk = PieceListStart(board,BKING);
//
//	//����췽������ȫ,����ȫ, ��췽Ҫ�ӷ�
//
//	for(Square bpawn = PieceListStart(board,BPAWN); bpawn > 0x32; bpawn = NextPiece(board,bpawn)){
//		if(StoY(bpawn) < 0xc){
//			board->mulScore -= Add_��x��_2��_by_Pawn_Safe_Shi[board->R_shi];
//		}
//	}
//
//	if(board->B_shi == 2 && board->B_xiang == 2 && StoY(bk) == 0x3){
//		if(board->b256[0x57] == BXIANG){
//			return 1;
//		}
//	}
//
//	*/
//}