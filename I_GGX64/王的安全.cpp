#include "eval_total.h"
#include "VMP.h"

//////////////////////////////////////////////////////////////////////////
/// ˫�����İ�ȫ��

template<Color Us>
Score eval_king_safe(Position& pos, EvalInfo& ei) {

	Bitboard att;
	Bitboard bside;
	Score bonus = SCORE_ZERO;
	const Color Them = (Us == WHITE ? BLACK : WHITE);

	Bitboard attThem = ei.attackKingBoard[Them];
	int attackCounter = (int)count_1s(attThem);

	const Square mk  = pos.king_square(Us);
	const Piece delt = COLOR_BY_SIDE_ADD[Us];	

	int att_che_num  = (int)count_1s(attThem,pos.pieces(BCHE  - delt));
	int att_ma_num   = (int)count_1s(attThem,pos.pieces(BMA   - delt));
	int att_pao_num  = (int)count_1s(attThem,pos.pieces(BPAO  - delt));
	int att_pawn_num = (int)count_1s(attThem,pos.pieces(BPAWN - delt));

	if (attackCounter <= 1 && (att_che_num + att_pao_num) == 0 ){
#ifdef CAN_OUT_EVAL_INFO
		ei.kingDanger[Us] = Value(0);
#endif		
		return bonus;
	}

	//�ҷ��г��������Է�û��
	//bool have3side = false; // �����ӹ����
	//////////////////////////////////////////////////////////////////////////	
	// fen 2ba5/5k3/n2ab4/6RNN/9/p1P6/9/4BA2B/3K3c1/r4A3 w - - 0 
	// ���ӹ�ߵ����. �г��ڽ����������ӹ��	attackCounter �������ұߵĹ�������
	
		//////////////////////////////////////////////////////////////////////////
		// ������ܵ���һ�£�

		// fen 3k1ab2/2N6/3ab4/p7p/9/P1p6/3r5/3C5/3CA4/1c1A1K3 w - - 0 1
		//������˽����ҽ����ܽ�ȥ���ڽ���һ������ж෽���ڣ�Ҫ�ӷ�
	
	//////////////////////////////////////////////////////////////////////////		
	// fen 2ba1k2C/4a4/4b4/p4r2p/6cR1/2N1n1B1P/P8/3AB4/4A4/4K4 w - - 0 1 ���BS̫����
	// ������Ĺ����ڱ������������
	ei.attPoint[Them] += 
		TOTAL_ATT_POINT[att_che_num][att_ma_num][att_pao_num][att_pawn_num][KposSafe[mk]];

	

	// ����Է�û�г��ˣ�Ҫ��һЩ
	// fen 2b2ab2/3ka4/4c4/p8/3P3P1/9/P3Cn1N1/8B/2p1A4/4KA3 w - - 0 1
	
	// ei.keypont[WHITE]
	// �ҷ��ķ��ط֡�
	//Bitboard danger = _mm_andnot_si128(ei.attacked_by(Us),ei.keypont[Them]);
	//ei.attPoint[Them] += (int)count_1s(danger) * 3;

	bool have3side = false;

	//////////////////////////////////////////////////////////////////////////
	// // �г��������ӽ�����
	if(att_che_num >= 1){	

	    //////////////////////////////////////////////////////////////////////////
	    // ���������ӹ�ߵ����
		// Ҫȥ�˵��߱�
		int ss;		
		if(Us == WHITE){ // Ҫȥ�˵��߱�  // PawnKingAttackZone
			bside = _mm_andnot_si128(_mm_andnot_si128(PawnKingAttackZone[mk],pos.pieces(BPAWN)),LowBB[0x04]);
		}
		else{
			bside = _mm_andnot_si128(_mm_andnot_si128(PawnKingAttackZone[mk],pos.pieces(RPAWN)), UpBB[0x05]);
		}
		// fen 2b1k1b2/9/9/5Pp2/8p/5RP2/1r1r1c2P/4BR3/1n2A4/2NAK1B2 w - - 0 1
		if (ei.pi->getExtraPawnInfo() & (Us == WHITE ? PEV_C_is_Bche_ATT : PEV_C_is_Rche_ATT)){
			ei.attPoint[Them] += 6;
		}


		// fen rC2kab2/4a4/2c1b1nc1/p1p1n1p1p/3RC4/2P6/P5r1P/N3B4/9/1RBAKA1N1 w - - 0 1 ����������ӹ����
		//att = m_and(bside,m_and(LeftBB[0x5],pos.pieces_of_color(Them))); // �м��Ҫ��Ҫ��
		//////////////////////////////////////////////////////////////////////////
		/// ���
		att = m_and(bside,m_and(LeftBB[0x4],pos.pieces_of_color(Them)));   // was 0x5  // ��ߣ���

		// ��Ҫ�����ҷ��ɹ����ĳ�,Ҳ�����ӹ����
		if(have_bit(att,pos.pieces(BCHE - delt))){
			ss = (int)count_1s(att);
			if(ss >= 3){ // pos.board_display("dd");				
				//���ֻ�г�2�ڣ������������ڣ�Ҫ��һЩ
				if(ss == 3){
					if(count_1s(att,pos.pieces(BPAO - delt)) == 2){ // 1��2��
						// fen 1CR1ck3/9/7r1/4Cn2p/2P6/2N5r/c8/B3B4/4A4/4KA3 b - - 0 1
						if(att_pao_num == 0){
							ei.attPoint[Them] -= 6;
						}
						else if(att_pao_num == 1){
							if(have_bit(m_and(att,FileBB_A[0x4]),pos.pieces(BPAO - delt))){
								ei.attPoint[Them] -= 4;
							}
						}
						// �������һ�ߣ� �ҳ����ڣ�һ��Ҫ���֡�
						Bitboard yc = m_and(att,pos.pieces(BCHE - delt));
						ASSERT(m_have_bit(yc));
						Square yche = pop_1st_bit_sq(yc);					
						if(abs(StoX(yche) - 0x4) >= 2){
							int cp_num = (int)count_1s(att,FileBB_A[StoX(yche)]);
							if(cp_num == 2){
								ei.attPoint[Them] -= 4;
							}
							else if(cp_num == 3){
								ei.attPoint[Them] -= 6;
							}
						} 

						if(have_bit(pos.pieces(BPAO - delt),RightBB[0x2])){
							ei.attPoint[Them] -= 8;
						}
					}
					// fen 4ka3/4a4/C3b4/p7p/2P3P2/9/3p4P/2N1R4/1c2K4/2r6 b - - 0 1
				}

				// ���Է��ж��ٳ��ڱ����� ����ȥ�˶Է������ߵĳ�
				// fen 1Cra1k3/4ac3/2P1b4/1R3N3/2n5p/P8/8P/9/2p1A4/4KAB2 b - - 0 1
				//att = m_and(bside,m_and(LeftBB[0x4],_mm_andnot_si128(ei.xray_bit[Them],pos.pieces(RCHE + delt))));

				Bitboard tside = m_and(bside,LeftBB[0x4]);
				//=====================
				// fen 2b1ka3/4a4/4b1r2/6NRR/p5r2/9/P3p4/4B4/4A4/2B1KA3 b - - 0 0
				if(have_bit(tside,pos.pieces(RCHE + delt))){
					ei.attPoint[Them] -= 2 * count_1s(tside,pos.pieces(RCHE + delt));
				}
				// ��������жԷ������ڱ�����Ҫ��һЩ���� fen 1C3ab2/2N1k1c2/3ab3n/p1R6/9/5p3/P3P1P2/B4A3/3K5/1r7 r
				if(have_bit(m_and(RankBB_A[StoY(mk)],tside),ei.attacked_by(RPAO + delt))){
					ei.attPoint[Them] -= 4;
				}
	
				// ����Է�û��һ�����ڣ�ҲҪ��att (û�г���������)
				if(!have_bit(tside,m_or(pos.pieces(RCHE + delt), pos.pieces(RPAO + delt)))){
					ei.attPoint[Them] += 3;
				}
				//====================
				ei.attPoint[Them] 
				+= SIDE_ATT_POINT[att_che_num][att_ma_num][att_pao_num][abs(0x3 - StoX(mk))];
				have3side = true;
			}
			// fen 2bakacC1/9/2P1b4/p1cNp4/7R1/9/P8/5K3/4A3r/3A5 b - - 0 1
			else if(ss >= 2){

				// �ж�����
				// fen 2b3R2/4aknR1/9/p1p6/6p2/8C/4P4/3A5/4K4/c1BA1rc2 b - - 0 1
				if(att_che_num == 2 && StoX(mk) < 0x4){
					ei.attPoint[Them] += 4;
					if(Us == WHITE ? StoY(mk) != 0x9 : StoY(mk) != 0x0){
						ei.attPoint[Them] += 4;
					}
				}

				if(have_bit(att,pos.pieces(BPAO - delt))){ // �г����ڽ�������һ���������������ڽ�����ҲҪ�ӷ�
					att = m_and(bside,m_and(RightBB[0x4],pos.pieces_of_color(Them)));
					ei.attPoint[Them] += (int)count_1s(att) * 2;
				}
				// �г����ڽ����ˡ�ҲҪ�ӷ�
				else if(have_bit(att,pos.pieces(BMA - delt))){
					att = m_and(bside,m_and(RightBB[0x4],pos.pieces_of_color(Them)));
					ei.attPoint[Them] += (int)count_1s(att) * 2;
					// ���������һ�ߣ���Ҫ�ӷ�
					if(StoX(mk) < 0x4){
						ei.attPoint[Them] += 4;
						// fen 3k1ab2/2N1a4/2nc5/p2Rp4/2b3p2/8p/P3P1P2/4B4/4A4/2BA1KCr1 b - - 0 1
						// ����Է�û�г��ڷ��أ�Ҫ�ӷ�
						//att = m_and(bside,m_and(LeftBB[0x4],pos.pieces_of_color(Them)));  // was 0x5
						if(!have_bit(pos.pieces(RCHE + delt),m_and(bside,LeftBB[0x4]))){
							ei.attPoint[Them] += 4;
						}
					}
				}
			}
		}
	
		//////////////////////////////////////////////////////////////////////////
		/// �ұ�
		att = m_and(bside,m_and(RightBB[0x4],pos.pieces_of_color(Them)));  // was RightBB[0x3]

		if(have_bit(att,pos.pieces(BCHE - delt))){
			ss = (int)count_1s(att);
			if(ss >= 3){  //pos.board_display("ss > 3 right"); print_bb(att);

				//���ֻ�г�2�ڣ������������ڣ�Ҫ��һЩ
				if(ss == 3 && count_1s(att,pos.pieces(BPAO - delt)) == 2){ // 1��2��
					// fen 1CR1ck3/9/7r1/4Cn2p/2P6/2N5r/c8/B3B4/4A4/4KA3 b - - 0 1
					if(att_pao_num == 0){
						ei.attPoint[Them] -= 6;
					}
					else if(att_pao_num == 1){
						if(have_bit(m_and(att,FileBB_A[0x4]),pos.pieces(BPAO - delt))){
							ei.attPoint[Them] -= 4;
						}
					}
					
					// �������һ�ߣ� �ҳ����ڣ�һ��Ҫ���֡� ����������һ��
					Bitboard yc = m_and(att,pos.pieces(BCHE - delt));
					ASSERT(m_have_bit(yc));
					Square yche = pop_1st_bit_sq(yc);					
					if(abs(StoX(yche) - 0x4) >= 2){
						int cp_num = (int)count_1s(att,FileBB_A[StoX(yche)]);
						if(cp_num == 2){
							ei.attPoint[Them] -= 4;
						}
						else if(cp_num == 3){
							ei.attPoint[Them] -= 6;
						}
					} 
					// fen 4ka1RC/9/4b4/5C3/1P2n1b2/9/3n5/B4A3/5K3/3A2r2 b - - 0 1 ������ܽ���Ҳ���ڽ����ˡ�
					// ���4��5�����Լ����ڣ���Ҫ����
					if(have_bit(pos.pieces(BPAO - delt),LeftBB[0x6])){
						ei.attPoint[Them] -= 8;
					}
				}

				//att = m_and(bside,m_and(RightBB[0x4],_mm_andnot_si128(ei.xray_bit[Them],pos.pieces(RCHE + delt))));
				//att = m_and(bside,m_and(RightBB[0x4],pos.pieces(RCHE + delt)));
				//ei.attPoint[Them] -= 4 * count_1s(att);  // �Է��г��ڷ��أ� �Է���һ�����ͼ�С4��

				Bitboard tside = m_and(bside,RightBB[0x4]);

				//=====================
				// fen 2b1ka3/4a4/4b1r2/6NRR/p5r2/9/P3p4/4B4/4A4/2B1KA3 b - - 0 0
				if(have_bit(tside,pos.pieces(RCHE + delt))){
					ei.attPoint[Them] -= 2 * count_1s(tside,pos.pieces(RCHE + delt));
				}
				// ��������жԷ������ڱ�����Ҫ��һЩ���� fen 1C3ab2/2N1k1c2/3ab3n/p1R6/9/5p3/P3P1P2/B4A3/3K5/1r7 r
				if(have_bit(m_and(RankBB_A[StoY(mk)],tside),ei.attacked_by(RPAO + delt))){
					ei.attPoint[Them] -= 4;
				}

				// ����Է�û��һ�����ڣ�ҲҪ��att (û�г���������)
				if(!have_bit(tside,m_or(pos.pieces(RCHE + delt), pos.pieces(RPAO + delt)))){
					ei.attPoint[Them] += 3;
				}
				//====================

				// fen 2bak3C/9/7R1/2n5N/1c4r2/P3pp3/2p5P/4B4/4A4/2BAK4 b - - 0 1
				ei.attPoint[Them] 
				+= SIDE_ATT_POINT[att_che_num][att_ma_num][att_pao_num][0x5 - StoX(mk)];
				have3side = true;

				// ����б�Ҫ��һЩ����Ϊ���ӣ���̫����
				//ei.attPoint[Them] -= (ei.att_pawn_num[Them] + 1)/2 * 3;

				//att = m_and(bside,m_and(LeftBB[0x4],pos.pieces_of_color(Them)));
				//ei.attPoint[Them] += (int)count_1s(att) * 2;
			}
			// fen 2bakacC1/9/2P1b4/p1cNp4/7R1/9/P8/5K3/4A3r/3A5 b - - 0 1
			else if(ss >= 2){

				// �ж�����
				// fen 2b3R2/4aknR1/9/p1p6/6p2/8C/4P4/3A5/4K4/c1BA1rc2 b - - 0 1
				if(att_che_num == 2 && StoX(mk) > 0x4){
					ei.attPoint[Them] += 4;
					if(Us == WHITE ? StoY(mk) != 0x9 : StoY(mk) != 0x0){
						ei.attPoint[Them] += 4;
					}
				}

				// �г����ڽ�������һ���������������ڽ�����ҲҪ�ӷ�
				if(have_bit(att,pos.pieces(BPAO - delt))){ 
					att = m_and(bside,m_and(LeftBB[0x4],pos.pieces_of_color(Them)));
					ei.attPoint[Them] += (int)count_1s(att) * 2;
				}
				// �г����ڽ����ˡ�ҲҪ�ӷ�
				else if(have_bit(att,pos.pieces(BMA - delt))){
					att = m_and(bside,m_and(LeftBB[0x4],pos.pieces_of_color(Them)));
					ei.attPoint[Them] += (int)count_1s(att) * 2;
					// ���������һ�ߣ���Ҫ�ӷ�
					if(StoX(mk) > 0x4){
						ei.attPoint[Them] += 4;
						// fen 3k1ab2/2N1a4/2nc5/p2Rp4/2b3p2/8p/P3P1P2/4B4/4A4/2BA1KCr1 b - - 0 1
						if(!have_bit(pos.pieces(RCHE + delt),m_and(bside,RightBB[0x4]))){
							ei.attPoint[Them] += 4;
						}
					}
				}
			}
			
		}	

		//////////////////////////////////////////////////////////////////////////	
		//int attBymat = pos.pMatinfo()->att_by_mat[Them];
		// �ٿ�һ�³����ɽ��ĵ�ķ�
		//int che_free = ChefreeCheckPointY[ei.cy[Them]] + ChefreeCheckPointX[ei.cx[Them]];	
		if(pos.piece_count(BCHE - delt) <= 1 && att_ma_num == 0 && att_pawn_num == 0){
			// fen 3ak4/4a4/9/3PR1N1p/9/9/P3P3P/4K1c2/2r6/6c2 w - - 0 1

			// fen 4kab2/5n3/b1Pa1r3/p2R4p/3N5/4C4/P3P3P/4B4/2c1K4/3A1A2c b - - 0 1
			if(att_pao_num == 2){
				// �������ң���Ҫ��att
				if(have_bit(LeftBB[0x4],pos.pieces(BPAO - delt)) && have_bit(RightBB[0x4],pos.pieces(BPAO - delt))){
					ei.attPoint[Them] -= 4;
					if(!have_bit(pos.pieces(BCHE - delt), Us == WHITE ? LowBB[0x5] : UpBB[0x4])){
						ei.attPoint[Them] -= 3;  // û�г����ӣ�Ҫ��
					}
				}
			}
			// fen 6b1C/9/4k4/p6Rp/2c1p1r2/8P/P8/2n1B4/9/2BAKA3 w - - 0 1
			else if(att_pao_num <= 1){
				ei.attPoint[Them] -= 4;
				if(pos.piece_count(BMA - delt) == 0){
					ei.attPoint[Them] -= 4;
				}
				if(pos.piece_count(BPAO - delt) <= 1){
					ei.attPoint[Them] -= 4;
				}
			}

			//// fen 2b1ka3/4a4/n3c4/9/8p/PN2N4/4P1R1P/3AB4/1C5r1/3AK3c w - - 0 1
		}	
	}
	else { //  fen 4k4/3Pa4/3a5/3cNn3/4C4/9/4p4/4B4/4AK3/3A5 w - - 0 1
		if (att_pao_num <= 1 && att_ma_num <= 1 && att_pawn_num <= 1) {
			ei.attPoint[Them] -= 8;
		}
	}

	//////////////////////////////////////////////////////////////////////////	
	// ������һ�¶Է��Ŀ���
	bonus -= eval_kong_zhong_di_pao<Them>(pos,ei);	
	//////////////////////////////////////////////////////////////////////////	
	// ����˨��������ʲô��
	bonus -= eval_king_up_one_string<Them>(pos,ei);
	//////////////////////////////////////////////////////////////////////////	
	//
	Score sv = SafetyTable[MIN_ZEOR_SAFE_POINT 	+ ei.attPoint[Them]];
	//////////////////////////////////////////////////////////////////////////	
	// �ټ��Ͻ���λ�õİ�ȫ��
	bonus -= sv;


#ifdef CAN_OUT_EVAL_INFO   
	ei.kingDanger[Us] = mg_value(sv);
#endif

	return bonus;
}

