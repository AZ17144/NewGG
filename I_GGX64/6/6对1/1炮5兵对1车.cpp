#ifndef END_my_m_MT_R_1pao5pawn_B_1che
#define END_my_m_MT_R_1pao5pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1��5����1��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 



//1��2����1��  //��x����1��_addByPawnSafe

void my_m_MT_R_1pao5pawn_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	if(my_xiang_num == 2 || my_shi_num == 2){
		EV_MY_SAFE = TRUE;
	}
	if(EV_MY_SAFE){
		Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_PaoxPawn��1Che_addByPawnSafeByShi[your_shi_num]);
	}
	
}

//void m_MT_B_1pao5pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
///*
//
//	//bool adfaf; = FALSE;
//
//	int  rk = PieceListStart(board,RKING);
//
//
//	if(board->B_xiang == 2 && board->B_shi == 2){   //���ж������, ������ȫ��
//		board->bsafe = TRUE;
//	}
//
//	if(board->B_shi == 2 || board->B_xiang == 2){  //���ж���,�����, ����������������������Ǻ���.
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//
//			if(StoY(from) < StoY(rk) && StoX(from) == 0x7){
//
//				if(board->b256[from+1] == BPAWN || board->b256[from-1] == BPAWN){
//
//					board->bsafe = TRUE;
//
//					break;
//				}
//			}
//		}
//	}
//
//	//if(TRUE == adfaf;){
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//
//			if(StoY(from) <= StoY(rk)){
//
//				board->mulScore -= ADD_PaoxPawn��1Che_addByPawnSafeByShi[board->R_shi];
//			}
//		}
//
// //       return 1;
//	//}
//
//	*/
//}