#include "eval_total.h"
/*
//////////////////////////////////////////////////////////////////////////
/// ���ڵ��ڵ�����
template<Color Us>
Score eval_zhong_di_pao(Position& pos, EvalInfo& ei){

	Score bonus = SCORE_ZERO;
	Bitboard bzp = ei.ZhongDiPaoBB[Us];
	while(m_have_bit(bzp)){
		const Color Them = (Us == WHITE ? BLACK : WHITE);
		//const Square mk  = pos.king_square(Us);
		const Square yk  = pos.king_square(Them);
		const Piece delt = COLOR_BY_SIDE_ADD[Us];	
		//Bitboard occ = pos.occupied_squares();
		Square pao_sq = pop_1st_bit(bzp);

		// fen 2bak4/3ra4/4n2r1/pR1CCP2p/6b2/9/Pp6P/3R5/2nNA4/2c1KAB2 b - - 0 1
		// ����ڸ��Լ��ı������ˣ�Ҫ�ӷ�
		if(bit_is_set(ei.attacked_by(RPAWN + delt),pao_sq)){
			bonus += make_score(16,32);
		}

		//////////////////////////////////////////////////////////////////////////
		/// �������������
		if(StoX(pao_sq) == StoX(yk)){
			bonus  += make_score(8,32);
			ei.attPoint[Us] += 6;			//////////////////////////////////////////////////////////////////////////


			// ��Ҫ�ж�һ���ǲ����ܵ��Է��Ĺ���
			if(bit_is_set(ei.attacked_by(Them),pao_sq)){
				if(bit_is_set(ei.attacked_by(Us),pao_sq)){
				}
				else{
					ei.attPoint[Us] -= 3;
				}
			}
		} 
		//////////////////////////////////////////////////////////////////////////
		/// ����϶��ǵ���
		else{ 
			ei.attPoint[Us] += 8;   // ���ڼӹ�����	
			bonus  += make_score(32, -8);
			// ��Ҫ�ж�һ���ǲ����ܵ��Է��Ĺ���
			if(bit_is_set(ei.attacked_by(Them),pao_sq)){
				if(bit_is_set(ei.attacked_by(Us),pao_sq)){
				}
				else{
					ei.attPoint[Us] -= 3;
				}
			}
		}


		// �Ա��ϵ�һ�ӵĹ�����Ҫ�Ӵ�. 
		Bitboard bet = BetweenBB[pao_sq][yk];
		// ����г�������, ��Ҫ�ж��ǲ��ǻ������ڹ���side.
		// fen 1CRaka3/9/n8/p2Rp3p/2b3p2/3nr1Pr1/P7P/B8/4A4/3AK4 r
		if(have_bit(bet,pos.pieces(RCHE + delt))){
			Bitboard kingside = m_and(bet,ei.attacked_by(BKING - delt));
			// ��
			for(int i = 0; i < pos.piece_count(RCHE + delt); i++){
				Square s =  pos.piece_list(RCHE+ delt,i);
				Bitboard A = ei.CheAtt[Us][i];                                // �õ��ڵĹ���λ����
				if(have_bit(A,kingside)){
					if(!bit_is_set(bet,s)){
						ei.haveKillDanger[Us] = true; 
						continue;
					}
				}
			}		
			// ��
			for(int i = 0; i < pos.piece_count(RMA + delt); i++){
				//Square s =  pos.piece_list(RMA + delt,i);
				Bitboard A = ei.MaAtt[Us][i];                                // �õ��ڵĹ���λ����
				if(have_bit(A,kingside)){
					ei.haveKillDanger[Us] = true; 
					continue;
				}
			}			
			// ��
			if(have_bit(ei.attacked_by(RPAWN + delt),kingside)){
				ei.haveKillDanger[Us] = true; 
				continue;
			}
			
		}
	}

	return bonus;
}

*/