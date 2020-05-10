
#include "chess.h"

//extern void AttBy_White_PaoMaPawn(typePOS*);
//extern void AttBy_Black_PaoMaPawn(typePOS*);
//
//extern void AttBy_WhitePao_MaPawnShiXiang(typePOS*);
//extern void AttBy_BlackPao_MaPawnShiXiang(typePOS*);

// �õ��췽��sq�Ĺ�������
int GetWhiteAtt_SQcount_CheMaPaoPawn(const typePOS *POSITION, EvalInfo *ei, int sq){

	int num = 0;
	for(int i = 0; i < RChe_num(); i++){
		if(bit_is_set(ei->CheAtt[WHITE][i],sq)){
			num++;
		}
	}
	for(int i = 0; i < RMa_num(); i++){
		if(bit_is_set(ei->MaAtt[WHITE][i],sq)){
			num++;
		}
	}
	for(int i = 0; i < RPao_num(); i++){	
		if(bit_is_set(ei->PaoAtt[WHITE][i],sq)){
			num++;
		}
	}	
	//if(bit_is_set(ei->RpawnAtt,sq)){
	//	num++;
	//}
	return num;
}
// �õ��ڷ���sq�Ĺ�������
int GetBlackAtt_SQcount_CheMaPaoPawn(const typePOS *POSITION, EvalInfo *ei, int sq){

	int num = 0;
	for(int i = 0; i < BChe_num(); i++){
		if(bit_is_set(ei->CheAtt[BLACK][i],sq)){
			num++;
		}
	}
	for(int i = 0; i < BMa_num(); i++){
		if(bit_is_set(ei->MaAtt[BLACK][i],sq)){
			num++;
		}
	}
	for(int i = 0; i < BPao_num(); i++){	
		if(bit_is_set(ei->PaoAtt[BLACK][i],sq)){
			num++;
		}
	}	
	//if(bit_is_set(ei->BpawnAtt,sq)){
	//	num++;
	//}
	return num;
}