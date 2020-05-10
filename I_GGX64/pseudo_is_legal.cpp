#include "chess.h" 
#ifdef USE_STOCK_FISH_FILE
#else

#include "preGen.h"

bool pseudo_is_legal(int move, typePOS *POSITION){

	int from  = FROM(move);
	int   to  = TO(move);
	int piece = PB90(from);
	int k;
	//Bitboard iskxy;

	 Bitboard occ = m_and(POSITION->byWhiteBlack,ClearMaskBB[from]);   //
     occ          = m_or(occ,SetMaskBB[to]);

	//PIECE_SIDE
	// if(POS_SIDE){

	if(PIECE_SIDE(piece) == WHITE_TO_MOVE){
		
		if(piece == RKING){  // 1,�ߵ������ǽ�,
			
			// 1. �ǲ��Ǹ��Է��� ��,�� ����
			if(m128_is_have_bit(m_and(m_or(POSITION->byChessBB[BKING],POSITION->byChessBB[BCHE]),
				rook_attacks_bb(to,occ)))) return FALSE;            

			// 2. �ǲ��Ǹ��Է��� �� ����
			if(m128_is_have_bit(m_and(POSITION->byChessBB[BPAO],
				pao_eat_attacks_bb(to,occ)))) return FALSE;

            // 3. �ǲ��Ǹ��Է��� �� ����
			if(m128_is_have_bit(m_and(POSITION->byChessBB[BMA],
				king_to_ma_attacks_bb(to,occ)))) return FALSE;

			// 4, �ǲ��Ǹ��Է��� �� ����
			if(m128_is_have_bit(m_and(Attack_By_Bpawn_Bking[to],POSITION->byChessBB[BPAWN]))) 
			     return FALSE;
		}
		else{  // 2,�ߵ����Ӳ��ǽ�

			k = RKpos();
			
			// 2.1 �ж��ǲ����߶����Լ������ϵ���,���˺�,���Է��ĳ�,��,�� ����
			//iskxy = m_and(ChePseudoMask_FR[k],m_or(ChePseudoMask_FR[from],ChePseudoMask_FR[to]));  
			//if(m128_is_have_bit(iskxy)){
			if(bit_is_set(ChePseudoMask_FR[k],from) || bit_is_set(ChePseudoMask_FR[k],to)){
				
				// 2.1.1. �ǲ��Ǹ��Է��� ��,�� ����, ** �����������˶Է�����.ͬʱȥ�˶Է�������
				if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],
					m_or(POSITION->byChessBB[BKING],POSITION->byChessBB[BCHE])),
					rook_attacks_bb(k,occ)))) {
						return FALSE; 
				}
				
				// 2.1.2. �ǲ��Ǹ��Է��� �� ����
				if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION->byChessBB[BPAO]),
					pao_eat_attacks_bb(k,occ)))){  //board_display(board,"""");
					return FALSE;
				}

			}

			// 2.2 �ж��ǲ����߶��Ŀ��ܽ����������ϵ��� ** �����������˶Է�����.
			if( ABS(from - k) == 8 || ABS(from - k) == 10){
				// ������һ�� �� �Ľ���
				if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION->byChessBB[BMA]), //�����ȥ�˶Է�����.
					king_to_ma_attacks_bb(k,occ))))
					return FALSE;
			}
		}
	}
	else{
		if(piece == BKING){  // 1,�ߵ������ǽ�,
			
			// 1. �ǲ��Ǹ��Է��� ��,�� ����
			if(m128_is_have_bit(m_and(m_or(POSITION->byChessBB[RKING],POSITION->byChessBB[RCHE]),
				rook_attacks_bb(to,occ)))) return FALSE;            

			// 2. �ǲ��Ǹ��Է��� �� ����
			if(m128_is_have_bit(m_and(POSITION->byChessBB[RPAO],
				pao_eat_attacks_bb(to,occ)))) return FALSE;

            // 3. �ǲ��Ǹ��Է��� �� ����
			if(m128_is_have_bit(m_and(POSITION->byChessBB[RMA],
				king_to_ma_attacks_bb(to,occ)))) return FALSE;

			// 4, �ǲ��Ǹ��Է��� �� ����
			if(m128_is_have_bit(m_and(Attack_By_Bpawn_Bking[to],POSITION->byChessBB[RPAWN]))) 
			     return FALSE;
		}
		else{  // 2,�ߵ����Ӳ��ǽ�

			k = BKpos();
			
			// 2.1 �ж��ǲ����߶����Լ������ϵ���,���˺�,���Է��ĳ�,��,�� ����
			//iskxy = m_and(ChePseudoMask_FR[k],m_or(ChePseudoMask_FR[from],ChePseudoMask_FR[to]));  
			//if(m128_is_have_bit(iskxy)){
			if(bit_is_set(ChePseudoMask_FR[k],from) || bit_is_set(ChePseudoMask_FR[k],to)){
				
				// 2.1.1. �ǲ��Ǹ��Է��� ��,�� ����, ** �����������˶Է�����.ͬʱȥ�˶Է�������
				if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],
					m_or(POSITION->byChessBB[RKING],POSITION->byChessBB[RCHE])),
					rook_attacks_bb(k,occ)))) {
						return FALSE; 
				}
				
				// 2.1.2. �ǲ��Ǹ��Է��� �� ����
				if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION->byChessBB[RPAO]),
					pao_eat_attacks_bb(k,occ)))){
					return FALSE;
				}

			}

			// 2.2 �ж��ǲ����߶��Ŀ��ܽ����������ϵ��� ** �����������˶Է�����.
			if( ABS(from - k) == 8 || ABS(from - k) == 10){
				// ������һ�� �� �Ľ���
				if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION->byChessBB[RMA]),
					king_to_ma_attacks_bb(k,occ))))
					return FALSE;
			}
		}
	}  

    return TRUE;
}

#endif