#ifndef END_my_m_MT_R_1che1ma3pawn_B_2pao2ma
#define END_my_m_MT_R_1che1ma3pawn_B_2pao2ma
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1��1��3����2��2��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


void my_m_MT_R_1che1ma3pawn_B_2pao2ma(typePOS &POSITION, EvalInfo &ei){

	if((my_xiang_num + my_shi_num) >= 3){
		MY_EV_ADD(EV_MY_CAN * 32);
	}
}
