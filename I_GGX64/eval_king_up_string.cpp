#include "eval_total.h"


///////////////////////////////////////////////////////////////////////////
/// �������һ�����˱�ǣ����, ���� ������, ����˨, ... �����췽�����ڷ�����
template<Color Us>
Score eval_king_up_one_string(Position& pos, EvalInfo& ei){

	const Color Them = (Us == WHITE ? BLACK : WHITE);	
	const Square yk  = pos.king_square(Them);	
	Score bonus = SCORE_ZERO;

	Square sq1 = Us == WHITE? Square(0x0d):Square(0x4c);
	
	// �Է�����������ӱ�ǣ����. 
	if(bit_is_set(ei.xray_bit[Us],sq1) 
		&& (Us == WHITE ? yk == Square(0x04) : Square(yk == 0x55))){		

		const Piece delt = COLOR_BY_SIDE_ADD[Us];
		Bitboard  occ = pos.occupied_squares();
		const Square mk  = pos.king_square(Us);

		Bitboard bm = m_and(pos.Pao_Eat_bb(yk), m_and(occ,FileBB_A[0x4]));
		Square sq2 = pop_1st_bit_sq(bm);

		Piece Up1Chess = pos.piece_on(sq1);
		Piece Up2Chess = pos.piece_on(sq2);

		ei.attPoint[Us] += 3;

		bool isMPao = false;  // �ǲ��ǶԷ�������ǣ��. 
		if(bit_is_set(ei.xray_bit[Us],sq2)){
			// fen 1rbnkab2/4a4/3cc4/pCP3R2/8p/4C4/P3P1P1n/2N1B4/4A4/3K1AB2 b - - 0 1
            // ����Ҫ��һЩ����
			ei.attPoint[Us] += 6;
			bonus += make_score(16, 32);  // �ټ�һЩ��
			isMPao = true;
		}

		// fen 2bak4/3ra4/4n2r1/pR1CCP2p/6b2/9/Pp6P/3R5/2nNA4/2c1KAB2 b - - 0 1
		// �� �� (��,��  ��)
		if(false){			
		}// ���湲���ֿ���.
		else if(Up1Chess == (BSHI - delt)){	 // �� �� sq2 sq3 �п���������˨.
			if(isMPao){
				if(pos.piece_on(yk - 1) == (BSHI - delt) || pos.piece_on(yk + 1) == (BSHI - delt)){
					if(Up2Chess == (BMA - delt) || Up2Chess == (BPAO - delt)){ // fen 2b2ab2/3ka4/4c4/p8/3P3P1/9/P3Cn1N1/8B/2p1A4/4KA3 w - - 0 1 ���RS too high
						bonus += make_score(16,32);
						ei.attPoint[Us] += 4;
					}
				}
			}
		} // fen r1bakab2/4n3r/1cn4c1/p1p1p1p1p/9/4C4/P1P1P1P1P/2N4C1/9/R1BAKABNR w - -
		else if(Up1Chess == (BMA - delt)){  // �� �� sq2 sq3 
			// �� �� sq2 �� 
			if(isMPao){
				// ��������������
				if(pos.piece_on(yk - 1) == (BSHI - delt) && pos.piece_on(yk + 1) == (BSHI - delt)){
					// ��������ҷ����Ĵ���,��Ҫ����
					if(Up2Chess == (BMA - delt) || Up2Chess == (BPAO - delt)){
						bonus  +=  make_score(96, 196);
					} // fen fen 3aka3/4n4/bc2b2c1/p3C1P1p/2nC5/2B6/3NP3P/9/9/2BAKA3 w - - 0 1
					bonus  += make_score(128,376);
					ei.attPoint[Us] += 20;
					// fen 3a5/2P1a4/b2kc4/9/9/9/3r5/4B4/4N4/R2AKAB2 b - - 0 1
					// fen 3aka3/4n2R1/1c2b1c1b/3CC3p/4R4/6P2/2r2r2P/4B4/9/2BAKA3 w - - 0 1
					// �ټ�һЩ�������ӵ�att fen 1r1akaR2/4n4/4b4/p3C3C/5P3/2p6/P3P3P/4B1c2/4A2r1/2BAK4 w - - 0 1
					ei.attPoint[Us] += (int)count_1s(pos.pieces_of_color(Us), Us == WHITE? UpBB[0x5] : LowBB[0x4]) * 3;
				}
				// ҲҪ��һЩ����
				else{
					if(Up2Chess == (BMA - delt) || Up2Chess == (BPAO - delt)){
						bonus  += make_score(16, 32);
					}
					bonus  += make_score(32,96);
					ei.attPoint[Us] += 6;
				}
			}
			// �� �� ��
			else if(Up2Chess == (RCHE + delt)){ 
				// ��������������
				if(pos.piece_on(yk - 1) == (BSHI - delt) && pos.piece_on(yk + 1) == (BSHI - delt)
					&& pos.piece_count(BXIANG - delt) == 0){
						bonus  += make_score(32,378);
						ei.attPoint[Us] += 10; // fen 3aka3/4nR3/4R4/7rp/4P4/2B6/6p1P/1c7/3rA4/2B1KA1N1 w - - 0 1
						ei.attPoint[Us] += (int)count_1s(pos.pieces_of_color(Us), Us == WHITE? UpBB[0x5] : LowBB[0x4]);
				}
				// ҲҪ��һЩ����
				else{
					bonus  += make_score(32,96);
					ei.attPoint[Us] += 3;
				}
			}
			// �� �� ��
			else if(Up2Chess == (RKING + delt)){
				bonus  += make_score(16,64);
				ei.attPoint[Us] += 3;
			}
		}
		else if(Up1Chess == (BPAO - delt)){  // �� �� sq2 sq3 
			// �� �� ��
			if(Up2Chess == (RCHE + delt)){
				// ��������������
				if(pos.piece_on(yk - 1) == (BSHI - delt) && pos.piece_on(yk + 1) == (BSHI - delt)
					&& pos.piece_count(BXIANG - delt) == 0){
						bonus  += make_score(48,128);
						ei.attPoint[Us] += 12;
				}
				// ҲҪ��һЩ����
				else{
					bonus  += make_score(16,80);
					ei.attPoint[Us] += 3;
				}
			}
			if(Up2Chess == (RKING + delt)){
				bonus  += make_score(0,64);
				ei.attPoint[Us] += 3;
			}
		}
		else if(Up1Chess == (BCHE - delt)){  // �� �� sq2 sq3 
			if(isMPao){
				// �����������ĳ�
				if(pos.piece_on(yk - 1) == (BSHI - delt) && pos.piece_on(yk + 1) == (BSHI - delt)){
					// ��������ҷ����Ĵ���,��Ҫ����
					if(Up2Chess == (BMA - delt) || Up2Chess == (BPAO - delt)){
						bonus  += make_score(96, 196);
					}
					bonus  += make_score(128,256);
					ei.attPoint[Us] += 28;
				}
				// ҲҪ��һЩ����
				else{
					if(Up2Chess == (BMA - delt) || Up2Chess == (BPAO - delt)){
						bonus  += make_score(64, 96);
					}
					bonus  += make_score(32,96);
					ei.attPoint[Us] += 4;
				}
			}
		}

		// ���������ǣ���ˣ�ҲҪ�ӽ���
		if(have_bit(ei.xray_bit[Us],RankBB_A[StoY(yk)])){
			ei.attPoint[Us] += 4; // fen 1Crak1b2/1R2a1r2/9/9/P3R4/9/7pc/9/3KA4/5A3 b - - 0 1
		}

		// �ٿ�һ����·�Ĺ���
		//////////////////////////////////////////////////////////////////////////					  
		// 1. �ҷ����ܲ��ܹ������Է����ı���
		for(int i = 0; i < pos.piece_count(RCHE + delt); i++){
			Square s =  pos.piece_list(RCHE + delt,i);	

			if(StoX(s) == 0x4) continue;

			Bitboard A = pos.Rook_attacks_bb(s);	

			//Us == WHITE ?
			//	att = m_and(att,m_or(_mm_load_si128((__m128i*)Rank0BB),  // ����+���Ļ򹥻�λ��
			//	m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),UpBB[3])))
			//	: att = m_and(att,m_or(_mm_load_si128((__m128i*)Rank9BB),
			//	m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),LowBB[6])));
			Bitboard att;
			Us == WHITE ? att = m_and(A,UpBB[03]) : att = m_and(A,LowBB[0x6]);

			// ��������ܹ���
			if(!m_have_bit(att) && (Us == WHITE? StoY(s) >= 0x5 : StoY(s) <= 0x4)){
				continue;
			}

			// ����һ��д? 
			Square mside = yk - 1;
			Square oside = yk + 1;

			// ���Ķ��ߵ���Ϣ
			if(StoX(s) < 0x4){
				att = m_and(LeftBB[0x4],att);
			}
			else if(StoX(s) > 0x4){
				mside = yk + 1;
				oside = yk - 1;
				att = m_and(RightBB[0x4],att);
			}

			// ���������˨.
			if(pos.piece_on(oside) == (BSHI - delt)){

				ei.attPoint[Us] += 4; // fen 3ak2r1/4a4/4b3b/4C1p1p/2p6/6P2/1pPnPR2P/8B/9/1N3K3 w - - 0 1

				if(pos.piece_count(BCHE - delt) <= 1){
					ei.attPoint[Us] += 3;
					if(pos.piece_count(BMA - delt) == 0){
						ei.attPoint[Us] += 2;
					}
				}

				// fen 2bak2r1/4a4/4b4/2pPC3p/6p2/2P6/P4R2P/5K3/8c/2B2A3 b - - 0 1
				if(StoX(s) == StoX(mk) && bit_is_set(A,mk)){
					ei.attPoint[Us] += 4;
					bonus += make_score(16,96);
				}

				// fen 2baka1r1/4n4/4b4/pc2C3p/3P5/4P4/P4R2P/4BK3/4A4/9 b - - 0 1
				if(Up1Chess == (BMA - delt)){
					bonus += make_score(16,96);
				}

				if(isMPao){
					bonus  += make_score(16,128);
					ei.attPoint[Us] += 3;
					// ����Է�û�������ڱ�����������һ����,Ҫ�ӷ�
					if(!bit_is_set(ei.attacked_by(Them),mside) && pos.piece_on(mside) == EMPTY){
						// fen 2bak4/4a4/2c1b1n2/p3CR3/6p2/2Pr5/4P4/C3B1N2/1c2K4/2BA1A3 w - - 0 1
						bonus  += make_score(16,48);
					}
					// fen 2r1kab2/4a3n/4bc3/6P1p/R2NC4/1p7/P3P3P/2C6/4A4/1c2K1B2 w - - 0 1
					//����ǶԷ��ĳ��ڵ���,�����Ǹ����,��Ҫ�۷�.
					if(have_bit(pos.pieces(BCHE - delt), Us == WHITE? RankBB_A[0x0] : RankBB_A[0x9])){
					    //if(have_bit(ei.attackKingCheCan[Them],pos.pieces(BCHE - delt))){
						bonus  += make_score(16,128);
					}

					// fen 1nbak4/1N2a4/1c2b1nC1/1C2p1N1p/5r3/6P2/P2pc2RP/4B4/4A4/2BAK4 w - - 0 1
					//�������ڱ����ҷ�������
					//if(have_bit(ei.attacked_by(Us),m_and(ei.ZhongDiPaoBB[Us],FileBB_A[0x04]))){
					//	bonus  += make_score(8,64);
					//}
				}
				else{
					bonus  += make_score(8,48);
					ei.attPoint[Us] += 3;
					// ����Է�û�������ڱ�����������һ����,Ҫ�ӷ�
					if(!bit_is_set(ei.attacked_by(Them),mside) && pos.piece_on(mside) == EMPTY){
						// fen 2bak4/4a4/2c1b1n2/p3CR3/6p2/2Pr5/4P4/C3B1N2/1c2K4/2BA1A3 w - - 0 1
						bonus  += make_score(16,32);
					}
					// fen 2r1kab2/4a3n/4bc3/6P1p/R2NC4/1p7/P3P3P/2C6/4A4/1c2K1B2 w - - 0 1
					//����ǶԷ��ĳ��ڵ���,�����Ǹ����,��Ҫ�۷�.
					//if(have_bit(ei.attackKingCheCan[Them],pos.pieces(BCHE - delt))){
					//	bonus  += make_score(6,32);
					//}
				}
			}
			else if(pos.piece_on(mside) == EMPTY){
				bonus  += make_score(8,64);
				ei.attPoint[Us] += 4;

				// ����Է�û�������ڱ�����������һ����,Ҫ�ӷ�
				if(!bit_is_set(ei.attacked_by(Them),mside)){
					// fen 2bak4/4a4/2c1b1n2/p3CR3/6p2/2Pr5/4P4/C3B1N2/1c2K4/2BA1A3 w - - 0 1
					bonus  += make_score(16,48);
				}
			}
			else{ // Ҫ��һ���ǲ����ܹ����� mside
				if(bit_is_set(att,mside)){
					bonus  += make_score(4,32);
					ei.attPoint[Us] += 3;
				}
			}
			// fen 2bakc1R1/4a4/n1c1b4/N1prC3p/P8/2P3r2/4P1n1P/3C2N2/4A4/1RBAK4 b - - 0 1
			/// 5. �Է������ڷ���,ҲҪ�۷�
			// �Է������ڷ���
			// fen 2bk2b2/4a4/3a5/8p/1P2RN3/P4r2P/4c1rn1/4B2R1/4A4/2BAKC3 w - - 0 1			
			if(bit_is_set(ei.attacked_by(BPAO - delt),mside) || pos.piece_on(mside) == (BPAO- delt)){
				ei.attPoint[Us] -= 6;
			}
			//// ����������ڹ����ҷ�������
			//if(have_bit(ei.attacked_by(Them),m_and(ei.ZhongDiPaoBB[Us],FileBB_A[0x04]))){
			//	ei.attPoint[Us] -= 3;
			//}
		} // che_end

		//////////////////////////////////////////////////////////////////////////
		// 2 ��һ�±�
		//Bitboard tbp = m_and(pos.pieces(RPAWN + delt),_mm_load_si128((__m128i*)TiMenBit_Pawn));
		//// ��һ��,�ǲ�����һ������.
		//if(m_have_bit(tbp)){  
		//	if(pos.piece_on(yk + 1) == (BSHI -delt)){
		//		if(have_bit(tbp,LeftBB[0x4])){
		//			bonus  += make_score(8,64);
		//			ei.attPoint[Us] += 3;
		//		}
		//		else{
		//			bonus  += make_score(4,32);
		//			ei.attPoint[Us] += 2;
		//		}
		//	}
		//	if (pos.piece_on(yk - 1) == (BSHI -delt)){
		//		if(have_bit(tbp,RightBB[0x4])){
		//			bonus  += make_score(8,64);
		//			ei.attPoint[Us] += 3;
		//		}
		//		else{
		//			bonus  += make_score(4,32);
		//			ei.attPoint[Us] += 2;
		//		}
		//	}

		//	if(Up1Chess == (BMA - delt)){
		//		bonus += make_score(16,64);
		//	}
		//}

		int pawnNum = (int)count_1s(ei.attackKingBoard[Us],pos.pieces(RPAWN + delt));
		ei.attPoint[Us] += pawnNum * 4;

		//////////////////////////////////////////////////////////////////////////
		/// 4. ��
		int maNum = (int)count_1s(ei.attackKingBoard[Us],pos.pieces(RMA + delt));
		ei.attPoint[Us] += maNum * 3;
		bonus += make_score(maNum * 16, maNum * 32);
		//for(int i = 0; i < pos.piece_count(RMA + delt); i++){
		//	Square s =  pos.piece_list(RMA + delt,i);
		//	// ���ڼ���ҲҪ����
		//	if(Us == WHITE? StoY(s) >= 0x5 : StoY(s) <= 0x4) continue;
		//	Bitboard att = ma_to_king_attacks_bb(s,occ);		
		//	if(have_bit(att,ei.attackKingMaCan[Them])){  // ����Խ���
		//		if(  (StoX(s) < 0x4 && pos.piece_on(yk + 1) == (BSHI -delt))
		//			||(StoX(s) > 0x4 && pos.piece_on(yk - 1) == (BSHI -delt))) {
		//				bonus  += make_score(8,64);
		//				ei.attPoint[Us] += 2;
		//		}
		//		else{
		//			bonus  += make_score(4,32);
		//			ei.attPoint[Us] += 1;
		//		}	

		//		if(Up1Chess == (BMA - delt)){
		//			bonus += make_score(16,64);
		//		}
		//	}			
		//} // fen 2bakabC1/9/2n6/p3p1R1N/9/8P/P1r1P4/9/9/3AKABc1 w - - 0 1
		//////////////////////////////////////////////////////////////////////////

		
	}// end 

		
	return bonus;
}






