#ifndef END_my_m_MT_R_1PAO1PAWN_B_1MA
#define END_my_m_MT_R_1PAO1PAWN_B_1MA
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"
 
#include "..\\..\\endgame\mat.h"
#include "1��1����1��.cpp"
#include "..\\..\\white.h"
#else
#include "..\\..\\black.h"
#endif 


//const int Panw_Add = 32;

//�ҷ�һ��һ��, �Է�һ��
void my_m_MT_R_1PAO1PAWN_B_1MA(typePOS &POSITION, EvalInfo &ei){

	//return;
	Square yk = your_king_pos;
	//��һ�¶Է�����ȫ���ҷ�ֻ���ڱ�ʱ�ĵ÷�,Ҫ�������ڷ���һЩ����Ϊ�Է�û�л���
	MY_EV_ADD(ADD_1PaoXPawn_1Ma_ByPawn[your_shi_num]);

	Square mpawn = S90_from_piecelist(POSITION,my_pawn,0);
	Square mpao  = S90_from_piecelist(POSITION,my_pao,0);

	if(StoY(mpawn) MY_SMALL StoY(yk)){
		MY_EV_SUB(168);
	}

	//����Է������ڽ�������,����
	// fen 4kab2/3Pn4/9/9/6b2/9/9/9/4K4/4CA3 w - - 0 0
	if(PB90(MY_SQ04) == your_king && PB90(MY_SQ0D) == your_ma){
		RETRUN_MUL(16);
	}

	//�ڷ�û���˾ͺ���
	if(my_shi_num == 0){
		if(StoY(yk) MY_LARGE StoY(mpawn)){
			RETRUN_MUL(1);
		}
		if((your_shi_num + your_xiang_num) >= 1){
			RETRUN_MUL(1);
		}
		// fen 5kb2/9/9/9/5N3/9/9/9/6pc1/4K4 b - - 120 120 
		if(StoY(mpawn) MY_SMALL MY_RANK2){
			RETRUN_MUL(1);
		}
	}

	//�Է�������ȫ
	if(your_shi_num >= 1 && your_xiang_num == 2){
		RETRUN_MUL(1);
	}

	// fen 4c4/3ka4/9/9/9/2N6/9/4K3B/3p5/9 w - - 169 169
	if(StoY(mpawn) MY_SMALL StoY(yk)){
		if(my_shi_num <= 1){
			if(your_xiang_num >= 1){
				RETRUN_MUL(1);
			}
		}
	}
	Square yma = S90_from_piecelist(POSITION,your_ma,0);
	//������ܿ��ƺڽ�,Ҳ�Ǻ���
	// fen 5kb2/3P5/3a5/9/2n6/9/9/9/3KA4/5C3 b - - 126 126 
	if(StoY(mpawn) MY_SMALL_EQL MY_RANK1 && your_xiang_num >= 1){
		if(FALSE){
		}
		else if (PB90(MY_SQ15) == your_shi && StoX(mpawn) < 0x4){
			Bitboard bbma = POSITION.ma_to_king_attacks_bb(yma);
			if(bit_is_set(bbma,Square(MY_SQ15))){
				RETRUN_MUL(1);
			}
		}
		else if (PB90(MY_SQ17) == your_shi && StoX(mpawn) > 0x4){
			Bitboard bbma = POSITION.ma_to_king_attacks_bb(yma);
			if(bit_is_set(bbma,Square(MY_SQ17))){
				RETRUN_MUL(1);
			}
		}
	}

	//����ڷ��ǵ�ȱ��,Ҳ�Ǻ���
	if((your_shi_num + your_xiang_num) >= 3){
		RETRUN_MUL(1);
	}
	if((your_shi_num + your_xiang_num) >= 2){
		RETRUN_MUL(2);
	}

	// fen 5k3/4P4/b8/9/9/9/6n2/3A5/3KA4/3C5 w - - 121 121
	//���뽫������ֻ���һ��
	if(my_xiang_num == 0 && your_shi_num != 0){
		if(StoY(mpawn) MY_SMALL_EQL MY_RANK5 && abs(StoY(mpawn) - StoY(yk)) <= 1){
			if(StoX(your_king_pos) == 0x5){
				if(PB90(MY_SQ3C) == your_ma || PB90(MY_SQ4F) == your_ma){
					RETRUN_MUL(2);
				}
			}
			if(StoX(your_king_pos) == 0x3){
				if(PB90(MY_SQ38) == your_ma || PB90(MY_SQ49) == your_ma){
					RETRUN_MUL(2);
				}
			}
		}
	}

	// fen 3k5/4n4/9/9/4C1P2/9/9/9/9/4K4 w - - 0 0
	if(my_shi_num == 0 && my_xiang_num == 0){
		if(StoX(your_king_pos) <= 0x4 && StoX(mpawn) >= 0x4){
			RETRUN_MUL(2);
		}
		if(StoX(your_king_pos) >= 0x4 && StoX(mpawn) <= 0x4){
			RETRUN_MUL(2);
		}
	}
	
	// fen 5a3/5k3/3a1N3/9/6b2/6c2/9/5K3/3p5/9 w - - 0 1
	// ����Է��Ľ�ǣ��ס��. 
	if(bit_is_set(ei.attacked_by(my_king),yma)){
		RETRUN_MUL(16);
	}

	// fen 9/5k3/4P4/5C3/3n5/9/9/4B4/9/2BK5 w - - 0 123
	if(my_shi_num == 0 && StoY(mpawn) MY_SMALL_EQL MY_RANK2){
		if(abs(StoY(mpawn) - StoY(yk)) <= 1){
			RETRUN_MUL(2);
		}
	}

	// fen 4ka3/4a4/4bc1N1/9/2b6/9/9/4B1p2/4A4/3K5 b - - 0 0
	//�ڱ��������࣬

	// fen 9/4P4/5k3/9/9/2B6/2n6/3KBA3/4A4/8C b - - 126 126
	if(StoY(mpawn) MY_SMALL StoY(yk) && StoY(yma) MY_LARGE_EQL MY_RANK5){
		RETRUN_MUL(4);
	}


	// fen 1c7/3ka4/9/6N2/9/9/9/3p5/4K4/3A5 w - - 121 121
	if(my_xiang_num == 0 && my_shi_num <= 1){
		if(your_shi_num >= 1 && StoY(yma) MY_LARGE_EQL MY_RANK4){
			if(abs(StoY(mpawn) - StoY(yk)) <= 1){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 5k3/4P4/3Cb4/3n5/9/2B6/9/4BA3/9/4K4 w - - 0 1
    if(your_xiang_num >= 1 && StoY(mpawn) MY_SMALL_EQL MY_RANK1){
		if(StoY(mpao) MY_SMALL_EQL MY_RANK2){
			if(abs(StoY(yma) - MY_RANK3) <= 1){
				RETRUN_MUL(4);
			}
		}
	}

	// fen 4k4/9/9/4P4/9/2B1n4/9/9/5K3/5C3 r
	if(my_shi_num == 0 && my_xiang_num <= 1){
		MY_EV_SUB(128);
		if(!bit_is_set(EV_MY_XBIT,yma)){
			RETRUN_MUL(4);
		}
	}

	// fen 2b2c3/3ka4/5a3/9/9/9/6N2/4B4/5p3/4K4 b - - 0 103
	if(your_xiang_num >= 1){
		if(StoY(yk) == MY_RANK0 && PB90(MY_SQ0D) == my_pawn){
		}
		else{
			RETRUN_MUL(8);
		}
	}

	// fen 4k4/3n1P3/5a2C/9/9/9/9/5A3/3K5/6B2 b - - 0 1

}

