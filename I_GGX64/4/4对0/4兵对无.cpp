#ifndef END_my_m_MT_R_4pawn
#define END_my_m_MT_R_4pawn
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "4������.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 

//�ҷ�3�����Է� 0 attacker
void my_m_MT_R_4pawn(typePOS &POSITION, EvalInfo &ei){
	BothOnlyPawnEval(POSITION,ei);
}
