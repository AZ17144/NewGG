#ifndef END_my_m_MT_R_2pao2pawn_B_1che2pawn
#define END_my_m_MT_R_2pao2pawn_B_1che2pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
#include "..\\..\\bitboard.h"
#include "..\\..\\endgame\mat.h"
#include "2��2����1��2��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int ADD_Che2Pawn_To_2PaoXPawn_ByPawn[3]       =  { 96, 64, 32};  //��2��,��2��X��
//const int ADD_2PaoXPawn_To_Che2Pawn_ByPawn[3]       =  { 96, 64, 32};  //��2��,��2��X��

void my_m_MT_R_2pao2pawn_B_1che2pawn(tipo_posizione *POSIZIONE, EvalInfo *ei){
/*
    int bk    = PieceListStart(board,BKING);
	int rk    = PieceListStart(board,RKING);


	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
		if(StoY(from) > StoY(bk)){
			board->mulScore += ADD_2PaoXPawn_To_Che2Pawn_ByPawn[board->B_shi];
		}
	}

	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
		if(StoY(from) < StoY(rk)){
			board->mulScore -= ADD_Che2Pawn_To_2PaoXPawn_ByPawn[board->R_shi];
		}
	}


	return 16;/*/
}

//void m_MT_B_2pao2pawn_R_1che2pawn(tipo_posizione *POSIZIONE, EvalInfo *ei){
///*
//    int rk    = PieceListStart(board,RKING);
//	int bk    = PieceListStart(board,BKING);
//
//	for(int from = PieceListStart(board,BPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) < StoY(rk)){
//			board->mulScore -= ADD_2PaoXPawn_To_Che2Pawn_ByPawn[board->R_shi];
//		}
//	}
//
//	for(int from = PieceListStart(board,RPAWN); from > 0x32; from = NextPiece(board,from)){
//		if(StoY(from) > StoY(bk)){
//			board->mulScore += ADD_Che2Pawn_To_2PaoXPawn_ByPawn[board->B_shi];
//		}
//	}
//
//	return 16;/*/
//}




//m_MT_R_1che3pawn_B_3pawn