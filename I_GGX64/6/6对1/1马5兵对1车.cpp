#ifndef END_my_m_MT_R_1ma5pawn_B_1che
#define END_my_m_MT_R_1ma5pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1��5����1��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//
// void m_MT_B_1CHE_R_1MA(board_t *board);
// void my_m_MT_R_1CHE_B_1MA(board_t *board);
//�ҷ�һ��һ��, �Է�һ��
void my_m_MT_R_1ma5pawn_B_1che(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;

	MY_EV_SUB(128);  // ����Ҫ�ӷ�

	your_m_MT_R_1CHE_B_1MA(POSITION,ei);

	if(ei.mul <= 2){		
		Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
		MY_EV_ADD((sint16)count_1s(bmp) * ADD_MaXPawn_To_CheByShi_WmaSafe[your_shi_num]);
	}
}

//void m_MT_B_1ma5pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
///*
//	//premat_t* pMat = board->pMat;
//	//uint16 Info16 = pMat->sixiangInfo8;
//
//	Square rk     = PieceListStart(board,RKING);
//	Square bk     = PieceListStart(board,BKING);
//	int bma    = PieceListStart(board,BMA);
//	Square bpawn  = PieceListStart(board,BPAWN);
//
//	bool isSafe = FALSE;
//
//	//��һ�ֺ���
//	// fen 4k4/9/4b4/4p4/2n4R1/9/9/9/9/4K4 w  ����: һ������������ page
//	if(board->B_xiang != 0){
//		if(board->b256[0x67] == BPAWN && board->b256[0x57] == BXIANG && StoX(bk) == 0x7){
//			//1, ����������
//			//if(board->b256[0x75] == BMA || board->b256[0x79] == BMA){
//			//	return 1;
//			//}
//			//2, ����ߵ�������
//			if(IsMaCanToOrAt(board,bma,0x75) || IsMaCanToOrAt(board,bma,0x79)){
//				isSafe = TRUE;
//			}
//		}
//	}
//
//	if(m_MT_R_1CHE_B_1MA(board) == 1){
//		isSafe = TRUE;
//	}
//
//	if(board->B_shi == 2 || board->B_xiang == 2){  //���ж���,�����, ����������������������Ǻ���.
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//
//			if(StoY(from) < StoY(rk) && StoX(from) == 0x7){
//
//				if(board->b256[from+1] == BPAWN || board->b256[from-1] == BPAWN){
//
//					isSafe = TRUE;
//
//					break;
//				}
//			}
//		}
//	}
//
//	if(isSafe){    //�������ȫ��
//
//		for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//			if(StoY(from) < StoY(rk)){
//				board->mulScore -= ADD_MaXPawn_To_CheByShi_WmaSafe[board->R_shi];
//			}
//		}
//
//		return 1;
//	}
//
//
//	*/
//}


