#ifndef END_my_m_MT_R_1MA_B_1PAWN
#define END_my_m_MT_R_1MA_B_1PAWN
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "1���1��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 
//�ܲ��ܺͣ�����ʤ


// <<���嚈������>>
// ��1ҳ ��2�� �ױ�����һ��

//�췽һ����, �ڷ�һ����
void my_m_MT_R_1MA_B_1PAWN(typePOS &POSITION, EvalInfo &ei){

   Square ypawn = S90_from_piecelist(POSITION,your_pawn,0);

   if(abs(StoX(ypawn) - 0x4) >= 3){
	   MY_EV_SUB(196);
   }

   if(StoY(ypawn) MY_LARGE MY_RANK4){
	   if(abs(StoX(ypawn) - 0x4) > 1){
		   MY_EV_SUB(64);
	   }

	   // ����Է��ı����ܱ�������Ҳ���Ǻ�
	   if(StoY(ypawn) == MY_RANK9){
		   if(your_shi_num <= 1 && your_xiang_num == 0
			   && my_xiang_num >= 1){
			   if(abs(StoX(ypawn) - 0x4) <= 1){
				   RETRUN_MUL(8);
			   }
		   }
	   }
	   RETRUN_MUL(1);
   }
   if((your_shi_num + your_xiang_num) >= 2){
	   RETRUN_MUL(1);
   }

   if(your_xiang_num >= 1){
	   RETRUN_MUL(1);
   }



   // �������ʤ��
   if(your_shi_num <= 1){
	   if(StoY(ypawn) == MY_RANK9){
		   if((StoX(ypawn) -0x4) <= 1){
			   if(my_xiang_num != 0){
				   RETRUN_MUL(8);
			   }
		   }
	   }
   }

   RETRUN_MUL(2);
}

