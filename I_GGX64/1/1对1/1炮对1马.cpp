
#ifndef END_my_m_MT_R_1PAO_B_1MA
#define END_my_m_MT_R_1PAO_B_1MA
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "1�ڶ�1��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 
//�췽һ����, �ڷ�һ���� //һ�����˫ʿ 
void my_m_MT_R_1PAO_B_1MA(typePOS &POSITION, EvalInfo &ei){

	if(my_shi_num == 0){
		RETRUN_MUL(1);
	}

	//�������ʲ���࣬��
	if(your_shi_num > 0 || your_xiang_num > 0){
		RETRUN_MUL(2);
	}

	//<<����о�����>>����16��  һ������������ȫ
	//���ڷ��ܲ���ʤ
	//if((Info16 & (CK_R_1x + CK_R_2x)) == 0){		//�ڷ�û����
	Square yma  = S90_from_piecelist(POSITION,your_ma,0);
	Square mpao = S90_from_piecelist(POSITION,my_pao,0);
	if(StoY(yma) MY_LARGE MY_RANK4){
		if(King_4_Side(yma) == King_4_Side(mpao)){
			RETRUN_MUL(2);
		}
	}
	//if(bma > 0x80){
	//	if(King_4_Side(bma) == King_4_Side(rpao)){
	//		return 2;
	//	}
	//}
	RETRUN_MUL(4);
 
}
