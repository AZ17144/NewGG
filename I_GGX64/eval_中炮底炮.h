

//***********************************************************
	// ���ڵ�����. (����,����)
	//*********************************************************** 
	Bitboard bzp = ei.ZhongDiPaoBB;
	while(m128_is_have_bit(bzp)){
		int msq    = pop_1st_bit(&bzp);
		uint8 mchess = PB90(msq);
		if(FALSE){
		}
		else if(mchess == RPAO){  // �п����Ǻ췽����,����
			if(FALSE){
			}
			else if(StoX(msq) == StoX(bk)){ // �п����Ǻ췽����

				// ��һ���ǲ�����ԭλ������
				//if(msq == 0x43 && PB90(0x3A) == RPAWN && PB90(0x1F) == BPAWN && bk == 0x04){
				//	if(bit_is_set(POSITION->DYN->attack_black,0x1F)){
				//		continue;  //�������������
				//	}
				//}		

				ei.attPoint[WHITECOLOR] += MidPao_att_point;         // ���ڼӹ�����
				// ��Ҫ�ж�һ���ǲ�������˨
				if(bk == 0x04 && PB90(0x0D) == BSHI && PB90(0X16) != EMPTY){					
					//if((PIECE_SIDE(PB90(0x03)) == BLACK_TO_MOVE && PB90(0x03) == BSHI)	        // ֻҪ������������ƶ�,�����ұ�����˨	    			
					//	|| (bit_is_set(POSITION->DYN->attack_white,0x03))){ // �������ܵ��Է��Ĺ��� 
					if(PB90(0x03) == BSHI){        // ֻҪ������������ƶ�,�����ұ�����˨	
						// 1, ���ܲ��ܹ��������� �ұ� ����, 
						for(int i = 0; i < RChe_num(); i++){
							int s = S90_from_piecelist(POSITION,RCHE,i);
							if(StoX(s) > 0x4){
								Bitboard C = rook_attacks_bb(s,_mm_andnot_si128(POSITION->byChessBB[RCHE],occ)); 
								C = m_and(C,m128_bb_or_bb(_mm_load_si128((__m128i*)Rank0BB),
									m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),UpBB[3])));
								if(m128_is_have_bit(C)){
									valu += TiMen_Che_att_Score;
									ei.attPoint[WHITECOLOR]  += TiMen_Che_att_point;
								}
							}
						}
						// 1, ������ڽ�������,������ ��Ҫ���ϵ�ס�ĳ�
						Bitboard tbP = m_and(bitboard_white_pawn,
							m_and(RightBB[0x04],
							_mm_load_si128((__m128i*)TiMenBit_Pawn)));
						if(m128_is_have_bit(tbP)){
						  valu += TiMen_Pawn_att_Score;
						  ei.attPoint[WHITECOLOR]  += TiMen_Pawn_att_point;
						}
					    // 3, ��
						if(StoX(rk) > 0x4){
							Bitboard tkb = rook_attacks_bb(rk,
								_mm_andnot_si128(m128_bb_or_bb(POSITION->byChessBB[BCHE],
								tbP),occ));
							if(m128_is_have_bit(m_and(tkb,
								_mm_load_si128((__m128i*)TiMenBit_Pawn)))){
							  // print_bb(tkb);
							   valu += TiMen_King_att_Score;
							   ei.attPoint[WHITECOLOR]  += TiMen_King_att_point;
							}
						}
					    // 4, ������ܹ�����������
						for(int i = 0; i < RMa_num(); i++){
							int s = S90_from_piecelist(POSITION,RMA,i);
							if(StoX(s) > 0x4){
								Bitboard A =  ma_to_king_attacks_bb(s,occ);  // �õ���Ĺ���λ����
								if(m128_is_have_bit(m_and(A,ei.attackKingMaCan[BLACKCOLOR]))){
								   valu += TiMen_Ma_att_Score;
								   ei.attPoint[WHITECOLOR]  += TiMen_Ma_att_point;
								}
							}
						}
					} // �ұ�����˨
					//if((PIECE_SIDE(PB90(0x05)) == BLACK_TO_MOVE && PB90(0x05) == BSHI)			    // ֻҪ���������ұ��ƶ�,�����������˨				
					//	|| (bit_is_set(POSITION->DYN->attack_white,0x05))){ // �������ܵ��Է��Ĺ���
					if(PB90(0x05) == BSHI) {
							// 1, ���ܲ��ܹ��������� �ұ� ����, 
							for(int i = 0; i < RChe_num(); i++){
								int s = S90_from_piecelist(POSITION,RCHE,i);
								if(StoX(s) < 0x4){
									Bitboard C = rook_attacks_bb(s,_mm_andnot_si128(POSITION->byChessBB[RCHE],occ)); 
									C = m_and(C,m128_bb_or_bb(_mm_load_si128((__m128i*)Rank0BB),
										m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),UpBB[3])));
									if(m128_is_have_bit(C)){
										valu += TiMen_Che_att_Score;
										ei.attPoint[WHITECOLOR]  += TiMen_Che_att_point;
									}
								}
							}
							// 1, ������ڽ�������,������ ��Ҫ���ϵ�ס�ĳ�
							Bitboard tbP = m_and(bitboard_white_pawn,
								m_and(LeftBB[0x04],
								_mm_load_si128((__m128i*)TiMenBit_Pawn)));
							if(m128_is_have_bit(tbP)){
								valu += TiMen_Pawn_att_Score;
								ei.attPoint[WHITECOLOR]  += TiMen_Pawn_att_point;
							}
							// 3, ��
							if(StoX(rk) < 0x4){
								Bitboard tkb = rook_attacks_bb(rk,
									_mm_andnot_si128(m128_bb_or_bb(POSITION->byChessBB[RCHE],
									tbP),occ));
								if(m128_is_have_bit(m_and(tkb,
									_mm_load_si128((__m128i*)TiMenBit_Pawn)))){
									//print_bb(tkb);
									valu += TiMen_King_att_Score;
									ei.attPoint[WHITECOLOR]  += TiMen_King_att_point;
								}
							}
							// 4, ������ܹ�����������
							for(int i = 0; i < RMa_num(); i++){
								int s = S90_from_piecelist(POSITION,RMA,i);
								if(StoX(s) < 0x4){
									Bitboard A =  ma_to_king_attacks_bb(s,occ);  // �õ���Ĺ���λ����
									if(m128_is_have_bit(m_and(A,ei.attackKingMaCan[BLACKCOLOR]))){
										valu += TiMen_Ma_att_Score;
										ei.attPoint[WHITECOLOR]  += TiMen_Ma_att_point;
									}
								}
							}
					}// �������˨
				} // if(bk == 0x04 && PB90(0x0D) == BSHI){	
			}// �п����Ǻ췽����
			else if(StoY(msq) == StoY(bk)){ // �п����Ǻ췽����
				
				if(pMat->searchInfo16 & CK_R_Only_1Che1PaoxPawn){	
					int palr = White_pawn_already_over_river(POSITION);
					if(palr == 0){
						continue;
					}
				}
				ei.attPoint[WHITECOLOR]  += Di_Pao_att_point;       // ���ڼӹ�����
				//��Ҫ�ж�һ���ǲ����ܵ��Է��Ĺ���
				if(bit_is_set(POSITION->DYN->attack_black,msq)){
					// �����Ǹ��Լ�����,��,�ڱ�����,ҲҪ�ӷ�
					if(bit_is_set(POSITION->DYN->attack_white,msq)){
					}
					else{
					    ei.attPoint[WHITECOLOR]  -= Di_Pao_att_By_Other;
					}
				}
			}
		}
		else if(mchess == BPAO){  // �п����Ǻڷ�����,����
			if(FALSE){
			}
			else if(StoX(msq) == StoX(rk)){ // �п����Ǻڷ�����

				// ��һ���ǲ�����ԭλ������
				//if(msq == 0x16 && PB90(0x3A) == RPAWN && PB90(0x1F) == BPAWN && rk == 0x55){
				//	if(bit_is_set(POSITION->DYN->attack_white,0x3A)){
				//		continue;  //�������������
				//	}
				//}
				ei.attPoint[BLACKCOLOR] += MidPao_att_point;         // ���ڼӹ�����
				// ��Ҫ�ж�һ���ǲ�������˨
				if(rk == 0x55 && PB90(0x4c) == RSHI && PB90(0X43) != EMPTY){					
					if(PB90(0x54) == RSHI){	        // ֻҪ������������ƶ�,�����ұ�����˨	
							// 1, ���ܲ��ܹ��������� �ұ� ����, 
							for(int i = 0; i < BChe_num(); i++){
								int s = S90_from_piecelist(POSITION,BCHE,i);
								if(StoX(s) > 0x4){
									Bitboard C = rook_attacks_bb(s,_mm_andnot_si128(POSITION->byChessBB[BCHE],occ)); 
									C = m_and(C,m128_bb_or_bb(_mm_load_si128((__m128i*)Rank9BB),
										m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),LowBB[6])));
									if(m128_is_have_bit(C)){
										valu -= TiMen_Che_att_Score;
										ei.attPoint[BLACKCOLOR]  += TiMen_Che_att_point;
									}
								}
							}
							// 1, ������ڽ�������,������ ��Ҫ���ϵ�ס�ĳ�
							Bitboard tbP = m_and(bitboard_black_pawn,
								m_and(RightBB[0x04],
								_mm_load_si128((__m128i*)TiMenBit_Pawn)));
							if(m128_is_have_bit(tbP)){
								valu -= TiMen_Pawn_att_Score;
								ei.attPoint[BLACKCOLOR] += TiMen_Pawn_att_point;
							}
							// 3, ��
							if(StoX(bk) > 0x4){
								Bitboard tkb = rook_attacks_bb(bk,
									_mm_andnot_si128(m128_bb_or_bb(POSITION->byChessBB[BCHE],
									tbP),occ));
								if(m128_is_have_bit(m_and(tkb,
									_mm_load_si128((__m128i*)TiMenBit_Pawn)))){
									//print_bb(tkb);
									valu -= TiMen_King_att_Score;
									ei.attPoint[BLACKCOLOR] += TiMen_King_att_point;
								}
							}
							// 4, ������ܹ�����������
							for(int i = 0; i < BMa_num(); i++){
								int s = S90_from_piecelist(POSITION,BMA,i);
								if(StoX(s) > 0x4){
									Bitboard A =  ma_to_king_attacks_bb(s,occ);  // �õ���Ĺ���λ����
									if(m128_is_have_bit(m_and(A,ei.attackKingMaCan[WHITECOLOR]))){
										valu -= TiMen_Ma_att_Score;
										ei.attPoint[BLACKCOLOR] += TiMen_Ma_att_point;
									}
								}
							}
					} // �ұ�����˨
					if(PB90(0x56) == RSHI){			    // ֻҪ���������ұ��ƶ�,�����������˨	
							// 1, ���ܲ��ܹ��������� �ұ� ����, 
							for(int i = 0; i < BChe_num(); i++){
								int s = S90_from_piecelist(POSITION,BCHE,i);
								if(StoX(s) < 0x4){
									Bitboard C = rook_attacks_bb(s,_mm_andnot_si128(POSITION->byChessBB[BCHE],occ)); 
									C = m_and(C,m128_bb_or_bb(_mm_load_si128((__m128i*)Rank9BB),
										m_and(_mm_load_si128((__m128i*)TiMenBit_Pawn),LowBB[6])));
									if(m128_is_have_bit(C)){
										valu -= TiMen_Che_att_Score;
										ei.attPoint[BLACKCOLOR] += TiMen_Che_att_point;
									}
								}
							}
							// 1, ������ڽ�������,������ ��Ҫ���ϵ�ס�ĳ�
							Bitboard tbP = m_and(bitboard_black_pawn,
								m_and(LeftBB[0x04],_mm_load_si128((__m128i*)TiMenBit_Pawn)));
							if(m128_is_have_bit(tbP)){
								valu -= TiMen_Pawn_att_Score;
								ei.attPoint[BLACKCOLOR] += TiMen_Pawn_att_point;
							}
							// 3, ��
							if(StoX(bk) < 0x4){
								Bitboard tkb = rook_attacks_bb(bk,
									_mm_andnot_si128(m128_bb_or_bb(POSITION->byChessBB[BCHE],
									tbP),occ));
								if(m128_is_have_bit(m_and(tkb,
									_mm_load_si128((__m128i*)TiMenBit_Pawn)))){
									//print_bb(tkb);
									valu -= TiMen_King_att_Score;
									ei.attPoint[BLACKCOLOR] += TiMen_King_att_point;
								}
							}
							// 4, ������ܹ�����������
							for(int i = 0; i < BMa_num(); i++){
								int s = S90_from_piecelist(POSITION,BMA,i);
								if(StoX(s) < 0x4){
									Bitboard A =  ma_to_king_attacks_bb(s,occ);  // �õ���Ĺ���λ����
									if(m128_is_have_bit(m_and(A,ei.attackKingMaCan[WHITECOLOR]))){
										valu -= TiMen_Ma_att_Score;
										ei.attPoint[BLACKCOLOR] += TiMen_Ma_att_point;
									}
								}
							}
					}// �������˨
				} // if(bk == 0x04 && PB90(0x0D) == BSHI){	
			}// �п����Ǻڷ�����
			else if(StoY(msq) == StoY(rk)){ // �п����Ǻڷ�����

				if(pMat->searchInfo16 & CK_B_Only_1Che1PaoxPawn){	
					int palr = Black_pawn_already_over_river(POSITION);
					if(palr == 0){
						continue;
					}
				}
				ei.attPoint[BLACKCOLOR] += Di_Pao_att_point;       // ���ڼӹ�����
				//fen 3k1P3/4aR3/2n1b4/p3p3p/2P3c2/P8/R2C4P/4C3N/cr2AK3/3r2B2 b - - 0 1
				//��Ҫ�ж�һ���ǲ����ܵ��Է��Ĺ���
				if(bit_is_set(POSITION->DYN->attack_white,msq)){
					// �����Ǹ��Լ�����,��,�ڱ�����,ҲҪ�ӷ�
					if(bit_is_set(POSITION->DYN->attack_black,msq)){
					}
					else{
					   ei.attPoint[BLACKCOLOR] -= Di_Pao_att_By_Other;
					}
				}
				// ����ʱ�����Գ齫�ķ���
			}
		}
	}