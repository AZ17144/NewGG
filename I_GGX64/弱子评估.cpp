#include "eval_total.h"
#pragma warning(disable : 4530)  

const Score Che2_String_Pao[10] = {	   //�ҷ��ж���ʱ���ڱ��Է�ǣ�ƿ۷�
	Score(((116) << 16) + (196)),     //0,  ���� -- �������ɶ�
	Score(((108) << 16) + (186)),     //1,
	Score(((100) << 16) + (178)),     //2,
	Score((( 92) << 16) + (170)),     //3,
	Score((( 84) << 16) + (162)),     //4, 
	Score((( 72) << 16) + (154)),     //5,
	Score((( 64) << 16) + (146)),     //6, 
	Score((( 56) << 16) + (138)),     //7,
	Score((( 48) << 16) + (130)),     //8,
	Score((( 40) << 16) + (124)),     //9,	
};

const Score Che1_String_Pao[10] = {   //�ҷ���һ��ʱ���ڱ��Է�ǣ�ƿ۷�
	Score(((168) << 16) + (196)),     //0,  ���� -- �������ɶ�
	Score(((160) << 16) + (186)),     //1,
	Score(((152) << 16) + (178)),     //2,
	Score(((144) << 16) + (170)),     //3,
	Score(((136) << 16) + (162)),     //4, 
	Score(((128) << 16) + (154)),     //5,
	Score(((120) << 16) + (146)),     //6, 
	Score(((112) << 16) + (138)),     //7,
	Score(((104) << 16) + (130)),     //8,
	Score((( 96) << 16) + (124)),     //9,	
};

// fen 4kab2/4ac3/4b4/pR2p2P1/cn7/C8/2p1P4/4B1N1B/1r1N5/3AKA3 w - - 0 1
const Score Che2_String_Ma[10] = {		
	Score(((118) << 16) + (196)),     //0,  ���� -- �������ɶ�
	Score(((110) << 16) + (186)),     //1,
	Score(((102) << 16) + (178)),     //2,
	Score((( 94) << 16) + (170)),     //3,
	Score((( 86) << 16) + (162)),     //4, 
	Score((( 78) << 16) + (154)),     //5,
	Score((( 70) << 16) + (146)),     //6, 
	Score((( 62) << 16) + (138)),     //7,
	Score((( 54) << 16) + (130)),     //8,
	Score((( 46) << 16) + (124)),     //9,	
};

const Score Che1_String_Ma[10] = {
	Score(((168) << 16) + (196)),     //0,  ���� -- �������ɶ�
	Score(((160) << 16) + (186)),     //1,
	Score(((152) << 16) + (178)),     //2,
	Score(((144) << 16) + (170)),     //3,
	Score(((136) << 16) + (162)),     //4, 
	Score(((128) << 16) + (154)),     //5,
	Score(((120) << 16) + (146)),     //6, 
	Score(((112) << 16) + (138)),     //7,
	Score(((108) << 16) + (130)),     //8,
	Score(((100) << 16) + (124)),     //9,	
};



//////////////////////////////////////////////////////////////////////////
/// ����˫��������

template<Color Us>
Score eval_weak_piece(Position& pos, EvalInfo& ei){
	//const Color Them = (Us == WHITE ? BLACK : WHITE);
	const Piece delt = COLOR_BY_SIDE_ADD[Us];
	Score bonus = SCORE_ZERO;

	Bitboard myMaPao = m_or(pos.pieces(RMA + delt), pos.pieces(RPAO + delt));

	if (!have_bit(ei.attacked_by(RCHE + delt), myMaPao)){
		return SCORE_ZERO;
	}

	// �ȿ�һ���ҷ�����,���ǲ��Ǹ��Է��ڹ���, �� ��(��) ���� 
	Bitboard str = m_and(ei.attacked_by(RCHE + delt), myMaPao);

	Bitboard yourChePao = m_or(ei.attacked_by(BCHE - delt), ei.attacked_by(BPAO - delt));
	if (!have_bit(str, yourChePao)){
		return SCORE_ZERO;
	}

	// ��� str ���Է��ģ������ڣ���ֻ�г��ڲ���ǣ�����ӹ�����
	str = m_and(str, yourChePao);

	// ������Լ����࣬�ˣ�������Ҳ��Ҳ�����ܹ���������	((( ��Ҫ�����Լ����ڣ������ۣ�))
	str = _mm_andnot_si128(ei.pi->pawnshiXiang_attacks(Us), str);     //print_bb(str);
	////////////////////////////////////////////////////////////////////////
	// 2��ͬʱ���Է�2��ǣ���ˡ�
	if (pos.piece_count(RCHE + delt) == 2 
		&& count_1s(str, pos.pieces(RPAO + delt)) == 2
		&& !have_bit(pos.pieces(RCHE + delt), ei.attacked_by(Us))){  // �ҷ��ĳ�û�б���
		Bitboard str2pao2che = m_and(str, ei.attacked_by(BCHE - delt));
		if (count_1s(str2pao2che) == 2 ){
			if (have_bit(str2pao2che, ei.attacked_by(RPAO + delt))){  // 2���໥�ڱ����ţ�
				// �ٿ�һ����û�������������ڱ�����
				Bitboard bsxp_ma = m_or(ei.pi->pawnshiXiang_attacks(Us),
					ei.attacked_by(RMA + delt));
				if (!have_bit(bsxp_ma, str2pao2che)){
					bonus -= Score(((48) << 16) + (138));     //9,	
				}
			}
		}
	}
	////////////////////////////////////////////////////////////////////////		
	// ȥ���м��ܱ���������
	str = _mm_andnot_si128(m_or(ei.attacked_by(RMA + delt), ei.attacked_by(RPAO + delt)), str);    
	Square sqStr;
	while (pop_1st_bit_sq(str, sqStr)) {

		Piece  strPiece = pos.piece_on(sqStr);

		// fen 2ba2RN1/4a2r1/2C1k4/c2n5/5n2P/3p2p2/2P6/4B4/1C2A4/4KAB2 w - - 0 1 
		// ѹ�����ˡ�
		if (strPiece == (RMA + delt)){
			if (have_bit(CheYaMa[sqStr], pos.pieces(BCHE - delt))){
				bonus -= Score(((48) << 16) + (118));     //9,	
			}
		}

		// ���ҳ������Լ��ĳ������ҳ������Լ��ĳ�������
		Bitboard cheAtt = pos.Rook_attacks_bb(sqStr);
		Bitboard mc = m_and(pos.pieces(RCHE + delt), cheAtt);
		Square sqMche;
		while (pop_1st_bit_sq(mc, sqMche)) {
			// �ҵ��Է��ĳ�
			Bitboard mask = StoX(sqMche) == StoX(sqStr) ?
				FileBB_A[StoX(sqStr)] : RankBB_A[StoY(sqStr)];

			// ������б�����ҲҪȥ�ˡ�
			if (bit_is_set(ei.attacked_by(Us), sqMche)){
			}
			else if (have_bit(cheAtt, m_and(mask, pos.pieces(BCHE - delt)))){
				// ������ҷ��������ڸ��Է��ĳ�ǣ����
				// nbet ����Ҫ����Ҫ����һ���ҷ��������ɶȣ�Ҳ���Ǳ�ǣ�Ʒ��ĳ������ɶ�
				int nbet = (int)count_1s(mask, pos.Rook_attacks_bb(sqMche));
				// fen 1r1ak4/cC2anC2/1Rn1b4/p8/2p1p1b2/5N3/P1c1P4/2N1B4/9/3AKAB2 b - - 0 1	
				if (pos.piece_count(RCHE + delt) == 2){
					if (strPiece == (RMA + delt)){
						bonus -= Che2_String_Ma[nbet];
					}
					else{
						bonus -= Che2_String_Pao[nbet];
					}
				} // fen 2bakab2/9/2n5n/p1p1p1p1p/6c2/2P6/Prc1R3P/C1N1BC2N/4A4/2BAK4 b - - 0 1
				else{
					if (strPiece == (RMA + delt)){
						bonus -= Che1_String_Ma[nbet];
					}
					else{
						bonus -= Che1_String_Pao[nbet];
					}
				}
			}
			//////////////////////////////////////////////////////////////////////////
			// ��Ҫ�ж�һ���ǲ��Ǹ��Է�����ǣ���ˣ� mChe sqStr X ��
			if (strPiece == (RMA + delt) && bit_is_set(ei.attacked_by(BPAO - delt), sqStr)){
				Bitboard paoAtt = m_and(pos.Pao_Eat_bb(sqStr), pos.pieces(BPAO - delt));
				// Ҫȥ�� �� �� X
				paoAtt = _mm_andnot_si128(pos.Rook_attacks_bb(sqMche), paoAtt); // pos.board_display("");
				if (have_bit(paoAtt, mask)){
					bonus -= make_score(64, 168);
					// fen 3ak1b2/9/3ab4/p4np1p/9/PN4P1P/2C1Pnrc1/4B1NR1/4A4/2BAK4 w - - 0 1
				}
			}
		}
	}
	return bonus;
}