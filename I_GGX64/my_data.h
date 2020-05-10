#ifndef S_MY_DATA_CHESS_H
#define S_MY_DATA_CHESS_H

//#include "s_value.h"

extern MARR_t *MARR;
extern premat_t PreMatInfo[6][6][3][3][3][3][3][3];
extern int      MatAddress[16];



#define maleg(from,to) Square(_MaLegTable[from][to])
extern uint8  _MaLegTable[90][90];                 //

#define TOTAL_SAFE_POINT  512
#define MIN_ZEOR_SAFE_POINT 64
extern Score  SafetyTable[TOTAL_SAFE_POINT];                  //��ȫ��
extern uint8  KposSafe[90];

extern TCHAR installDir[512];			   //�������Ŀ¼
#ifdef  USE_LOG_FILE
extern TCHAR  log_path[512];
extern FILE*   llog_file;
#endif

extern Bitboard PaoCanAttKing[90];					   // �ж�һ����������
extern Bitboard BitMaGooDMove[2];                      // ���кò��ӿ���

extern Score PrePawnAttKingMul_Safe[3][90][90];        // ���ܹ����������� 
extern Score point_R_01Shi_B_Pawn90[3][90];            // �Է�ȱ��ʱ����λ�÷�
extern Score point_B_01Shi_R_Pawn90[3][90];

extern Bitboard CheYaMa[90];

extern bool MustOuPutEvalInf;

#endif