
	// �ڶ���ֻ���۹��ӱ�
	// ���
	p = m_and(bitboard_white_pawn,_mm_load_si128((__m128i*)RpawnOverBB));
	if(m128_is_have_bit(p)){
		// ����һ�ߵļӷ�
		//Bitboard bKPC;
		//bKPC = m_and(ei.attackKingCheCan[WHITECOLOR],p);
		//while (m128_is_have_bit(bKPC)){
		//	int kpawnche = pop_1st_bit(&bKPC);  //fen 4ka3/4aP3/2n5b/4p1N1p/p5b2/4R4/1r2P3P/2r1B4/4A1C2/c1BA1K3 w
		//	if(m128_is_have_bit(m_and(
		//		one_rpawn_rk_attacks(kpawnche),attacks_by_rpawn_rk(bk)))){ //board_display(POSITION,"��֧�ű�!!");							
		//			ei.Rattack_B_Count += King_CheSameLineAtt ;
		//			break;
		//	}
		//}						
		//------- ���ӱ������ļӷ�
		int gh_num  = count_1s(_mm_andnot_si128(_mm_load_si128((__m128i*)Rank0BB),p));	// ȥ�˵��߱�
		valu       += PAWN_NUM_OVER_RIVER_point[gh_num];
		B = p;
		//------- ����Է�û������,Ҫ�ӷ���
		int yshi    = POSITION->pieceCount[BSHI];
		//int pnum    = 0;
		while(m128_is_have_bit(B)){  // ���
			int pawn = pop_1st_bit(&B);			

			//fen 2ba1k3/3P5/9/9/p3pNb2/8p/P1c6/2N1BA3/4A1n2/2BK5 w - - 10 10
			//��������һ��,Ҫ�۷�
			if(StoY(pawn) <= 0x2){
				if(!IsOnSameSide(pawn,bk)){
					valu -= PawnNotOnSameSide[yshi];
				}
			}

			valu += point_B_01Shi_R_Pawn90[yshi][pawn];              //���ӱ��żӷ�
			int pawnSafe = PrePawnAttKingMul_Safe[yshi][pawn][bk];   //�����ƽ��ķ�
			if(pawnSafe){
				// 1.��һ�±��ܲ��ܽ���, ת��Ϊbcy,bcx, �����������
				if(m128_is_have_bit(m_and( // ��������Խ�����
					one_rpawn_rk_attacks(pawn),attacks_by_rpawn_rk(bk)))){
						// ��Ҫ�ж�һ��,1,Ҫ�����ڶԷ��Ľ�, 

						set_bit(ei.attackKingBoard,pawn);                         // ��һ����־

						ei.kingAdjacentZoneAttacksCount[WHITECOLOR] ++;

						if(bit_is_set(ei.attackKingCheCan[WHITECOLOR],pawn)){
							ei.attPoint[WHITECOLOR] += King_CheSameLineAtt ; 
						}
						//����Է��Ľ�����ԭλ,�緽ֻ��һ����û��
						if(StoY(pawn) != 0x0){						
							ei.rcy ++;	
							if(ABS(StoX(pawn) - 0x4) <= 1){
								if(PB90(pawn - 9) != BSHI || yshi <= 1 || bk != 0x4){
									ei.rcy++;
								}
							}
						}
						valu += pawnSafe;
				}
				else{ //2.��һ�±��ǲ��ǲ���ǰ����,
					if(StoY(pawn) < StoY(bk)){
					}
					else{ //POSITION->DYN->attack_black ��û�кò�
						if(m128_is_have_bit( // fen 1rbak4/1C2a4/4b4/6P2/p6PC/2B6/P1pn5/BRnA5/3KA4/9 r
							_mm_andnot_si128(
							m128_bb_or_bb(POSITION->DYN->attack_black,bitboard_occ_white),
							RPawnGoodMove[pawn]))){
							valu += pawnSafe;
						}	
					}
				}
			}
		}
	}

	// �ڱ�
	p = m_and(bitboard_black_pawn,_mm_load_si128((__m128i*)BpawnOverBB));
	if(m128_is_have_bit(p)){

		//------- ���ӱ������ļӷ�
		int gh_num  = count_1s(_mm_andnot_si128(_mm_load_si128((__m128i*)Rank9BB),p));	// ȥ�˵��߱�
		valu       -= PAWN_NUM_OVER_RIVER_point[gh_num]; // fen 3ckab2/4a4/4b4/P2R1P2p/2r1P4/P1N6/5n2P/3AB4/9/2BK1A3 w - - 5 5

		B = p; // fen 4ka3/1PP1a4/9/9/4p1p2/7R1/4p4/4B4/3rA4/3AK1B2 b
		//------- ����Է�û������,Ҫ�ӷ���
		int yshi    = POSITION->pieceCount[RSHI];
		//int pnum    = 0;
		while(m128_is_have_bit(B)){
			int pawn = pop_1st_bit(&B);		//fen 1N1k1a3/1N7/3a5/9/4C3p/4p4/4p3n/4B4/1n7/2BA1K3 b - - 0 0 	y	
						
			//fen 2ba1k3/3P5/9/9/p3pNb2/8p/P1c6/2N1BA3/4A1n2/2BK5 w - - 10 10
			//��������һ��,Ҫ�۷�
			if(StoY(pawn) >= 0x7){
				if(!IsOnSameSide(pawn,rk)){
					valu += PawnNotOnSameSide[yshi];
				}
			}
			
			valu -= point_R_01Shi_B_Pawn90[yshi][pawn];
			int pawnSafe = PrePawnAttKingMul_Safe[yshi][pawn][rk];
			if(pawnSafe){
				// 1.��һ�±��ܲ��ܽ���, ת��Ϊbcy,bcx, �����������
				if(m128_is_have_bit(m_and( // ��������Խ�����
					one_bpawn_bk_attacks(pawn),attacks_by_bpawn_bk(rk)))){
                   
					set_bit(ei.attackKingBoard,pawn);                         // ��һ����־

					ei.kingAdjacentZoneAttacksCount[BLACKCOLOR] ++;
					
					if(bit_is_set(ei.attackKingCheCan[BLACKCOLOR],pawn)){
						ei.attPoint[BLACKCOLOR] += King_CheSameLineAtt ; 
					}

					// ����Է��Ľ�����ԭλ,�緽ֻ��һ����û��
					if(StoY(pawn) != 0x9){						
						ei.bcy ++;	
						if(ABS(StoX(pawn) - 0x4) <= 1){
							if(PB90(pawn + 9) != RSHI || yshi <= 1 || rk != 0x55){
								ei.bcy++;
							}
						}
					}
					valu -= pawnSafe;
				}
				else{  //�������ܽ���, ��һ�±��ǲ��ǲ���ǰ����,
					if(StoY(pawn) > StoY(rk)){
					}
					else{ //POSITION->DYN->attack_black
						if(m128_is_have_bit( //fen 1rbak4/1C2a4/4b4/6P2/p6PC/2B6/P1pn5/BRnA5/3KA4/9 r
							_mm_andnot_si128(
							m128_bb_or_bb(POSITION->DYN->attack_white,bitboard_occ_black),
							BPawnGoodMove[pawn]))){
								valu -= pawnSafe;
						}
					}
				}
			}
		}
	}