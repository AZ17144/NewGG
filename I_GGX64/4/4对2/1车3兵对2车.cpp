#ifndef END_my_m_MAR_R_1che3pawn_B_2che_a
#define END_my_m_MAR_R_1che3pawn_B_2che_a
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1��3����2��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//�췽1������ �ڷ� 2��

void my_m_MT_R_1che3pawn_B_2che(typePOS &POSITION, EvalInfo &ei){


	Square yk = your_king_pos;
	Square mk = my_king_pos;
	Square mche = S90_from_piecelist(POSITION,my_che,0); 

	//����췽������ȫ,����ȫ, ��췽Ҫ�ӷ�
	// ADD
	Bitboard bmp = m_and(bb_my_pawn,MyLowBB[StoY(yk)]);
	MY_EV_ADD((sint16)count_1s(bmp) * Add_��x��_2��_by_Pawn_Safe_Shi[your_shi_num]);

	// fen 2ba1k3/4a4/4b4/4PPP2/9/9/4r4/9/4A4/1r1RKA3 b - - 0 1
    if(my_shi_num == 2 && MY_SQ55 == mk && PB90(MY_SQ4C) == my_shi){
		Bitboard lp = My_get_connect_Pawn(POSITION);
		if(bit_is_set(lp,MY_SQ1F) || bit_is_set(lp,MY_SQ28)){
			if(PB90(MY_SQ54) == my_shi){
				if(StoX(mche) >= 0x5){
					if(StoX(mche) == 0x5){
						RETRUN_MUL(2);
					}
					if(StoY(mche) == MY_RANK9){
						RETRUN_MUL(2);
					}
				}
			}
			if(PB90(MY_SQ56) == my_shi){
				if(StoX(mche) <= 0x3){
					if(StoX(mche) == 0x3){
						RETRUN_MUL(2);
					}
					if(StoY(mche) == MY_RANK9){
						RETRUN_MUL(2);
					}
				}
			}
		}
	}

	//1, �췽������ȫ, ��췽�ǰ�ȫ��
	if((my_shi_num + my_xiang_num) == 4 && PB90(MY_SQ55) == my_king){
		if(PB90(MY_SQ43) == my_xiang){	
			RETRUN_MUL(4);
		}
		// fen 4kab2/4a4/4b4/3R1P3/P8/4r4/8P/Br7/4A4/2B1KA3 b - - 0 1
		if(StoX(mche) == 0x3 && PB90(MY_SQ56) == my_shi){
			if(PB90(MY_SQ53) == my_xiang && PB90(MY_SQ3F) == my_xiang){
				RETRUN_MUL(6);
			}
		}
		if(StoX(mche) == 0x5 && PB90(MY_SQ54) == my_shi){
			if(PB90(MY_SQ57) == my_xiang && PB90(MY_SQ47) == my_xiang){
				RETRUN_MUL(6);
			}
		}

		RETRUN_MUL(8);
	}

	//
}

