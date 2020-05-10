#ifndef END_my_m_MT_R_2pao_1ma1pawn_B_1che1pawn
#define END_my_m_MT_R_2pao_1ma1pawn_B_1che1pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "2��1��1����1��1��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//2��1��1����1��, ����Ҫ�ӷ�

void my_m_MT_R_2pao_1ma1pawn_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){

	Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);
	Square mpawn = S90_from_piecelist(POSITION, my_pawn, 0);

	if(StoY(ypawn) MY_SMALL_EQL MY_RANK4 || my_shi_num >= 1){
		MY_EV_ADD(Add_2��1���1��1��);
	}

	// SUB
	Square mk = my_king_pos;
	Bitboard ymp = m_and(bb_your_pawn,MyUpBB[StoY(mk)]);
	int pyok = (int)count_1s(ymp);
	MY_EV_SUB(pyok * Add_2��1���1��1��_byPawn_Shi[my_shi_num]);

	//  fen 2b6/1CN1ak3/4ba3/9/9/5p3/P7r/9/4A2C1/3AK4 w - - 0 1
	if ((my_shi_num + my_xiang_num) <= 2) {
		if (StoY(ypawn) MY_LARGE_EQL MY_RANK4) {
			MY_EV_SUB(64);
			if (StoY(mpawn) MY_LARGE_EQL MY_RANK4) {
				MY_EV_SUB(32);
			}
			if (abs(StoX(mpawn) - 0x4) == 4) {
				MY_EV_SUB(32);
			}
		}
	}
}

//
//void m_MT_B_2pao_1ma1pawn_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
///*
//	Square rpawn = PieceListStart(board,RPAWN);
//
//	if(rpawn > 0x80 && board->B_shi > 0){
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


////2��1���1��, ����Ҫ�ӷ�
//
//void my_m_MT_R_2pao_1ma_B_1che1pawn(typePOS &POSITION, EvalInfo &ei){
//
//
//	//���û�й���,�������ڷ�����
//	Square bpawn = PieceListStart(board,BPAWN);
//
//	if(bpawn < 0x80 || board->R_shi > 0){
//		board->mulScore += Add_2��1���1��1��;
//	}
//
//	return 16;
//}
//
//
//void m_MT_B_2pao_1ma_R_1che1pawn(typePOS &POSITION, EvalInfo &ei){
//
//	Square rpawn = PieceListStart(board,RPAWN);
//
//	if(rpawn > 0x80 || board->B_shi > 0){
//		board->mulScore -= Add_2��1���1��1��;
//	}
//
//	return 16;
//}
