
#include "..\\..\\chess.h"
#include "..\\..\\preGen.h"

#include "..\\..\\endgame\mat.h"

const int ADD_byShi[3]   = {196,64,32};

//�����Գ���
void m_MT_1CHE1PAWN_TO_1CHE1PAWN(typePOS *POSITION, EvalInfo *ei){

	int rpawn = S90_from_piecelist(POSITION,RPAWN,0);
	int bpawn = S90_from_piecelist(POSITION,BPAWN,0);

	int rk = RKpos();
	int bk = BKpos();

	int rche = S90_from_piecelist(POSITION,RCHE,0);
	int bche = S90_from_piecelist(POSITION,BCHE,0);

	int rcan = White_pawn_can_over_river(POSITION);
	int bcan = Black_pawn_can_over_river(POSITION);

	//���һ���ǵͱ�����Ҫ����
	if(StoY(bpawn) == 0x9){
		ei->evscore += 64;
	}
	if(StoY(rpawn) == 0x0){
		ei->evscore -= 64;
	}

	if(StoX(rk) == 0x4){
		ei->evscore += 64;
	}
	if(StoX(bk) == 0x4){
		ei->evscore -= 64;
	}

	if(StoX(rche) == 0x4){
		ei->evscore += 64;
	}
	if(StoX(bche) == 0x4){
		ei->evscore -= 64;
	}
	//���һ���Ľ���Է��ı���ͬһ��,Ҫ����
	if(King_4_Side(rk) == King_4_Side(bpawn)){
		if(StoY(bpawn) == 0x9){
			ei->evscore -= 24;
		}
		else{
			ei->evscore -= 64;
		}
	}
	if(King_4_Side(bk) == King_4_Side(rpawn)){
		if(StoY(rpawn) == 0x0){
			ei->evscore += 24;
		}
		else{
			ei->evscore += 64;
		}
	}
    // ˫������������
	if(BShi_num() == 2 && StoY(bk) <= 1){
		ei->bsafe = TRUE;
	}
	if(RShi_num() == 2 && StoY(rk) >= 8){
		ei->rsafe = TRUE;
	}
	//fen 4k4/4a1P2/3ab4/9/2b2r3/9/4R4/4Bp3/4A4/3K2B2 w - - 0 0
	if(RXiang_num() == 2 && RShi_num() >= 1){
		if(StoY(bpawn) <= 0x7){
			if(StoX(rk) == 0x3){
				if(StoX(bpawn) > 0x4){
					ei->rsafe = TRUE;
				}
			}
			if(StoX(rk) == 0x5){
				if(StoX(bpawn) < 0x4){
					ei->rsafe = TRUE;
				}
			}
		}
	}
	if(BXiang_num() == 2 && BShi_num() >= 1){
		if(StoY(rpawn) >= 0x2){
			if(StoX(bk) == 0x3){
				if(StoX(rpawn) > 0x4){
					ei->bsafe = TRUE;
				}
			}
			if(StoX(bk) == 0x5){
				if(StoX(rpawn) < 0x4){
					ei->bsafe = TRUE;
				}
			}
		}
	}
	//fen 5Rb2/3k5/4b4/9/p3r4/6P2/9/3ABA3/9/2B1K4 w - - 71 71
	if(BXiang_num() == 2){
		if(StoY(rpawn) >= 0x5 && rcan == 0){
			ei->bsafe = TRUE;
		}
	}
	if(RXiang_num() == 2){
		if(StoY(bpawn) <= 0x4 && bcan == 0){
			ei->rsafe = TRUE;
		}
	}

	if(StoY(rpawn) > StoY(bk)){
		ei->evscore += ADD_byShi[BShi_num()];
	}
	if(StoY(bpawn) < StoY(rk)){
		ei->evscore -= ADD_byShi[RShi_num()];
	}

	//���˫���ı���û�й���,����һ������,��ֻҪһ���г��ڱ������Ǻ��� 
	if(StoY(rpawn) > 0x4 && StoY(bpawn) < 0x5 && StoX(rpawn) == StoX(bpawn)){
		if(StoY(rche) == StoY(rpawn)){
			RETRUN_MUL(2);
		}
		if(StoY(bche) == StoY(bpawn)){
			RETRUN_MUL(2);
		}
	}
}
