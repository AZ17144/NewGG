#include "chess.h"
 
#ifdef USE_STOCK_FISH_FILE
#else

#include "preGen.h"
#include "eval_const_h.h"

int Point_StringScoreByChe[16];  // ��ǣ�����ڵĵ÷�

int Point_R_XianProtectPoint[16]; // �󱣻��Լ����ӵĵ÷�
int Point_B_XianProtectPoint[16];

int Point_R_ShiProtectPoint[16];  // �˱����Լ����ӵĵ÷�
int Point_B_ShiProtectPoint[16];

int point_R_CheProtectPoint[16];  // �������ķ���
int point_B_CheProtectPoint[16];  

int Point_R_ma_Att_Score[16]; // �����Լ����ӵĵ÷�
int Point_B_ma_Att_Score[16];

int Point_R_pawn_Att_Score[16]; // �������Լ����ӵĵ÷�
int Point_B_pawn_Att_Score[16];

int PAWN_NUM_OVER_RIVER_point[8];      //       point(t,t);

//fen 2b1k2r1/3Ra4/2c6/p3p1n1p/2pn5/8P/P2rP4/2N2R2N/4A4/2B1KAB2 w - - 0 
//���ǣ������74�����ң�
// ---------------------------------------------------------------------- ��ǣ������
const static sint16 opening_stringbyche[16]  = { 
	0,
//  ��	 ��	  ��   ��   ��   ��	 ��   
	0,   0,   0,  16,  0,   0,   0,     // ����, �錢
	0,
	0,   0,   0, -16,  0,  -0,   0,     // ����
};
const static sint16 endgame_stringbyche[16]  = { 
	0,
//  ��	 ��	  ��   ��   ��   ��	  ��   
	0,   0,   0, 168,  0,  196,   0,     // ����, �錢
	0,
	0,   0,   0,-168,  0, -196,   0,     // ����
};
// ---------------------------------------------------------------------- �����Լ�������
const static sint16 opening_Rche_Att_Score[16]  = { 
	0,
//  ��	 ��	  ��   ��   ��    ��	   ��   
	16,  0,   0,   0,  16,   8,    0,     // ����, //��Ϊ������˫���ģ����Եü�����
	0,
	0,   0,   0,  16,   0,    0,   0,     // ����
};


const static sint16 endgame_Rche_Att_Score[16]  = { 
	0,
//  ��	 ��	  ��   ��   ��    ��	   ��   
	0,   8,   8,  12,  32,   16,   4,     // ����, �錢
	0,
	0,   8,   8,  32,   0,   32,   16,     // ����
};


const static sint16 opening_Rma_Att_Score[16]  = { 
	0,
//  ��	 ��	  ��   ��   ��    ��	   ��   
	0,   8,   8,  12,  16,   16,   8,     // ����, //��Ϊ������˫���ģ����Եü�����
	0,
	0,  16,  16,  16,  32,   16,   8,     // ����
};


const static sint16 endgame_Rma_Att_Score[16]  = { 
	0,
//  ��	 ��	  ��   ��   ��    ��	   ��   
	0,   8,   8,  12,  16,   16,  16,     // ����, �錢
	0,
	0,  16,  16,  16,  32,   16,   8,     // ����
};

// ---------------------------------------------------------------------- �˱����Լ�������
const static sint16 opening_Rshi_Att_Score[16]  = { 
	0,
//  ��	 ��	  ��   ��   ��    ��	   ��   
	0,   8,   0,  12,  16,   16,   0,     // ����,      // ��Ϊ�˱�����˫���ģ����Եü�����
	0,
	0,   0,   0,  32,  64,   32,   8,     // ����
};

const static sint16 endgame_Rshi_Att_Score[16]  = { 
	0,
//  ��	 ��	  ��   ��    ��    ��	   ��   
	0,   8,   0,  12,  16,   16,   0,     // ����, �錢
	0,
	0,   0,   0,  32,  64,   32,   8,     // ����
};

// ---------------------------------------------------------------------- ��
const static sint16 opening_Rxiang_Att_Score[16]  = { 
	0,
//  ��	 ��	  ��   ��   ��    ��	   ��   
	0,   0,   8,  12,  16,   16,   16,     // ����, //��Ϊ�ౣ����˫���ģ����Եü�����
	0,
	0,   0,   0,  32,  64,   32,   8,      // ����
};

const static sint16 endgame_Rxiang_Att_Score[16]  = { 
	0,
//  ��	 ��	  ��   ��    ��    ��	   ��   
	0,   0,   8,  12,  16,   16,   16,     // ����, 
	0,
	0,   0,   0,  32,  64,   32,   8,      // ����
};

// ---------------------------------------------------------------------- �������Լ������ӵĵ÷�
const static sint16 opening_Rpawn_Att_Score[16]  = { 
	0,
//  ��	 ��	  ��   ��    ��    ��	   ��   
	0,   0,   0,  24,  16,   16,   16,      // ����, //��Ϊ�ౣ����˫���ģ����Եü�����
	0,
	0,  24,  24,  32,  64,   32,   16,      // ����
};


const static sint16 endgame_Rpawn_Att_Score[16]  = { 
	0,
//  ��	 ��	  ��   ��    ��    ��	   ��   
	0,   0,   0,  16,  16,   16,   16,     // ����, 
	0,
	0,  36,  24,  32,  64,   32,   16,      // ����
};

// --------------------------------------------------------------------------------------
static void initPointbyOpenEnd(int PointArr[], const sint16 openArr[], const sint16 endArr[], bool isMirror){
	int i;
	for(i = 0; i < 16; i++){
		if(isMirror){
			PointArr[i] = point(openArr[revertChess[i]],endArr[revertChess[i]]);
		}
		else{
		    PointArr[i] = point(openArr[i],endArr[i]);
		}
	}
}

void eval_const_int(void){

	initPointbyOpenEnd(Point_StringScoreByChe,
		opening_stringbyche,endgame_stringbyche,FALSE);    // ��ǣ��

	//extern int point_R_CheProtectPoint[16];  // �������ķ���
	//extern int point_B_CheProtectPoint[16]; 

	initPointbyOpenEnd(point_R_CheProtectPoint,
		opening_Rche_Att_Score,endgame_Rche_Att_Score,FALSE);  // �쳵�����Լ�������
	initPointbyOpenEnd(point_B_CheProtectPoint,
		opening_Rche_Att_Score,endgame_Rche_Att_Score,TRUE);  // �ڳ������Լ�������

	//initPointbyOpenEnd(point_B_CheProtectPoint,
	//	opening_Bche_Att_Score,endgame_Bche_Att_Score);  // �ڳ������Լ�������

	initPointbyOpenEnd(Point_R_ma_Att_Score,
		opening_Rma_Att_Score,endgame_Rma_Att_Score,FALSE);  // �������Լ�������
	initPointbyOpenEnd(Point_B_ma_Att_Score,
		opening_Rma_Att_Score,endgame_Rma_Att_Score,TRUE);  // �������Լ�������

	//initPointbyOpenEnd(Point_B_ma_Att_Score,
	//	opening_Bma_Att_Score,endgame_Bma_Att_Score);  // �������Լ�������

	initPointbyOpenEnd(Point_R_XianProtectPoint,
		opening_Rxiang_Att_Score,endgame_Rxiang_Att_Score,FALSE);  // ���󱣻��Լ�������
	initPointbyOpenEnd(Point_B_XianProtectPoint,
		opening_Rxiang_Att_Score,endgame_Rxiang_Att_Score,TRUE);  // ���󱣻��Լ�������

	//initPointbyOpenEnd(Point_B_XianProtectPoint,
	//	opening_Bxiang_Att_Score,endgame_Bxiang_Att_Score);  // ���󱣻��Լ�������

	initPointbyOpenEnd(Point_R_ShiProtectPoint,
		opening_Rshi_Att_Score,endgame_Rshi_Att_Score,FALSE);  // ���˱����Լ�������

	initPointbyOpenEnd(Point_B_ShiProtectPoint,
		opening_Rshi_Att_Score,endgame_Rshi_Att_Score,TRUE);  // ���˱����Լ�������

	//initPointbyOpenEnd(Point_B_ShiProtectPoint,
	//	opening_Bshi_Att_Score,endgame_Bshi_Att_Score);  // ���˱����Լ�������

	initPointbyOpenEnd(Point_R_pawn_Att_Score,
		opening_Rpawn_Att_Score,endgame_Rpawn_Att_Score,FALSE);  // ���䱣���Լ�������
	initPointbyOpenEnd(Point_B_pawn_Att_Score,
		opening_Rpawn_Att_Score,endgame_Rpawn_Att_Score,TRUE);  // ���䱣���Լ�������

	//initPointbyOpenEnd(Point_B_pawn_Att_Score,
	//	opening_Bpawn_Att_Score,endgame_Bpawn_Att_Score);  // ���䱣���Լ�������

	//const static sint16 PAWN_NUM_OVER_RIVER[6] =   {0, 16, 96, 108, 116, 124};
	//extern int PAWN_NUM_OVER_RIVER_point[16];      //       point(t,t);
	for(int i = 0; i < 6; i++){
		PAWN_NUM_OVER_RIVER_point[i] = point(PAWN_NUM_OVER_RIVER[i],PAWN_NUM_OVER_RIVER[i]);
	}
}

#endif

