#ifndef END_my_m_MT_R_2pao_1ma5pawn_B_1che1pawn
#define END_my_m_MT_R_2pao_1ma5pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2��1��5����1��1��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//2��1��5����1��, ����Ҫ�ӷ�

void my_m_MT_R_2pao_1ma5pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	if(StoY(ypawn) MY_SMALL MY_RANK5 || my_shi_num > 0){
		MY_EV_ADD(Add_2��1���1��1��);
	}

	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * Add_2��1���1��1��_byPawn_Shi[your_shi_num]);
}


//void m_MT_B_2pao_1ma5pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rpawn = PieceListStart(board,RPAWN);
//
//	if(rpawn > 0x80 || board->B_shi > 0){
//		board->mulScore -= Add_2��1���1��1��;
//	}
//
//	//����������ļӷ�
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -=  Add_2��1���1��1��_byPawn_Shi[board->R_shi];
//		}
//	}
//
//	*/
//}