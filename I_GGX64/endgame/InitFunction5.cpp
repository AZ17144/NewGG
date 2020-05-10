#ifndef E_InitMatFunction5
#define E_InitMatFunction5
#include "..\\chess.h"
 
#include "..\\white.h"
#else
#include "..\\black.h"
#endif

void InitMatFunction5(void){
	//********************************************* 5 �� 0*****************************************************************

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [0]  [0]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_R_5pawn;
	funMat[MARR->a[0]  [5]  [0]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_B_5pawn;

	//************************************5 �� 1*********************************************************
	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [1]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_R_1CHE_4PAWN_B_1CHE;
	funMat[MARR->a[0]  [4]  [1]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1CHE_4PAWN_R_1CHE;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [1]  [0]  [0]  [0]  [0]  [1]  ]  = m_MT_R_1che4pawn_B_1pao;
	funMat[MARR->a[0]  [4]  [0]  [0]  [1]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [1]  [0]  [0]  [0]  [1]  [0]  ]  = m_MT_R_1che4pawn_B_1ma;
	funMat[MARR->a[0]  [4]  [0]  [1]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [1]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_R_1che4pawn_B_1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [0]  [1]  [2]  [1]  [0]  [0]  ]  = m_MT_R_2pao_1ma2pawn_B_1che;
	funMat[MARR->a[0]  [2]  [1]  [0]  [0]  [0]  [1]  [2]  ]  = m_MT_B_2pao_1ma2pawn_R_1che;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [0]  [2]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao_2ma2pawn_B_1che;
	funMat[MARR->a[0]  [2]  [1]  [0]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao_2ma2pawn_R_1che;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [0]  [2]  [1]  [0]  [0]  ]  = m_MT_R_2pao_3pawn_B_1che;
	funMat[MARR->a[0]  [3]  [1]  [0]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao_3pawn_R_1che;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [0]  [2]  [0]  [0]  [1]  ]  = m_MT_R_2pao_3pawn_B_1pao;
	funMat[MARR->a[0]  [3]  [0]  [0]  [1]  [0]  [0]  [2]  ]  = m_MT_B_2pao_3pawn_R_1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [0]  [2]  [0]  [1]  [0]  ]  = m_MT_R_2pao_3pawn_B_1ma;
	funMat[MARR->a[0]  [3]  [0]  [1]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao_3pawn_R_1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [0]  [2]  [0]  [0]  [0]  ]  = m_MT_R_2pao_3pawn_B_1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao_3pawn_R_1pawn;

		//           ���  ����  �쳵  ����  ����  �ڳ�  ����   ���� 
	funMat[MARR->a[3]  [0]  [0]  [1]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao1ma_3pawn_B_1che;
	funMat[MARR->a[0]  [3]  [1]  [0]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_3pawn_R_1che;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [1]  [1]  [0]  [0]  [1]  ]  = m_MT_R_1pao_1ma3pawn_B_1pao;
	funMat[MARR->a[0]  [3]  [0]  [0]  [1]  [0]  [1]  [1]  ]  = m_MT_B_1pao_1ma3pawn_R_1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [1]  [1]  [0]  [1]  [0]  ]  = m_MT_R_1pao1ma_3pawn_B_1ma;
	funMat[MARR->a[0]  [3]  [0]  [1]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_3pawn_R_1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [1]  [1]  [0]  [0]  [0]  ]  = m_MT_R_1pao1ma_3pawn_B_1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma_3pawn_R_1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [2]  [0]  [1]  [0]  [0]  ]  = m_MT_R_2ma_3pawn_B_1che;
	funMat[MARR->a[0]  [3]  [1]  [0]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma_3pawn_R_1che;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [2]  [0]  [0]  [0]  [1]  ]  = m_MT_R_2ma_3pawn_B_1pao;
	funMat[MARR->a[0]  [3]  [0]  [0]  [1]  [0]  [2]  [0]  ]  = m_MT_B_2ma_3pawn_R_1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [2]  [0]  [0]  [1]  [0]  ]  = m_MT_R_2ma_3pawn_B_1ma;
	funMat[MARR->a[0]  [3]  [0]  [1]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma_3pawn_R_1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [2]  [0]  [0]  [0]  [0]  ]  = m_MT_R_2ma_3pawn_B_1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma_3pawn_R_1pawn;


	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [0]  [0]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao4pawn_B_1che;
	funMat[MARR->a[0]  [4]  [1]  [0]  [0]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_1che;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [0]  [0]  [1]  [0]  [0]  [1]  ]  = m_MT_R_1PAO4PAWN_B_1PAO;	
	funMat[MARR->a[0]  [4]  [0]  [0]  [1]  [0]  [0]  [1]  ]  = m_MT_B_1PAO4PAWN_R_1PAO;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [0]  [0]  [1]  [0]  [1]  [0]  ]  = m_MT_R_1PAO4PAWN_B_1MA;	
	funMat[MARR->a[0]  [4]  [0]  [1]  [0]  [0]  [0]  [1]  ]  = m_MT_B_1PAO4PAWN_R_1MA;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [0]  [0]  [1]  [0]  [0]  [0]  ]  = m_MT_R_1pao4pawn_B_1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [0]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [0]  [1]  [0]  [1]  [0]  [0]  ]  = m_MT_R_1ma4pawn_B_1che;  
	funMat[MARR->a[0]  [4]  [1]  [0]  [0]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_1che;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [0]  [1]  [0]  [0]  [0]  [1]  ]  = m_MT_R_1ma4pawn_B_1pao;  
	funMat[MARR->a[0]  [4]  [0]  [0]  [1]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [0]  [1]  [0]  [0]  [1]  [0]  ]  = m_MT_R_1ma4pawn_B_1ma;  
	funMat[MARR->a[0]  [4]  [0]  [1]  [0]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [0]  [1]  [0]  [0]  [0]  [0]  ]  = m_MT_R_1ma4pawn_B_1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [0]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [0]  [0]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_R_5pawn_B_1che;
	funMat[MARR->a[0]  [5]  [1]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_B_5pawn_R_1che;
	
	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [0]  [0]  [0]  [0]  [0]  [0]  [1]  ]  = m_MT_R_5pawn_B_1pao;
	funMat[MARR->a[0]  [5]  [0]  [0]  [1]  [0]  [0]  [0]  ]  = m_MT_B_5pawn_R_1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [0]  [0]  [0]  [0]  [0]  [1]  [0]  ]  = m_MT_R_5pawn_B_1ma;
	funMat[MARR->a[0]  [5]  [0]  [1]  [0]  [0]  [0]  [0]  ]  = m_MT_B_5pawn_R_1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [1]  [0]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_R_5pawn_B_1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_B_5pawn_R_1pawn;

	//************************************5 �� 2*********************************************************
    //           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [2]  [0]  [1]  [2]  [0]  [0]  ]  = m_MT_R_2che1pao2pawn_B_2che; //2��1��1����2��
	funMat[MARR->a[0]  [2]  [2]  [0]  [0]  [2]  [0]  [1]  ]  = m_MT_B_2che1pao2pawn_R_2che;

	 //           ���  ����  �쳵  ����  ����  �ڳ�  ����  ������ 
	funMat[MARR->a[2]  [0]  [2]  [1]  [0]  [2]  [0]  [0]  ]  = m_MT_R_2che1ma2pawn_B_2che; //2��1��1����2��
	funMat[MARR->a[0]  [2]  [2]  [0]  [0]  [2]  [1]  [0]  ]  = m_MT_B_2che1ma2pawn_R_2che;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [2]  [0]  [0]  [2]  [0]  [0]  ]  = m_MT_R_2che3pawn_B_2che;
	funMat[MARR->a[0]  [3]  [2]  [0]  [0]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_2che;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [0]  [2]  [2]  [0]  [0]  ]  = m_MT_R_1che2pao2pawn_B_2che;   
	funMat[MARR->a[0]  [2]  [2]  [0]  [0]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao2pawn_R_2che;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [0]  [2]  [1]  [1]  [0]  ]  = m_MT_R_1che2pao2pawn_B_1che1ma;   
	funMat[MARR->a[0]  [2]  [1]  [1]  [0]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao2pawn_R_1che1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [1]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1che1pao1ma2pawn_B_1che1ma;   
	funMat[MARR->a[0]  [2]  [1]  [1]  [0]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_1che1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [2]  [0]  [1]  [1]  [0]  ]  = m_MT_R_1che2ma2pawn_B_1che1ma;   
	funMat[MARR->a[0]  [2]  [1]  [1]  [0]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma2pawn_R_1che1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [1]  [1]  [2]  [0]  [0]  ]  = m_MT_R_1che1pao1ma2pawn_B_2che;
	funMat[MARR->a[0]  [2]  [2]  [0]  [0]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_2che;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [0]  [1]  [2]  [0]  [0]  ]  = m_MT_R_1che1pao3pawn_B_2che;   
	funMat[MARR->a[0]  [3]  [2]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_2che;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [0]  [1]  [1]  [0]  [1]  ]  = m_MT_R_1che1pao3pawn_B_1che1pao; 
	funMat[MARR->a[0]  [3]  [1]  [0]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1che1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [0]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1che1pao3pawn_B_1che1ma;	
	funMat[MARR->a[0]  [3]  [1]  [1]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1che1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [1]  [0]  [2]  [0]  [0]  ]  = m_MT_R_1che1ma3pawn_B_2che;
	funMat[MARR->a[0]  [3]  [2]  [0]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_2che;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [1]  [0]  [1]  [0]  [1]  ]  = m_MT_R_1che1ma3pawn_B_1che1pao;
	funMat[MARR->a[0]  [3]  [1]  [0]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1che1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [1]  [0]  [1]  [1]  [0]  ]  = m_MT_R_1che1ma3pawn_B_1che1ma;
	funMat[MARR->a[0]  [3]  [1]  [1]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1che1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [1]  [0]  [0]  [2]  [0]  [0]  ]  = m_MT_R_1che4pawn_B_2che;
	funMat[MARR->a[0]  [4]  [2]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_2che;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [1]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_R_1che4pawn_B_1che1pao; 
	funMat[MARR->a[0]  [4]  [1]  [0]  [1]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1che1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [1]  [0]  [0]  [1]  [1]  [0]  ]  = m_MT_R_1che4pawn_B_1che1ma;
	funMat[MARR->a[0]  [4]  [1]  [1]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1che1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [1]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_R_1che4pawn_B_1che1pawn;
	funMat[MARR->a[1]  [4]  [1]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1che1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [1]  [0]  [0]  [0]  [0]  [2]  ]  = m_MT_R_1che4pawn_B_2pao;
	funMat[MARR->a[0]  [4]  [0]  [0]  [2]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_2pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [1]  [0]  [0]  [0]  [1]  [1]  ]  = m_MT_R_1che4pawn_B_1pao1ma;
	funMat[MARR->a[0]  [4]  [0]  [1]  [1]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [1]  [0]  [0]  [0]  [2]  [0]  ]  = m_MT_R_1che4pawn_B_2ma;
	funMat[MARR->a[0]  [4]  [0]  [2]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [1]  [0]  [0]  [0]  [0]  [1]  ]  = m_MT_R_1che4pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [1]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [1]  [0]  [0]  [0]  [1]  [0]  ]  = m_MT_R_1che4pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [2]  [1]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_R_1che4pawn_B_2pawn;
	funMat[MARR->a[2]  [4]  [0]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [0]  [1]  [2]  [1]  [0]  [1]  ]  = m_MT_R_2pao1ma2pawn_B_1che1pao;  //
	funMat[MARR->a[0]  [2]  [1]  [0]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_1che1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [0]  [1]  [2]  [1]  [1]  [0]  ]  = m_MT_R_2pao1ma2pawn_B_1che1ma; 
	funMat[MARR->a[0]  [2]  [1]  [1]  [0]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_1che1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [0]  [2]  [1]  [1]  [0]  [1]  ]  = m_MT_R_1pao2ma2pawn_B_1che1pao;  //
	funMat[MARR->a[0]  [2]  [1]  [0]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma2pawn_R_1che1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [0]  [2]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1pao2ma2pawn_B_1che1ma; 
	funMat[MARR->a[0]  [2]  [1]  [1]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma2pawn_R_1che1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [0]  [1]  [2]  [1]  [0]  [0]  ]  = m_MT_R_2pao_1ma2pawn_B_1che1pawn;
	funMat[MARR->a[1]  [2]  [1]  [0]  [0]  [0]  [1]  [2]  ]  = m_MT_B_2pao_1ma2pawn_R_1che1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [0]  [2]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao_2ma2pawn_B_1che1pawn;
	funMat[MARR->a[1]  [2]  [1]  [0]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao_2ma2pawn_R_1che1pawn;
	
	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [0]  [2]  [1]  [0]  [0]  ]  = m_MT_R_2pao3pawn_B_1che1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_1che1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [0]  [2]  [0]  [0]  [2]  ]  = m_MT_R_2pao3pawn_B_2pao;
	funMat[MARR->a[0]  [3]  [0]  [0]  [2]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_2pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [0]  [2]  [0]  [1]  [1]  ]  = m_MT_R_2pao3pawn_B_1ma1pao;
	funMat[MARR->a[0]  [3]  [0]  [1]  [1]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_1ma1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [0]  [2]  [0]  [2]  [0]  ]  = m_MT_R_2pao3pawn_B_2ma;
	funMat[MARR->a[0]  [3]  [0]  [2]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [2]  [0]  [1]  [0]  [0]  ]  = m_MT_R_2ma3pawn_B_1che1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_1che1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [2]  [0]  [0]  [0]  [2]  ]  = m_MT_R_2ma3pawn_B_2pao;
	funMat[MARR->a[0]  [3]  [0]  [0]  [2]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_2pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [2]  [0]  [0]  [1]  [1]  ]  = m_MT_R_2ma3pawn_B_1ma1pao;
	funMat[MARR->a[0]  [3]  [0]  [1]  [1]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_1ma1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [2]  [0]  [0]  [2]  [0]  ]  = m_MT_R_2ma3pawn_B_2ma;
	funMat[MARR->a[0]  [3]  [0]  [2]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [1]  [1]  [1]  [0]  [1]  ]  = m_MT_R_1ma1pao3pawn_B_1che1pao;
	funMat[MARR->a[0]  [3]  [1]  [0]  [1]  [0]  [1]  [1]  ]  = m_MT_B_1ma1pao3pawn_R_1che1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [1]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1ma1pao3pawn_B_1che1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1ma1pao3pawn_R_1che1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [1]  [1]  [0]  [0]  [2]  ]  = m_MT_R_1ma1pao3pawn_B_2pao;
	funMat[MARR->a[0]  [3]  [0]  [0]  [2]  [0]  [1]  [1]  ]  = m_MT_B_1ma1pao3pawn_R_2pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [1]  [1]  [0]  [1]  [1]  ]  = m_MT_R_1ma1pao3pawn_B_1ma1pao;
	funMat[MARR->a[0]  [3]  [0]  [1]  [1]  [0]  [1]  [1]  ]  = m_MT_B_1ma1pao3pawn_R_1ma1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [1]  [1]  [0]  [2]  [0]  ]  = m_MT_R_1ma1pao3pawn_B_2ma;
	funMat[MARR->a[0]  [3]  [0]  [2]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1ma1pao3pawn_R_2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [0]  [2]  [0]  [0]  [1]  ]  = m_MT_R_2pao3pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [1]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_1pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [0]  [2]  [0]  [1]  [0]  ]  = m_MT_R_2pao3pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [1]  [1]  [0]  [0]  [1]  ]  = m_MT_R_1ma1pao3pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [1]  [0]  [1]  [1]  ]  = m_MT_B_1ma1pao3pawn_R_1pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [1]  [1]  [0]  [1]  [0]  ]  = m_MT_R_1ma1pao3pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1ma1pao3pawn_R_1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [2]  [0]  [0]  [0]  [1]  ]  = m_MT_R_2ma3pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [1]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_1pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [2]  [0]  [0]  [1]  [0]  ]  = m_MT_R_2ma3pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [0]  [0]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao4pawn_B_1che1pawn;
	funMat[MARR->a[1]  [4]  [1]  [0]  [0]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_1che1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [0]  [0]  [1]  [0]  [0]  [2]  ]  = m_MT_R_1pao4pawn_B_2pao;   
	funMat[MARR->a[0]  [4]  [0]  [0]  [2]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_2pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [0]  [0]  [1]  [0]  [1]  [1]  ]  = m_MT_R_1pao4pawn_B_1pao1ma;
	funMat[MARR->a[0]  [4]  [0]  [1]  [1]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_1pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [0]  [0]  [1]  [0]  [2]  [0]  ]  = m_MT_R_1pao4pawn_B_2ma;
	funMat[MARR->a[0]  [4]  [0]  [2]  [0]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [0]  [0]  [1]  [0]  [0]  [1]  ]  = m_MT_R_1pao4pawn_B_1pao1pawn;	
	funMat[MARR->a[1]  [4]  [0]  [0]  [1]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_1pao1pawn; 

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [0]  [0]  [1]  [0]  [1]  [0]  ]  = m_MT_R_1pao4pawn_B_1ma1pawn;	
	funMat[MARR->a[1]  [4]  [0]  [1]  [0]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [2]  [0]  [0]  [1]  [0]  [0]  [0]  ]  = m_MT_R_1pao4pawn_B_2pawn;	
	funMat[MARR->a[2]  [4]  [0]  [0]  [0]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [0]  [1]  [0]  [0]  [0]  [2]  ]  = m_MT_R_1ma4pawn_B_2pao;   
	funMat[MARR->a[0]  [4]  [0]  [0]  [2]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_2pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [0]  [1]  [0]  [0]  [1]  [1]  ]  = m_MT_R_1ma4pawn_B_1pao1ma;	
	funMat[MARR->a[0]  [4]  [0]  [1]  [1]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_1pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [0]  [1]  [0]  [0]  [2]  [0]  ]  = m_MT_R_1ma4pawn_B_2ma;  
	funMat[MARR->a[0]  [4]  [0]  [2]  [0]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [0]  [1]  [0]  [0]  [0]  [1]  ]  = m_MT_R_1ma4pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [1]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_1pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [0]  [1]  [0]  [0]  [1]  [0]  ]  = m_MT_R_1ma4pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [0]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [2]  [0]  [1]  [0]  [0]  [0]  [0]  ]  = m_MT_R_1ma4pawn_B_2pawn;
	funMat[MARR->a[2]  [4]  [0]  [0]  [0]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [1]  [0]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_R_5pawn_B_1che1pawn;
	funMat[MARR->a[1]  [5]  [1]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_B_5pawn_R_1che1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [1]  [0]  [0]  [0]  [0]  [0]  [1]  ]  = m_MT_R_5pawn_B_1pao1pawn;
	funMat[MARR->a[1]  [5]  [0]  [0]  [1]  [0]  [0]  [0]  ]  = m_MT_B_5pawn_R_1pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [1]  [0]  [0]  [0]  [0]  [1]  [0]  ]  = m_MT_R_5pawn_B_1ma1pawn;
	funMat[MARR->a[1]  [5]  [0]  [1]  [0]  [0]  [0]  [0]  ]  = m_MT_B_5pawn_R_1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [2]  [0]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_R_5pawn_B_2pawn;
	funMat[MARR->a[2]  [5]  [0]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_B_5pawn_R_2pawn;
	
	//************************************5 �� 3*********************************************************
	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [2]  [0]  [1]  [2]  [0]  [1]  ]  = m_MT_R_2che1pao2pawn_B_2che1pao;
	funMat[MARR->a[0]  [2]  [2]  [0]  [1]  [2]  [0]  [1]  ]  = m_MT_B_2che1pao2pawn_R_2che1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [2]  [1]  [0]  [2]  [0]  [1]  ]  = m_MT_R_2che1ma2pawn_B_2che1pao;
	funMat[MARR->a[0]  [2]  [2]  [0]  [1]  [2]  [1]  [0]  ]  = m_MT_B_2che1ma2pawn_R_2che1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [2]  [0]  [1]  [2]  [1]  [0]  ]  = m_MT_R_2che1pao2pawn_B_2che1ma;
	funMat[MARR->a[0]  [2]  [2]  [1]  [0]  [2]  [0]  [1]  ]  = m_MT_B_2che1pao2pawn_R_2che1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [2]  [1]  [0]  [2]  [1]  [0]  ]  = m_MT_R_2che1ma2pawn_B_2che1ma;
	funMat[MARR->a[0]  [2]  [2]  [1]  [0]  [2]  [1]  [0]  ]  = m_MT_B_2che1ma2pawn_R_2che1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [2]  [0]  [0]  [2]  [0]  [1]  ]  = m_MT_R_2che3pawn_B_2che1pao;
	funMat[MARR->a[0]  [3]  [2]  [0]  [1]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_2che1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [2]  [0]  [0]  [2]  [1]  [0]  ]  = m_MT_R_2che3pawn_B_2che1ma;
	funMat[MARR->a[0]  [3]  [2]  [1]  [0]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_2che1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [2]  [0]  [0]  [2]  [0]  [0]  ]  = m_MT_R_2che3pawn_B_2che1pawn;
	funMat[MARR->a[1]  [3]  [2]  [0]  [0]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_2che1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [2]  [0]  [0]  [1]  [0]  [2]  ]  = m_MT_R_2che3pawn_B_1che2pao;
	funMat[MARR->a[0]  [3]  [1]  [0]  [2]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_1che2pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [2]  [0]  [0]  [1]  [1]  [1]  ]  = m_MT_R_2che3pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [3]  [1]  [1]  [1]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_1che1pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [2]  [0]  [0]  [1]  [2]  [0]  ]  = m_MT_R_2che3pawn_B_1che2ma;
	funMat[MARR->a[0]  [3]  [1]  [2]  [0]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_1che2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [2]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_R_2che3pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [1]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_1che1pao1pawn;

    //           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [2]  [0]  [0]  [1]  [1]  [0]  ]  = m_MT_R_2che3pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [3]  [1]  [1]  [0]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_1che1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [2]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_R_2che3pawn_B_1che2pawn;
	funMat[MARR->a[2]  [3]  [1]  [0]  [0]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_1che2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [1]  [0]  [2]  [2]  [0]  [0]  ]  = m_MT_R_1che2pao2pawn_B_2che1pawn;
	funMat[MARR->a[1]  [2]  [2]  [0]  [0]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao2pawn_R_2che1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [0]  [2]  [1]  [0]  [2]  ]  = m_MT_R_1che2pao2pawn_B_1che2pao;   //---------
	funMat[MARR->a[0]  [2]  [1]  [0]  [2]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao2pawn_R_1che2pao; 

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [0]  [2]  [1]  [1]  [1]  ]  = m_MT_R_1che2pao2pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [2]  [1]  [1]  [1]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao2pawn_R_1che1pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [0]  [2]  [1]  [2]  [0]  ]  = m_MT_R_1che2pao2pawn_B_1che2ma;
	funMat[MARR->a[0]  [2]  [1]  [2]  [0]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao2pawn_R_1che2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [1]  [1]  [1]  [0]  [2]  ]  = m_MT_R_1che1pao1ma2pawn_B_2che1pawn;
	funMat[MARR->a[0]  [2]  [1]  [0]  [2]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_2che1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [1]  [1]  [1]  [0]  [2]  ]  = m_MT_R_1che1pao1ma2pawn_B_1che2pao;
	funMat[MARR->a[0]  [2]  [1]  [0]  [2]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_1che2pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [1]  [1]  [1]  [1]  [1]  ]  = m_MT_R_1che1pao1ma2pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [2]  [1]  [1]  [1]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_1che1pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [1]  [1]  [1]  [2]  [0]  ]  = m_MT_R_1che1pao1ma2pawn_B_1che2ma;
	funMat[MARR->a[0]  [2]  [1]  [2]  [0]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_1che2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [1]  [1]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1che1pao1ma2pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [2]  [1]  [1]  [0]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_1che1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [1]  [2]  [0]  [2]  [0]  [0]  ]  = m_MT_R_1che2ma2pawn_B_2che1pawn;
	funMat[MARR->a[1]  [2]  [2]  [0]  [0]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma2pawn_R_2che1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [2]  [0]  [1]  [0]  [2]  ]  = m_MT_R_1che2ma2pawn_B_1che2pao;
	funMat[MARR->a[0]  [2]  [1]  [0]  [2]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma2pawn_R_1che2pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [2]  [0]  [1]  [1]  [1]  ]  = m_MT_R_1che2ma2pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [2]  [1]  [1]  [1]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma2pawn_R_1che1pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [2]  [0]  [1]  [2]  [0]  ]  = m_MT_R_1che2ma2pawn_B_1che2ma;
	funMat[MARR->a[0]  [2]  [1]  [2]  [0]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma2pawn_R_1che2ma; //---------

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [1]  [2]  [0]  [1]  [1]  [0]  ]  = m_MT_R_1che2ma2pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [2]  [1]  [1]  [0]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma2pawn_R_1che1ma1pawn; //---------

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [0]  [1]  [2]  [0]  [1]  ]  = m_MT_R_1che1pao3pawn_B_2che1pao;
	funMat[MARR->a[0]  [3]  [2]  [0]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_2che1pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [0]  [1]  [2]  [1]  [0]  ]  = m_MT_R_1che1pao3pawn_B_2che1ma;
	funMat[MARR->a[0]  [3]  [2]  [1]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_2che1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [0]  [1]  [2]  [0]  [0]  ]  = m_MT_R_1che1pao3pawn_B_2che1pawn;
	funMat[MARR->a[1]  [3]  [2]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_2che1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [0]  [1]  [1]  [0]  [2]  ]  = m_MT_R_1che1pao3pawn_B_1che2pao;
	funMat[MARR->a[0]  [3]  [1]  [0]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1che2pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [0]  [1]  [1]  [1]  [1]  ]  = m_MT_R_1che1pao3pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [3]  [1]  [1]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1che1pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [0]  [1]  [1]  [0]  [1]  ]  = m_MT_R_1che1pao3pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1che1pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [0]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1che1pao3pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [3]  [1]  [1]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1che1ma1pawn;
	
	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [1]  [0]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1che1pao3pawn_B_1che2pawn;
	funMat[MARR->a[2]  [3]  [1]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1che2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [0]  [1]  [0]  [1]  [2]  ]  = m_MT_R_1che1pao3pawn_B_2pao1ma;
	funMat[MARR->a[0]  [3]  [0]  [1]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_2pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [0]  [1]  [0]  [0]  [2]  ]  = m_MT_R_1che1pao3pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_2pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [0]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1che1pao3pawn_B_1pao2ma;
	funMat[MARR->a[0]  [3]  [0]  [2]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1pao2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [0]  [1]  [0]  [1]  [1]  ]  = m_MT_R_1che1pao3pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [1]  [0]  [1]  [0]  [0]  [1]  ]  = m_MT_R_1che1pao3pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [3]  [0]  [0]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [1]  [0]  [1]  [0]  [1]  [0]  ]  = m_MT_R_1che1pao3pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [1]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [3]  [1]  [0]  [1]  [0]  [0]  [0]  ]  = m_MT_R_1che1pao3pawn_B_3pawn;
	funMat[MARR->a[3]  [3]  [0]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [1]  [0]  [2]  [0]  [0]  ]  = m_MT_R_1che1ma3pawn_B_2che1pawn;
	funMat[MARR->a[1]  [3]  [2]  [0]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_2che1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [1]  [0]  [1]  [0]  [2]  ]  = m_MT_R_1che1ma3pawn_B_1che2pao;
	funMat[MARR->a[0]  [3]  [1]  [0]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1che2pao;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [1]  [0]  [1]  [1]  [1]  ]  = m_MT_R_1che1ma3pawn_B_1che1pao1ma;
	funMat[MARR->a[0]  [3]  [1]  [1]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1che1pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [1]  [0]  [1]  [0]  [1]  ]  = m_MT_R_1che1ma3pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1che1pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [1]  [0]  [1]  [1]  [0]  ]  = m_MT_R_1che1ma3pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [3]  [1]  [1]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1che1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [1]  [1]  [0]  [1]  [0]  [0]  ]  = m_MT_R_1che1ma3pawn_B_1che2pawn;
	funMat[MARR->a[2]  [3]  [1]  [0]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1che2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [1]  [0]  [0]  [1]  [2]  ]  = m_MT_R_1che1ma3pawn_B_2pao1ma;
	funMat[MARR->a[0]  [3]  [0]  [1]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_2pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [1]  [0]  [0]  [0]  [2]  ]  = m_MT_R_1che1ma3pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_2pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [1]  [0]  [0]  [2]  [1]  ]  = m_MT_R_1che1ma3pawn_B_1pao2ma;
	funMat[MARR->a[0]  [3]  [0]  [2]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1pao2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [1]  [0]  [0]  [1]  [1]  ]  = m_MT_R_1che1ma3pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [1]  [1]  [0]  [0]  [0]  [1]  ]  = m_MT_R_1che1ma3pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [3]  [0]  [0]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [1]  [1]  [0]  [0]  [1]  [0]  ]  = m_MT_R_1che1ma3pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [1]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [3]  [1]  [1]  [0]  [0]  [0]  [0]  ]  = m_MT_R_1che1ma3pawn_B_3pawn;
	funMat[MARR->a[3]  [3]  [0]  [0]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [1]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_R_1che4pawn_B_1che1pao1pawn;
	funMat[MARR->a[1]  [4]  [1]  [0]  [1]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1che1pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [1]  [0]  [0]  [1]  [1]  [0]  ]  = m_MT_R_1che4pawn_B_1che1ma1pawn;
	funMat[MARR->a[1]  [4]  [1]  [1]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1che1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [2]  [1]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_R_1che4pawn_B_1che2pawn;
	funMat[MARR->a[2]  [4]  [1]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1che2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [1]  [0]  [0]  [0]  [1]  [2]  ]  = m_MT_R_1che4pawn_B_2pao1ma;
	funMat[MARR->a[0]  [4]  [0]  [1]  [2]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_2pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [0]  [1]  [0]  [0]  [0]  [2]  [1]  ]  = m_MT_R_1che4pawn_B_1pao2ma;
	funMat[MARR->a[0]  [4]  [0]  [2]  [1]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1pao2ma;	

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [1]  [0]  [0]  [0]  [0]  [2]  ]  = m_MT_R_1che4pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [4]  [0]  [0]  [2]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_2pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [1]  [0]  [0]  [0]  [1]  [1]  ]  = m_MT_R_1che4pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [1]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [1]  [0]  [0]  [0]  [2]  [0]  ]  = m_MT_R_1che4pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [2]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_2ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [2]  [1]  [0]  [0]  [0]  [0]  [1]  ]  = m_MT_R_1che4pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [4]  [0]  [0]  [1]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [2]  [1]  [0]  [0]  [0]  [1]  [0]  ]  = m_MT_R_1che4pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [1]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [3]  [1]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_R_1che4pawn_B_3pawn;
	funMat[MARR->a[3]  [4]  [0]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[1]  [1]  [0]  [2]  [2]  [1]  [0]  [1]  ]  = m_MT_R_2pao2ma1pawn_B_1che1pao1pawn;  //0
	funMat[MARR->a[1]  [1]  [1]  [0]  [1]  [0]  [2]  [2]  ]  = m_MT_B_2pao2ma1pawn_R_1che1pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [0]  [1]  [2]  [1]  [0]  [1]  ]  = m_MT_R_2pao1ma2pawn_B_1che1pao1pawn;  //0
	funMat[MARR->a[1]  [2]  [1]  [0]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_1che1pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [0]  [1]  [2]  [1]  [1]  [0]  ]  = m_MT_R_2pao1ma2pawn_B_1che1ma1pawn; 
	funMat[MARR->a[1]  [2]  [1]  [1]  [0]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_1che1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [0]  [2]  [1]  [1]  [0]  [1]  ]  = m_MT_R_1pao2ma2pawn_B_1che1pao1pawn;  //0
	funMat[MARR->a[1]  [2]  [1]  [0]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma2pawn_R_1che1pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [0]  [2]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1pao2ma2pawn_B_1che1ma1pawn; 
	funMat[MARR->a[1]  [2]  [1]  [1]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma2pawn_R_1che1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [2]  [0]  [2]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao2ma2pawn_B_1che2pawn; 
	funMat[MARR->a[2]  [2]  [1]  [0]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma2pawn_R_1che2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_R_2pao1ma2pawn_B_2pao1ma;
	funMat[MARR->a[0]  [2]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_2pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [0]  [1]  [2]  [0]  [2]  [1]  ]  = m_MT_R_2pao1ma2pawn_B_1pao2ma;
	funMat[MARR->a[0]  [2]  [0]  [2]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_1pao2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [0]  [2]  [1]  [0]  [1]  [2]  ]  = m_MT_R_1pao2ma2pawn_B_2pao1ma;
	funMat[MARR->a[0]  [2]  [0]  [1]  [2]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma2pawn_R_2pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1pao2ma2pawn_B_1pao2ma;
	funMat[MARR->a[0]  [2]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma2pawn_R_1pao2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [0]  [2]  [1]  [0]  [0]  ]  = m_MT_R_2pao3pawn_B_1che2pawn;
	funMat[MARR->a[2]  [3]  [1]  [0]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_1che2pawn;
	
	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [0]  [2]  [0]  [1]  [2]  ]  = m_MT_R_2pao3pawn_B_2pao1ma;   //
	funMat[MARR->a[0]  [3]  [0]  [1]  [2]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_2pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [0]  [2]  [0]  [2]  [1]  ]  = m_MT_R_2pao3pawn_B_1pao2ma;   //
	funMat[MARR->a[0]  [3]  [0]  [2]  [1]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_1pao2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [0]  [2]  [0]  [0]  [2]  ]  = m_MT_R_2pao3pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [2]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_2pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [0]  [2]  [0]  [1]  [1]  ]  = m_MT_R_2pao3pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [1]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_1pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [0]  [2]  [0]  [2]  [0]  ]  = m_MT_R_2pao3pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [2]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_2ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [0]  [2]  [0]  [0]  [1]  ]  = m_MT_R_2pao3pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [3]  [0]  [0]  [1]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_1pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [0]  [2]  [0]  [1]  [0]  ]  = m_MT_R_2pao3pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [1]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [1]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao1ma3pawn_B_1che2pawn;
	funMat[MARR->a[2]  [3]  [1]  [0]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma3pawn_R_1che2pawn;
   
	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [1]  [1]  [0]  [1]  [2]  ]  = m_MT_R_1pao1ma3pawn_B_2pao1ma;   //
	funMat[MARR->a[0]  [3]  [0]  [1]  [2]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma3pawn_R_2pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [1]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1pao1ma3pawn_B_1pao2ma;   //
	funMat[MARR->a[0]  [3]  [0]  [2]  [1]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma3pawn_R_1pao2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [1]  [1]  [0]  [0]  [2]  ]  = m_MT_R_1pao1ma3pawn_B_2pao1pawn;  
	funMat[MARR->a[1]  [3]  [0]  [0]  [2]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma3pawn_R_2pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [1]  [1]  [0]  [2]  [0]  ]  = m_MT_R_1pao1ma3pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [2]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma3pawn_R_2ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [1]  [1]  [0]  [1]  [1]  ]  = m_MT_R_1pao1ma3pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [1]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma3pawn_R_1pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [1]  [1]  [0]  [0]  [1]  ]  = m_MT_R_1pao1ma3pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [3]  [0]  [0]  [1]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma3pawn_R_1pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [1]  [1]  [0]  [1]  [0]  ]  = m_MT_R_1pao1ma3pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [1]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma3pawn_R_1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [2]  [0]  [1]  [0]  [0]  ]  = m_MT_R_2ma3pawn_B_1che2pawn;
	funMat[MARR->a[2]  [3]  [1]  [0]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_1che2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [2]  [0]  [0]  [1]  [2]  ]  = m_MT_R_2ma3pawn_B_2pao1ma;   //
	funMat[MARR->a[0]  [3]  [0]  [1]  [2]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_2pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [0]  [2]  [0]  [0]  [2]  [1]  ]  = m_MT_R_2ma3pawn_B_1pao2ma;   //
	funMat[MARR->a[0]  [3]  [0]  [2]  [1]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_1pao2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [2]  [0]  [0]  [0]  [2]  ]  = m_MT_R_2ma3pawn_B_2pao1pawn;
	funMat[MARR->a[1]  [3]  [0]  [0]  [2]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_2pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [2]  [0]  [0]  [1]  [1]  ]  = m_MT_R_2ma3pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [1]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_1pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [2]  [0]  [0]  [2]  [0]  ]  = m_MT_R_2ma3pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [2]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_2ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [2]  [0]  [0]  [0]  [1]  ]  = m_MT_R_2ma3pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [3]  [0]  [0]  [1]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_1pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [2]  [0]  [0]  [1]  [0]  ]  = m_MT_R_2ma3pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [1]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [0]  [0]  [1]  [0]  [1]  [1]  ]  = m_MT_R_1pao4pawn_B_1pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [1]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_1pao1ma1pawn;	

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [0]  [0]  [1]  [0]  [2]  [0]  ]  = m_MT_R_1pao4pawn_B_2ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [2]  [0]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_2ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [2]  [0]  [0]  [1]  [0]  [0]  [1]  ]  = m_MT_R_1pao4pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [4]  [0]  [0]  [1]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_1pao2pawn;	

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [2]  [0]  [0]  [1]  [0]  [1]  [0]  ]  = m_MT_R_1pao4pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [1]  [0]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [3]  [0]  [0]  [1]  [0]  [0]  [0]  ]  = m_MT_R_1pao4pawn_B_3pawn;
	funMat[MARR->a[3]  [4]  [0]  [0]  [0]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [2]  [0]  [1]  [0]  [0]  [0]  [1]  ]  = m_MT_R_1ma4pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [4]  [0]  [0]  [1]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_1pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [2]  [0]  [1]  [0]  [0]  [1]  [0]  ]  = m_MT_R_1ma4pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [1]  [0]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [3]  [0]  [1]  [0]  [0]  [0]  [0]  ]  = m_MT_R_1ma4pawn_B_3pawn;
	funMat[MARR->a[3]  [4]  [0]  [0]  [0]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [2]  [0]  [0]  [0]  [0]  [0]  [1]  ]  = m_MT_R_5pawn_B_1pao2pawn;
	funMat[MARR->a[2]  [5]  [0]  [0]  [1]  [0]  [0]  [0]  ]  = m_MT_B_5pawn_R_1pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [2]  [0]  [0]  [0]  [0]  [1]  [0]  ]  = m_MT_R_5pawn_B_1ma2pawn;
	funMat[MARR->a[2]  [5]  [0]  [1]  [0]  [0]  [0]  [0]  ]  = m_MT_B_5pawn_R_1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [3]  [0]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_R_5pawn_B_3pawn;
	funMat[MARR->a[3]  [5]  [0]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_B_5pawn_R_3pawn;
	
	//************************************5 �� 4*********************************************************
	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [2]  [0]  [1]  [2]  [0]  [1]  ]  = m_MT_R_2che1pao2pawn_B_2che1pao1pawn; //
	funMat[MARR->a[1]  [2]  [2]  [0]  [1]  [2]  [0]  [1]  ]  = m_MT_B_2che1pao2pawn_R_2che1pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [2]  [0]  [0]  [1]  [1]  [1]  ]  = m_MT_R_2che3pawn_B_1che1pao1ma1pawn; //
	funMat[MARR->a[1]  [3]  [1]  [1]  [1]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_1che1pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [2]  [0]  [0]  [2]  [1]  [0]  ]  = m_MT_R_2che3pawn_B_2che1ma1pawn; //
	funMat[MARR->a[1]  [3]  [2]  [1]  [0]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_2che1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[1]  [1]  [1]  [1]  [2]  [1]  [0]  [2]  ]  = m_MT_R_1che2pao1ma1pawn_B_1che2pao1pawn;
	funMat[MARR->a[1]  [1]  [1]  [0]  [2]  [1]  [1]  [2]  ]  = m_MT_B_1che2pao1ma1pawn_R_1che2pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[1]  [1]  [1]  [1]  [2]  [2]  [1]  [0]  ]  = m_MT_R_1che2pao1ma1pawn_B_2che1ma1pawn;
	funMat[MARR->a[1]  [1]  [2]  [1]  [0]  [1]  [1]  [2]  ]  = m_MT_B_1che2pao1ma1pawn_R_2che1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[1]  [2]  [1]  [1]  [2]  [2]  [0]  [0]  ]  = m_MT_R_1che2pao1ma1pawn_B_2che2pawn;
	funMat[MARR->a[2]  [1]  [2]  [0]  [0]  [1]  [1]  [2]  ]  = m_MT_B_1che2pao1ma1pawn_R_2che2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[1]  [2]  [1]  [2]  [1]  [2]  [0]  [0]  ]  = m_MT_R_1che1pao2ma1pawn_B_2che2pawn; //
	funMat[MARR->a[2]  [1]  [2]  [0]  [0]  [1]  [2]  [1]  ]  = m_MT_B_1che1pao2ma1pawn_R_2che2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [2]  [1]  [0]  [2]  [2]  [0]  [0]  ]  = m_MT_R_1che2pao2pawn_B_2che2pawn;
	funMat[MARR->a[2]  [2]  [2]  [0]  [0]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao2pawn_R_2che2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ���� 
	funMat[MARR->a[2]  [0]  [1]  [0]  [2]  [1]  [1]  [2] ]  = m_MT_R_1che2pao2pawn_B_1che2pao1ma;
	funMat[MARR->a[0]  [2]  [1]  [1]  [2]  [1]  [0]  [2] ]  = m_MT_B_1che2pao2pawn_R_1che2pao1ma;	

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ���� 
	funMat[MARR->a[2]  [0]  [1]  [0]  [2]  [1]  [2]  [1] ]  = m_MT_R_1che2pao2pawn_B_1che1pao2ma;
	funMat[MARR->a[0]  [2]  [1]  [2]  [1]  [1]  [0]  [2] ]  = m_MT_B_1che2pao2pawn_R_1che1pao2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [1]  [0]  [2]  [1]  [1]  [1]  ]  = m_MT_R_1che2pao2pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [1]  [1]  [1]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao2pawn_R_1che1pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [1]  [0]  [2]  [1]  [0]  [2]  ]  = m_MT_R_1che2pao2pawn_B_1che2pao1pawn;
	funMat[MARR->a[1]  [2]  [1]  [0]  [2]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao2pawn_R_1che2pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [1]  [1]  [1]  [1]  [2]  ]  = m_MT_R_1che1pao1ma2pawn_B_1che2pao1ma;
	funMat[MARR->a[0]  [2]  [1]  [1]  [2]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_1che2pao1ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [0]  [1]  [1]  [1]  [1]  [2]  [1]  ]  = m_MT_R_1che1pao1ma2pawn_B_1che1pao2ma;
	funMat[MARR->a[0]  [2]  [1]  [2]  [1]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_1che1pao2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [1]  [1]  [1]  [1]  [0]  [2]  ]  = m_MT_R_1che1pao1ma2pawn_B_1che2pao1pawn;
	funMat[MARR->a[1]  [2]  [1]  [0]  [2]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_1che2pao1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [1]  [1]  [1]  [1]  [1]  [1]  ]  = m_MT_R_1che1pao1ma2pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [1]  [1]  [1]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_1che1pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [1]  [1]  [1]  [1]  [2]  [0]  ]  = m_MT_R_1che1pao1ma2pawn_B_1che2ma1pawn;
	funMat[MARR->a[1]  [2]  [1]  [2]  [0]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_1che2ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [2]  [1]  [1]  [1]  [1]  [0]  [1]  ]  = m_MT_R_1che1pao1ma2pawn_B_1che1pao2pawn;
	funMat[MARR->a[2]  [2]  [1]  [0]  [1]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_1che1pao2pawn;
	
	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [2]  [1]  [1]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1che1pao1ma2pawn_B_1che1ma2pawn;
	funMat[MARR->a[2]  [2]  [1]  [1]  [0]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_1che1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [1]  [2]  [0]  [1]  [1]  [1]  ]  = m_MT_R_1che2ma2pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [1]  [1]  [1]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma2pawn_R_1che1pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [2]  [1]  [2]  [0]  [1]  [1]  [0]  ]  = m_MT_R_1che2ma2pawn_B_1che1ma2pawn;
	funMat[MARR->a[2]  [2]  [1]  [1]  [0]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma2pawn_R_1che1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [1]  [0]  [0]  [2]  [2]  ]  = m_MT_R_1che1ma3pawn_B_2pao2ma; //
	funMat[MARR->a[0]  [3]  [0]  [2]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_2pao2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [0]  [1]  [1]  [1]  [1]  ]  = m_MT_R_1che1pao3pawn_B_1che1pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [1]  [1]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1che1pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [1]  [0]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1che1pao3pawn_B_1che1ma2pawn;
	funMat[MARR->a[2]  [3]  [1]  [1]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1che1ma2pawn;

    //           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [0]  [1]  [0]  [1]  [0]  [2]  [2]  ]  = m_MT_R_1che1pao3pawn_B_2pao2ma;
	funMat[MARR->a[0]  [3]  [0]  [2]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_2pao2ma;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [1]  [0]  [0]  [1]  [2]  ]  = m_MT_R_1che1ma3pawn_B_2pao1ma1pawn; //
	funMat[MARR->a[1]  [3]  [0]  [1]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_2pao1ma1pawn;

        //           ���  ����  �쳵  ����  ����  �ڳ�  ����   ���� 
	funMat[MARR->a[3]  [1]  [1]  [0]  [1]  [0]  [1]  [2]  ]  = m_MT_R_1che1pao3pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_2pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [1]  [1]  [0]  [1]  [0]  [1]  ]  = m_MT_R_1che1ma3pawn_B_1che1pao2pawn;
	funMat[MARR->a[2]  [3]  [1]  [0]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1che1pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [1]  [1]  [0]  [1]  [1]  [0]  ]  = m_MT_R_1che1ma3pawn_B_1che1ma2pawn;
	funMat[MARR->a[2]  [3]  [1]  [1]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1che1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [3]  [1]  [1]  [0]  [1]  [0]  [0]  ]  = m_MT_R_1che1ma3pawn_B_1che3pawn;
	funMat[MARR->a[3]  [3]  [1]  [0]  [0]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1che3pawn;

        //           ���  ����  �쳵  ����  ����  �ڳ�  ����   ���� 
	funMat[MARR->a[3]  [1]  [1]  [1]  [0]  [0]  [2]  [1]  ]  = m_MT_R_1che1ma3pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [2]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1pao2ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [1]  [0]  [1]  [2]  [0]  [0]  ]  = m_MT_R_1che1pao3pawn_B_2che2pawn;
	funMat[MARR->a[2]  [3]  [2]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_2che2pawn; //

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [0]  [1]  [1]  [0]  [2]  ]  = m_MT_R_1che1pao3pawn_B_1che2pao1pawn;
	funMat[MARR->a[1]  [3]  [1]  [0]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1che2pao1pawn; //

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [1]  [0]  [1]  [1]  [0]  [1]  ]  = m_MT_R_1che1pao3pawn_B_1che1pao2pawn;
	funMat[MARR->a[2]  [3]  [1]  [0]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1che1pao2pawn; //

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [3]  [1]  [0]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1che1pao3pawn_B_1che3pawn;
	funMat[MARR->a[3]  [3]  [1]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1che3pawn; //

    //           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [0]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1che1pao3pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [2]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1pao2ma1pawn; //

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [2]  [1]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_R_1che4pawn_B_1che1pao2pawn;    //1��4����1��1��2��
	funMat[MARR->a[2]  [4]  [1]  [0]  [1]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1che1pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [3]  [1]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_R_1che4pawn_B_1che3pawn;
	funMat[MARR->a[3]  [4]  [1]  [0]  [0]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1che3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [1]  [0]  [0]  [0]  [1]  [2]  ]  = m_MT_R_1che4pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [1]  [2]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_2pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [1]  [1]  [0]  [0]  [0]  [2]  [1]  ]  = m_MT_R_1che4pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [4]  [0]  [2]  [1]  [1]  [0]  [0]  ]  = m_MT_B_1che4pawn_R_1pao2ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[1]  [2]  [0]  [2]  [2]  [1]  [0]  [1]  ]  = m_MT_R_2pao2ma1pawn_B_1che1pao2pawn; 
	funMat[MARR->a[2]  [1]  [1]  [0]  [1]  [0]  [2]  [2]  ]  = m_MT_B_2pao2ma1pawn_R_1che1pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[1]  [2]  [0]  [2]  [2]  [1]  [1]  [0]  ]  = m_MT_R_2pao2ma1pawn_B_1che1ma2pawn; 
	funMat[MARR->a[2]  [1]  [1]  [1]  [0]  [0]  [2]  [2]  ]  = m_MT_B_2pao2ma1pawn_R_1che1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[1]  [2]  [0]  [1]  [2]  [1]  [0]  [1]  ]  = m_MT_R_2pao1ma2pawn_B_1che1pao2pawn;  //0
	funMat[MARR->a[2]  [1]  [1]  [0]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_1che1pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [2]  [0]  [1]  [2]  [1]  [1]  [0]  ]  = m_MT_R_2pao1ma2pawn_B_1che1ma2pawn; 
	funMat[MARR->a[2]  [2]  [1]  [1]  [0]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_1che1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [3]  [0]  [1]  [2]  [1]  [0]  [0]  ]  = m_MT_R_2pao1ma2pawn_B_1che3pawn; 
	funMat[MARR->a[3]  [2]  [1]  [0]  [0]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_1che3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [2]  [0]  [1]  [2]  [0]  [1]  [1]  ]  = m_MT_R_2pao1ma2pawn_B_1pao1ma2pawn; 
	funMat[MARR->a[2]  [2]  [0]  [1]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_1pao1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [2]  [0]  [2]  [1]  [1]  [0]  [1]  ]  = m_MT_R_1pao2ma2pawn_B_1che1pao2pawn;  //0
	funMat[MARR->a[2]  [2]  [1]  [0]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma2pawn_R_1che1pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [2]  [0]  [2]  [1]  [1]  [1]  [0]  ]  = m_MT_R_1pao2ma2pawn_B_1che1ma2pawn; 
	funMat[MARR->a[2]  [2]  [1]  [1]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma2pawn_R_1che1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	//funMat[MARR->a[2]  [3]  [0]  [2]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao2ma2pawn_B_1che3pawn; 
	//funMat[MARR->a[3]  [2]  [1]  [0]  [0]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma2pawn_R_1che3pawn;

	 //           ���  ����  �쳵  ����  ����  �ڳ�  ����  ������ 
	funMat[MARR->a[2]  [1]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_R_2pao1ma2pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_2pao1ma1pawn;

    //           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [0]  [1]  [2]  [0]  [2]  [1]  ]  = m_MT_R_2pao1ma2pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [2]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_1pao2ma1pawn;

    //           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [1]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1pao2ma2pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma2pawn_R_1pao2ma1pawn;

    //           ���  ����  �쳵  ���� ����   �ڳ�  ���� ���� ��
	funMat[MARR->a[2]  [1]  [0]  [2]  [1]  [0]  [1]  [2]  ]  = m_MT_R_1pao2ma2pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [2]  [0]  [1]  [2]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma2pawn_R_2pao1ma1pawn;

	//           ���  ����  �쳵  ���� ����   �ڳ�  ���� ���� ��
	funMat[MARR->a[2]  [2]  [0]  [2]  [1]  [0]  [1]  [1]  ]  = m_MT_R_1pao2ma2pawn_B_1pao1ma2pawn;
	funMat[MARR->a[2]  [2]  [0]  [1]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma2pawn_R_1pao1ma2pawn;

	//            ���  ����  �쳵 ����  ����  �ڳ�  ����  ���� �� 
	funMat[MARR->a[3]  [2]  [0]  [0]  [2]  [0]  [1]  [1]  ]  = m_MT_R_2pao3pawn_B_1pao1ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [1]  [1]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_1pao1ma2pawn;

	//            ���  ����  �쳵 ����  ����  �ڳ�  ����  ���� �� 
	funMat[MARR->a[3]  [2]  [0]  [0]  [2]  [0]  [0]  [2]  ]  = m_MT_R_2pao3pawn_B_2pao2pawn;
	funMat[MARR->a[2]  [3]  [0]  [0]  [2]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_2pao2pawn;

	//            ���  ����  �쳵 ����  ����  �ڳ�  ����  ���� �� 
	funMat[MARR->a[3]  [2]  [0]  [0]  [2]  [0]  [2]  [0]  ]  = m_MT_R_2pao3pawn_B_2ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [2]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_2ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [3]  [0]  [1]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1pao1ma3pawn_B_1che3pawn;
	funMat[MARR->a[3]  [3]  [1]  [0]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma3pawn_R_1che3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [1]  [1]  [0]  [0]  [2]  ]  = m_MT_R_1pao1ma3pawn_B_2pao2pawn;
	funMat[MARR->a[2]  [3]  [0]  [0]  [2]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma3pawn_R_2pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [1]  [1]  [0]  [1]  [1]  ]  = m_MT_R_1pao1ma3pawn_B_1pao1ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [1]  [1]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma3pawn_R_1pao1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [1]  [1]  [0]  [2]  [0]  ]  = m_MT_R_1pao1ma3pawn_B_2ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [2]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma3pawn_R_2ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [2]  [0]  [0]  [1]  [2]  ]  = m_MT_R_2ma3pawn_B_2pao1ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [1]  [2]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_2pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [0]  [2]  [0]  [0]  [2]  [1]  ]  = m_MT_R_2ma3pawn_B_1pao2ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [2]  [1]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_1pao2ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [2]  [0]  [0]  [0]  [2]  ]  = m_MT_R_2ma3pawn_B_2pao2pawn;
	funMat[MARR->a[2]  [3]  [0]  [0]  [2]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_2pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [2]  [0]  [0]  [1]  [1]  ]  = m_MT_R_2ma3pawn_B_1pao1ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [1]  [1]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_1pao1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [0]  [2]  [0]  [0]  [2]  [0]  ]  = m_MT_R_2ma3pawn_B_2ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [2]  [0]  [0]  [2]  [0]  ]  = m_MT_B_2ma3pawn_R_2ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [2]  [0]  [1]  [0]  [0]  [2]  [0]  ]  = m_MT_R_1ma4pawn_B_2ma2pawn;
	funMat[MARR->a[2]  [4]  [0]  [2]  [0]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_2ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [3]  [0]  [1]  [0]  [0]  [1]  [0]  ]  = m_MT_R_1ma4pawn_B_1ma3pawn;
	funMat[MARR->a[3]  [4]  [0]  [1]  [0]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_1ma3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [4]  [0]  [0]  [1]  [0]  [0]  [0]  ]  = m_MT_R_1pao4pawn_B_4pawn;
	funMat[MARR->a[4]  [4]  [0]  [0]  [0]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_4pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [4]  [0]  [1]  [0]  [0]  [0]  [0]  ]  = m_MT_R_1ma4pawn_B_4pawn;
	funMat[MARR->a[4]  [4]  [0]  [0]  [0]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_4pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [3]  [0]  [0]  [0]  [0]  [0]  [1]  ]  = m_MT_R_5pawn_B_1pao3pawn;
	funMat[MARR->a[3]  [5]  [0]  [0]  [1]  [0]  [0]  [0]  ]  = m_MT_B_5pawn_R_1pao3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [3]  [0]  [0]  [0]  [0]  [1]  [0]  ]  = m_MT_R_5pawn_B_1ma3pawn;
	funMat[MARR->a[3]  [5]  [0]  [1]  [0]  [0]  [0]  [0]  ]  = m_MT_B_5pawn_R_1ma3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [4]  [0]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_R_5pawn_B_4pawn;
	funMat[MARR->a[4]  [5]  [0]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_B_5pawn_R_4pawn;   
	
	//************************************5 �� 5*********************************************************
	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [2]  [0]  [0]  [1]  [2]  [1]  ]  = m_MT_R_2che3pawn_B_1che1pao2ma1pawn; //
	funMat[MARR->a[1]  [3]  [1]  [2]  [1]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_1che1pao2ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [2]  [0]  [0]  [1]  [1]  [2]  ]  = m_MT_R_2che3pawn_B_1che2pao1ma1pawn; //
	funMat[MARR->a[1]  [3]  [1]  [1]  [2]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_1che2pao1ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [2]  [0]  [0]  [1]  [0]  [2]  ]  = m_MT_R_2che3pawn_B_1che2pao2pawn; //
	funMat[MARR->a[2]  [3]  [1]  [0]  [2]  [2]  [0]  [0]  ]  = m_MT_B_2che3pawn_R_1che2pao2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[1]  [2]  [1]  [1]  [2]  [1]  [2]  [0]  ]  = m_MT_R_1che2pao1ma1pawn_B_1che2ma2pawn; //
	funMat[MARR->a[2]  [1]  [1]  [2]  [0]  [1]  [1]  [2]  ]  = m_MT_B_1che2pao1ma1pawn_R_1che2ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [2]  [1]  [0]  [2]  [1]  [1]  [1]  ]  = m_MT_R_1che2pao2pawn_B_1che1pao1ma2pawn; //
	funMat[MARR->a[2]  [2]  [1]  [1]  [1]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao2pawn_R_1che1pao1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [3]  [1]  [0]  [2]  [1]  [0]  [1]  ]  = m_MT_R_1che2pao2pawn_B_1che1pao3pawn; //
	funMat[MARR->a[3]  [2]  [1]  [0]  [1]  [1]  [0]  [2]  ]  = m_MT_B_1che2pao2pawn_R_1che1pao3pawn;

	
	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [2]  [1]  [1]  [1]  [1]  [2]  [0]  ]  = m_MT_R_1che1pao1ma2pawn_B_1che2ma2pawn; //
	funMat[MARR->a[2]  [2]  [1]  [2]  [0]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_1che2ma2pawn;
	
	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [3]  [1]  [1]  [1]  [1]  [0]  [1]  ]  = m_MT_R_1che1pao1ma2pawn_B_1che1pao3pawn; //
	funMat[MARR->a[3]  [2]  [1]  [0]  [1]  [1]  [1]  [1]  ]  = m_MT_B_1che1pao1ma2pawn_R_1che1pao3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [3]  [1]  [2]  [0]  [1]  [1]  [0]  ]  = m_MT_R_1che2ma2pawn_B_1che1ma3pawn;
	funMat[MARR->a[3]  [2]  [1]  [1]  [0]  [1]  [2]  [0]  ]  = m_MT_B_1che2ma2pawn_R_1che1ma3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [1]  [0]  [0]  [2]  [2]  ]  = m_MT_R_1che1ma3pawn_B_2pao2ma1pawn; //
	funMat[MARR->a[1]  [3]  [0]  [2]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_2pao2ma1pawn;

    //           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [1]  [1]  [0]  [1]  [0]  [2]  [2]  ]  = m_MT_R_1che1pao3pawn_B_2pao2ma1pawn;
	funMat[MARR->a[1]  [3]  [0]  [2]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_2pao2ma1pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [1]  [1]  [0]  [0]  [1]  [2]  ]  = m_MT_R_1che1ma3pawn_B_2pao1ma2pawn; //
	funMat[MARR->a[2]  [3]  [0]  [1]  [2]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_2pao1ma2pawn;

    //          ���  ����  �쳵  ����  ����  �ڳ�  ����   ���� 
	funMat[MARR->a[3]  [2]  [1]  [0]  [1]  [0]  [1]  [2]  ]  = m_MT_R_1che1pao3pawn_B_2pao1ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [1]  [2]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_2pao1ma2pawn;

    //           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [2]  [1]  [1]  [0]  [0]  [2]  [1]  ]  = m_MT_R_1che1ma3pawn_B_1pao2ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [2]  [1]  [1]  [1]  [0]  ]  = m_MT_B_1che1ma3pawn_R_1pao2ma2pawn;

	 //           ���  ����  �쳵  ����  ����  �ڳ�  ����  ������ 
	funMat[MARR->a[3]  [4]  [1]  [0]  [1]  [1]  [0]  [0]  ]  = m_MT_R_1che1pao3pawn_B_1che4pawn;
	funMat[MARR->a[4]  [3]  [1]  [0]  [0]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1che4pawn; //

     //           ���  ����  �쳵  ����  ����  �ڳ�  ����  ������ 
	funMat[MARR->a[3]  [2]  [1]  [0]  [1]  [0]  [2]  [1]  ]  = m_MT_R_1che1pao3pawn_B_1pao2ma2pawn;
	funMat[MARR->a[2]  [3]  [0]  [2]  [1]  [1]  [0]  [1]  ]  = m_MT_B_1che1pao3pawn_R_1pao2ma2pawn; //

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[1]  [2]  [0]  [2]  [2]  [0]  [1]  [2]  ]  = m_MT_R_2pao2ma1pawn_B_2pao1ma2pawn;
	funMat[MARR->a[2]  [1]  [0]  [1]  [2]  [0]  [2]  [2]  ]  = m_MT_B_2pao2ma1pawn_R_2pao1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[1]  [2]  [0]  [2]  [2]  [0]  [2]  [1]  ]  = m_MT_R_2pao2ma1pawn_B_1pao2ma2pawn;
	funMat[MARR->a[2]  [1]  [0]  [2]  [1]  [0]  [2]  [2]  ]  = m_MT_B_2pao2ma1pawn_R_1pao2ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [2]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_R_2pao1ma2pawn_B_2pao1ma2pawn;
	funMat[MARR->a[2]  [2]  [0]  [1]  [2]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_2pao1ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����   
	funMat[MARR->a[2]  [2]  [0]  [1]  [2]  [0]  [2]  [1]  ]  = m_MT_R_2pao1ma2pawn_B_1pao2ma2pawn;
	funMat[MARR->a[2]  [2]  [0]  [2]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_1pao2ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����   
	funMat[MARR->a[2]  [3]  [0]  [1]  [2]  [0]  [1]  [1]  ]  = m_MT_R_2pao1ma2pawn_B_1pao1ma3pawn;
	funMat[MARR->a[3]  [2]  [0]  [1]  [1]  [0]  [1]  [2]  ]  = m_MT_B_2pao1ma2pawn_R_1pao1ma3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [2]  [0]  [2]  [1]  [0]  [2]  [1]  ]  = m_MT_BR_1pao2ma2pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[2]  [3]  [0]  [2]  [1]  [0]  [1]  [1]  ]  = m_MT_R_1pao2ma2pawn_B_1pao1ma3pawn;
	funMat[MARR->a[3]  [2]  [0]  [1]  [1]  [0]  [2]  [1]  ]  = m_MT_B_1pao2ma2pawn_R_1pao1ma3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [3]  [0]  [1]  [1]  [0]  [0]  [2]  ]  = m_MT_R_1pao1ma3pawn_B_2pao3pawn;
	funMat[MARR->a[3]  [3]  [0]  [0]  [2]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma3pawn_R_2pao3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [3]  [0]  [0]  [2]  [0]  [2]  [0]  ]  = m_MT_R_2pao3pawn_B_2ma3pawn;
	funMat[MARR->a[3]  [3]  [0]  [2]  [0]  [0]  [0]  [2]  ]  = m_MT_B_2pao3pawn_R_2ma3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[3]  [3]  [0]  [1]  [1]  [0]  [2]  [0]  ]  = m_MT_R_1pao1ma3pawn_B_2ma3pawn;
	funMat[MARR->a[3]  [3]  [0]  [2]  [0]  [0]  [1]  [1]  ]  = m_MT_B_1pao1ma3pawn_R_2ma3pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [5]  [0]  [0]  [1]  [0]  [0]  [0]  ]  = m_MT_R_1pao4pawn_B_5pawn;
	funMat[MARR->a[5]  [4]  [0]  [0]  [0]  [0]  [0]  [1]  ]  = m_MT_B_1pao4pawn_R_5pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[4]  [5]  [0]  [1]  [0]  [0]  [0]  [0]  ]  = m_MT_R_1ma4pawn_B_5pawn;
	funMat[MARR->a[5]  [4]  [0]  [0]  [0]  [0]  [1]  [0]  ]  = m_MT_B_1ma4pawn_R_5pawn;

	//           ���  ���� �쳵 ���� ���� �ڳ� ���� ����  
	funMat[MARR->a[5]  [5]  [0]  [0]  [0]  [0]  [0]  [0]  ]  = m_MT_5pawn_TO_5pawn;

}