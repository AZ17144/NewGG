#include "eval_total.h"

///////////////////////////////////////////////////////////////////////////
/// �������һ�����˱�ǣ����, ���� ������, ����˨, ... �����췽�����ڷ�����
template<Color Us>
Score eval_king_up_one_string(const Position& pos, EvalInfo& ei){

	const Color Them = (Us == WHITE ? BLACK : WHITE);	
	const Square yk  = pos.king_square(Them);	
	Score bonus = SCORE_ZERO;
	
	// �Է�����������ӱ�ǣ����. 
	if(bit_is_set(ei.xray_bit[Us],(Us == WHITE ? 0x0d : 0x4c)) && (Us == WHITE ? yk == 0x04 : yk == 0x55)){		

		const Piece delt = COLOR_BY_SIDE_ADD[Us];
		Bitboard  occ = pos.occupied_squares();
		const Square mk  = pos.king_square(Us);
		// �õ��������sq2,sq3.  k sq1 sq2 sq3
		//Bitboard bm = m_and(ei.attackKingPaoCan[Them], 
		//	m_or(pos.pieces(RKING + delt), pos.pieces(RCHE + delt))); // 
		Bitboard bm = m_and(ei.attackKingPaoCan[Them], m_and(occ,FileBB_A[0x4]));
		//bm = m_and(bm,FileBB_A[0x4]);   // print_bb(bm);
		Square sq2 = pop_1st_bit(&bm);
		assert(sq2 >= 0x04 && sq2 <= 0x55);

		Piece Up1Chess = (Us == WHITE ? pos.piece_on(Square(0x0d)) : pos.piece_on(Square(0x4c)));
		Piece Up2Chess = pos.piece_on(sq2);

		bool isMPao;  // �ǲ��ǶԷ�������ǣ��. 
		//bool istm = false;
		//print_bb(ei.ZhongDiPaoBB[Us]);
		if(have_bit(ei.ZhongDiPaoBB[Us],FileBB_A[0x4])){
			isMPao = true;			
		}
		else{
			isMPao = false;
		}
		//fen 2bak4/3ra4/4n2r1/pR1CCP2p/6b2/9/Pp6P/3R5/2nNA4/2c1KAB2 b - - 0 1
		// �� �� (��,��  ��)
		if(false){			
		}// ���湲���ֿ���.
		else if(Up1Chess == (BSHI - delt)){	 // �� �� sq2 sq3 �п���������˨.
			if(isMPao){
				if(pos.piece_on(yk - 1) == (BSHI - delt) || pos.piece_on(yk + 1) == (BSHI - delt)){
					if(Up2Chess == (BMA - delt) || Up2Chess == (BPAO - delt)){
						bonus += make_score(16,32);
						ei.attPoint[Us] += 3;
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
					} //fen fen 3aka3/4n4/bc2b2c1/p3C1P1p/2nC5/2B6/3NP3P/9/9/2BAKA3 w - - 0 1
					bonus  += make_score(128,256);
					ei.attPoint[Us] += 24;
					//fen 3a5/2P1a4/b2kc4/9/9/9/3r5/4B4/4N4/R2AKAB2 b - - 0 1
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
						bonus  += make_score(64,168);
						ei.attPoint[Us] += 18;
				}
				// ҲҪ��һЩ����
				else{
					bonus  += make_score(32,96);
					ei.attPoint[Us] += 3;
				}
				//fen 2bak3C/4a4/9/p2P4p/3r5/4p4/P3r1c1P/6R2/4N4/1R2KA3 w - - 0 1
				if(pos.piece_on(yk + 1) == (BSHI - delt)){
					if(!have_bit(pos.pieces(BXIANG - delt), RightBB[0x4])){
						Bitboard apao = m_and(pos.pieces(RPAO + delt),RightBB[0x05]);
						ei.attackKingBoard[Us] = m_or(ei.attackKingBoard[Us],apao);
					}
				}
				if(pos.piece_on(yk - 1) == (BSHI - delt)){
					if(!have_bit(pos.pieces(BXIANG - delt), LeftBB[0x4])){
						Bitboard apao = m_and(pos.pieces(RPAO + delt),LeftBB[0x03]);
						ei.attackKingBoard[Us] = m_or(ei.attackKingBoard[Us],apao);
					}
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

		// �ٿ�һ����·�Ĺ���
		//////////////////////////////////////////////////////////////////////////					  
		// 1. �ҷ����ܲ��ܹ������Է����ı���
		for(int i = 0; i < pos.piece_count(RCHE + delt); i++){
			Square s =  pos.piece_list(RCHE + delt,i);	

			if(StoX(s) == 0x4) continue;

			Bitboard att = ei.CheAtt[Us][i];		

			Us == WHITE ?
				att = m_and(att,m_or(_mm_load_si128((__m128i*)Rank0BB),  // ����+���Ļ򹥻�λ��
				m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),UpBB[3])))
				: att = m_and(att,m_or(_mm_load_si128((__m128i*)Rank9BB),
				m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),LowBB[6])));

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

				//fen 2baka1r1/4n4/4b4/pc2C3p/3P5/4P4/P4R2P/4BK3/4A4/9 b - - 0 1
				if(Up1Chess == (BMA - delt)){
					bonus += make_score(16,96);
				}

				if(isMPao){
					bonus  += make_score(16,96);
					ei.attPoint[Us] += 2;
					// ����Է�û�������ڱ�����������һ����,Ҫ�ӷ�
					if(!bit_is_set(ei.attacked_by(Them),mside) && pos.piece_on(mside) == EMPTY){
						// fen 2bak4/4a4/2c1b1n2/p3CR3/6p2/2Pr5/4P4/C3B1N2/1c2K4/2BA1A3 w - - 0 1
						bonus  += make_score(16,48);
					}
					//fen 2r1kab2/4a3n/4bc3/6P1p/R2NC4/1p7/P3P3P/2C6/4A4/1c2K1B2 w - - 0 1
					//����ǶԷ��ĳ��ڵ���,�����Ǹ����,��Ҫ�۷�.
					if(have_bit(ei.attackKingCheCan[Them],pos.pieces(BCHE - delt))){
						bonus  += make_score(16,64);
					}

					//fen 1nbak4/1N2a4/1c2b1nC1/1C2p1N1p/5r3/6P2/P2pc2RP/4B4/4A4/2BAK4 w - - 0 1
					//�������ڱ����ҷ�������
					if(have_bit(ei.attacked_by(Us),m_and(ei.ZhongDiPaoBB[Us],FileBB_A[0x04]))){
						bonus  += make_score(8,64);
					}
				}
				else{
					bonus  += make_score(8,48);
					ei.attPoint[Us] += 3;
					// ����Է�û�������ڱ�����������һ����,Ҫ�ӷ�
					if(!bit_is_set(ei.attacked_by(Them),mside) && pos.piece_on(mside) == EMPTY){
						// fen 2bak4/4a4/2c1b1n2/p3CR3/6p2/2Pr5/4P4/C3B1N2/1c2K4/2BA1A3 w - - 0 1
						bonus  += make_score(16,32);
					}
					//fen 2r1kab2/4a3n/4bc3/6P1p/R2NC4/1p7/P3P3P/2C6/4A4/1c2K1B2 w - - 0 1
					//����ǶԷ��ĳ��ڵ���,�����Ǹ����,��Ҫ�۷�.
					if(have_bit(ei.attackKingCheCan[Them],pos.pieces(BCHE - delt))){
						bonus  += make_score(6,32);
					}
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
			if(bit_is_set(ei.attacked_by(BPAO - delt),mside)){
				ei.attPoint[Us] -= 6;
			}
		} // che_end

		//////////////////////////////////////////////////////////////////////////
		// 2 ��һ�±�
		Bitboard tbp = m_and(pos.pieces(RPAWN + delt),_mm_load_si128((__m128i*)TiMenBit_Pawn));
		// ��һ��,�ǲ�����һ������.
		if(m_have_bit(tbp)){  
			if(pos.piece_on(yk + 1) == (BSHI -delt)){
				if(have_bit(tbp,LeftBB[0x4])){
					bonus  += make_score(8,64);
					ei.attPoint[Us] += 4;
				}
				else{
					bonus  += make_score(4,32);
					ei.attPoint[Us] += 2;
				}
			}
			if (pos.piece_on(yk - 1) == (BSHI -delt)){
				if(have_bit(tbp,RightBB[0x4])){
					bonus  += make_score(8,64);
					ei.attPoint[Us] += 4;
				}
				else{
					bonus  += make_score(4,32);
					ei.attPoint[Us] += 2;
				}
			}

			if(Up1Chess == (BMA - delt)){
				bonus += make_score(16,64);
			}
		}
		//////////////////////////////////////////////////////////////////////////
		/// 3. ��
		if(StoX(mk) != 0x4){  // if(StoX(s) == 0x4) continue;
			Bitboard tkb = rook_attacks_bb(mk,_mm_andnot_si128(
				m_or(pos.pieces(RCHE + delt), tbp),occ));
			if(have_bit(tkb,_mm_load_si128((__m128i*)TiMenBit_Pawn))){
				if(  (StoX(mk) < 0x4 && pos.piece_on(yk + 1) == (BSHI -delt))
					||(StoX(mk) > 0x4 && pos.piece_on(yk - 1) == (BSHI -delt))) {
						bonus  += make_score(16,64);
						ei.attPoint[Us] += 3;
				}
				else{
					bonus  += make_score(16,32);
					ei.attPoint[Us] += 2;
				}	

				if(Up1Chess == (BMA - delt)){
					bonus += make_score(16,64);
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		/// 4. ��
		for(int i = 0; i < pos.piece_count(RMA + delt); i++){
			Square s =  pos.piece_list(RMA + delt,i);
			// ���ڼ���ҲҪ����
			if(Us == WHITE? StoY(s) >= 0x5 : StoY(s) <= 0x4) continue;
			Bitboard att = ei.MaAtt[Us][i];		
			if(have_bit(att,ei.attackKingMaCan[Them])){  // ����Խ���
				if(  (StoX(s) < 0x4 && pos.piece_on(yk + 1) == (BSHI -delt))
					||(StoX(s) > 0x4 && pos.piece_on(yk - 1) == (BSHI -delt))) {
						bonus  += make_score(8,64);
						ei.attPoint[Us] += 3;
				}
				else{
					bonus  += make_score(4,32);
					ei.attPoint[Us] += 2;
				}	

				if(Up1Chess == (BMA - delt)){
					bonus += make_score(16,64);
				}
			}			
		} // fen 2bakabC1/9/2n6/p3p1R1N/9/8P/P1r1P4/9/9/3AKABc1 w - - 0 1
		//////////////////////////////////////////////////////////////////////////

		
	}// end 

		
	return bonus;
}




