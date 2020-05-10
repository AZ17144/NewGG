#include "chess.h"

#ifdef USE_STOCK_FISH_FILE
#else
 
#include "preGen.h"

Bitboard sq_attacked_by_color(const typePOS *POSITION, int sq, int white_to_move){

	Bitboard occ;
	Bitboard att;
	//m128_from_2u64(att,0,0);
	//register Bitboard bb;
    occ = POSITION->byWhiteBlack;              // board_display(board,"");
	if(white_to_move){                         // �������

        //1,���,��˧                                                             //BB_or_BB(att,bb); ��һ����ʡȥ.
		att = m_and(Attack_By_Rpawn_Rking[sq],
			m_or(POSITION->byChessBB[RPAWN],POSITION->byChessBB[RKING]));       //�õ�����ɹ�����λ����
		
		//2,��
		att = m_or(att,
			m_and(rook_attacks_bb(sq,occ), POSITION->byChessBB[RCHE]));

		//3,��
		att = m_or(att,
			m_and(pao_eat_attacks_bb(sq,occ),POSITION->byChessBB[RPAO]));

		//4,��
		att = m_or(att,
			m_and(king_to_ma_attacks_bb(sq,occ),POSITION->byChessBB[RMA]));

		//5,��
		att = m_or(att,
			m_and(shi_attacks(sq),POSITION->byChessBB[RSHI]));

		//6,��
		att = m_or(att,
			m_and(xiang_attacks_bb(sq,occ),POSITION->byChessBB[RXIANG]));

		//att = m_or(m_and(Attack_By_Rpawn_Rking[sq],m_or(board->byChessBB[RPAWN],board->byChessBB[RKING])),
		//	m_or(


		//att = m_or(
		//	m_and(Attack_By_Rpawn_Rking[sq],m_or(board->byChessBB[RPAWN],board->byChessBB[RKING])),
		//	m_or(m_and(rook_attacks_bb(sq,occ), board->byChessBB[RCHE]),
		//	m_or(m_and(pao_eat_attacks_bb(sq,occ),board->byChessBB[RPAO]),
		//	m_or(m_and(king_to_ma_attacks_bb(sq,occ),board->byChessBB[RMA]),
		//	m_or(m_and(shi_attacks(sq),board->byChessBB[RSHI]),
		//	xiang_attacks_bb(sq,occ),board->byChessBB[RXIANG])))));



		       
	}
	else{

		 //1,����,�ڽ�                                                             //BB_or_BB(att,bb); ��һ����ʡȥ.
		att = m_and(Attack_By_Bpawn_Bking[sq],
			m_or(POSITION->byChessBB[BPAWN],POSITION->byChessBB[BKING]));       //�õ�����ɹ�����λ����

		//2,��
		att = m_or(att,
			m_and(rook_attacks_bb(sq,occ), POSITION->byChessBB[BCHE]));

		//3,��
		att = m_or(att,
			m_and(pao_eat_attacks_bb(sq,occ),POSITION->byChessBB[BPAO]));

		//4,��
		att = m_or(att,
			m_and(king_to_ma_attacks_bb(sq,occ),POSITION->byChessBB[BMA]));	

		//5,��
		att = m_or(att,
			m_and(shi_attacks(sq),POSITION->byChessBB[BSHI]));

		//6,��
		att = m_or(att,
			m_and(xiang_attacks_bb(sq,occ),POSITION->byChessBB[BXIANG]));
	}

	return att;
}

#endif