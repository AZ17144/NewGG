#include "chess.h"

#ifdef USE_STOCK_FISH_FILE
#else
 
#include "preGen.h"

bool board_is_incheck(const typePOS *POSITION, int white_to_move){

	Bitboard occ = POSITION->byWhiteBlack;
	int k;

	if(white_to_move){   //�콫�ǲ��Ǹ��ڷ�������
		k = RKpos();


		//�ǲ��Ǹ��Է��ĳ�, ��, ����, ���Է��Ľ�,��������.
		//if(m128_is_have_bit(m_and(m_or(board->byChessBB[BKING],board->byChessBB[BCHE]),
		if(m128_is_have_bit(m_and(POSITION->byChessBB[BCHE],
			rook_attacks_bb(k,occ)))) return TRUE;

		//3,���ӷ��ǲ��Ǹ��Է����ڽ���
		if(m128_is_have_bit(m_and(POSITION->byChessBB[BPAO],
			pao_eat_attacks_bb(k,occ)))) return TRUE;


		//4,���ӷ��ǲ��Ǹ��Է�������	
		if(m128_is_have_bit(m_and(POSITION->byChessBB[BMA],
			king_to_ma_attacks_bb(k,occ)))) return TRUE;

		//1,���ӷ��ǲ��Ǹ��Է��ı�����
		if(m128_is_have_bit(m_and(Attack_By_Bpawn_Bking[k],POSITION->byChessBB[BPAWN]))) 
			return TRUE;
	}
	else{ // side == BLACK
		k = BKpos();

		//�ǲ��Ǹ��Է��ĳ�, ��, ���� ,���Է��Ľ�,��������.
		if(m128_is_have_bit(m_and(POSITION->byChessBB[RCHE],
			rook_attacks_bb(k,occ)))) return TRUE;

		//3,���ӷ��ǲ��Ǹ��Է����ڽ���
		if(m128_is_have_bit(m_and(POSITION->byChessBB[RPAO],
			pao_eat_attacks_bb(k,occ)))) return TRUE;

		//4,���ӷ��ǲ��Ǹ��Է�������	
		if(m128_is_have_bit(m_and(POSITION->byChessBB[RMA],
			king_to_ma_attacks_bb(k,occ)))) return TRUE;

		//1,���ӷ��ǲ��Ǹ��Է��ı�����
		if(m128_is_have_bit(m_and(Attack_By_Rpawn_Rking[k],POSITION->byChessBB[RPAWN]))) 
			return TRUE;
	} 

	return FALSE;
}

#endif