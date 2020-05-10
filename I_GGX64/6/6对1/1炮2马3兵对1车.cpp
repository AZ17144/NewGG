#ifndef END_my_m_MT_R_1pao_2ma3pawn_B_1che
#define END_my_m_MT_R_1pao_2ma3pawn_B_1che
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1��2��3����1��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//2��1���1��, ����Ҫ�ӷ�

void my_m_MT_R_1pao_2ma3pawn_B_1che(typePOS &POSITION, EvalInfo &ei){

	Square yk = your_king_pos;
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * Add_1��2���1��_byPawn_Shi[your_shi_num]);

	MY_EV_ADD(Add_2��1���1��);
}


//void m_MT_B_1pao_2ma3pawn_R_1che(typePOS &POSITION, EvalInfo &ei){
///*
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < 0xc){
//			board->mulScore -=  Add_1��2���1��_byPawn_Shi[board->R_shi];
//		}
//	}
//
//	board->mulScore -= Add_2��1���1��;
//
//	*/
//}