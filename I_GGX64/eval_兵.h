	


       // ���
		Bitboard p = bitboard_white_pawn;
		Bitboard B = p;
		//Bitboard Btmp;
		// ��ǰһ��.
		B = _mm_andnot_si128(_mm_load_si128((__m128i*)Rank0BB),B);
		m128_RightShift(B,9);
		ei.attackedBy[RPAWN] = B;   // ��һ��ֻҪֱ�Ӹ�ֵ
		POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,B);	
		B = m128_bb_and_bb(B,bit_bk);
		m128_LeftShift(B,9);	
		POSITION->DYN->black_king_check = m128_bb_or_bb(POSITION->DYN->black_king_check,B);
		// ���ӱ�	
		//fen 9/4k4/3a5/1P7/9/3N1R3/4r4/4Bn3/9/2BK1p3 w - - 0 0
		if(have_bit(p,_mm_load_si128((__m128i*)RpawnOverBB))){
			p = m128_bb_and_bb(p,_mm_load_si128((__m128i*)RpawnOverBB));
			// ����һ�ߵļӷ�
			Bitboard bKPC;
			bKPC = m128_bb_and_bb(ei.attackKingCheCan[WHITECOLOR],p);
			while (m128_is_have_bit(bKPC)){
				int kpawnche = pop_1st_bit(&bKPC);
				if(StoX(kpawnche) != StoX(rk)){
					continue;
				}
				else if(PB90[kpawnche] == RPAWN){ //fen 4ka3/4aP3/2n5b/4p1N1p/p5b2/4R4/1r2P3P/2r1B4/4A1C2/c1BA1K3 w
					if(m128_is_have_bit(m128_bb_and_bb(
						one_rpawn_rk_attacks(kpawnche),attacks_by_rpawn_rk(bk)))){ //board_display(POSITION,"��֧�ű�!!");							
							ei.Rattack_B_Count += King_CheSameLineAtt ;
							break;
					}
				}
			}						
			//------- ���ӱ������ļӷ�
			int gh_num  = count_1s(_mm_andnot_si128(_mm_load_si128((__m128i*)Rank0BB),p));	// ȥ�˵��߱�
			valu       += PAWN_NUM_OVER_RIVER_point[gh_num];
			B = p;
			//------- ����Է�û������,Ҫ�ӷ���
			int yshi    = POSITION->pieceCount[BSHI];
			//int pnum    = 0;
			while(m128_is_have_bit(B)){ // ���
				int pawn = pop_1st_bit(&B);				
				valu += point_B_01Shi_R_Pawn90[yshi][pawn];   // �Է����˺��ҷ����ļӷ�
				if(yshi == 0){
					if(   (ei.R_att_Bside[BK_RIGHT] & (KS_S_CHE_MY_SIDE_1_OPEN + KS_S_CHE_MY_SIDE_2_OPEN))
						||(ei.R_att_Bside[BK_LEFT]  & (KS_S_CHE_MY_SIDE_1_OPEN + KS_S_CHE_MY_SIDE_2_OPEN))){
							valu += point_B_01Shi_R_Pawn90_My_CheOpen[pawn]; //�ټ�һЩ��
                     
							// �ȶ�һ�³����ͶԷ����˵�����
							// 2��1����2��,1��1����1��,����Է������ڷ���,��Ҫ��һ��. ����Է��г��ڷ���,��Ҫ��һ��.
							if(StoY(bk) == 0x0){
								if(pawn == 0x0d){

								}
							}

					}


					//
				}
				int pawnSafe = PrePawnAttKingMul_Safe[yshi][pawn][bk];
				if(pawnSafe){
					valu += pawnSafe;
					if(StoX(pawn) == 0x4){
						ei.R_att_Bside[BK_RIGHT] |= KS_S_PAWN_SIDE_ATT;
						ei.R_att_Bside[BK_LEFT]  |= KS_S_PAWN_SIDE_ATT;
					}
					else{
						ei.R_att_Bside[King_4_Side(pawn)] |= KS_S_PAWN_SIDE_ATT;	
					}
				}
			}
			B = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);  // ȥ�������
			m128_RightShift(B,1);                   //���к������һ��
			ei.attackedBy[RPAWN] = m128_bb_or_bb(ei.attackedBy[RPAWN],B);
			POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,B);
			B = m128_bb_and_bb(B,bit_bk);
			m128_LeftShift(B,1);		
			POSITION->DYN->black_king_check = m128_bb_or_bb(POSITION->DYN->black_king_check,B);
			//
			B = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
			m128_LeftShift(B,1);                   //���к������һ��
			ei.attackedBy[RPAWN] = m128_bb_or_bb(ei.attackedBy[RPAWN],B);
			POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,B);
			B = m128_bb_and_bb(B,bit_bk);
			m128_RightShift(B,1);
			POSITION->DYN->black_king_check = m128_bb_or_bb(POSITION->DYN->black_king_check,B);

			// �õ��䱣���Լ������ӵķ�
			B = m128_bb_and_bb(ei.attackedBy[RPAWN],occ);
			while (m128_is_have_bit(B))	{
				int p1 = pop_1st_bit(&B);
				valu += Point_R_pawn_Att_Score[PB90[p1]];
			}			
		}	


		// black ��
		p = bitboard_black_pawn;
		B = p;
		// ��ǰһ��.
		B = _mm_andnot_si128(_mm_load_si128((__m128i*)Rank9BB),B);
		m128_LeftShift(B,9);
		ei.attackedBy[BPAWN] = B;   // ��һ��ֻҪֱ�Ӹ�ֵ
		POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,B);
		B = m128_bb_and_bb(B,bit_rk);
		m128_RightShift(B,9);
		POSITION->DYN->white_king_check = m128_bb_or_bb(POSITION->DYN->white_king_check,B);
		// ���ӱ�	
		if(have_bit(p,_mm_load_si128((__m128i*)BpawnOverBB))){
			p = m128_bb_and_bb(p,_mm_load_si128((__m128i*)BpawnOverBB));
			Bitboard bKPC;
			bKPC = m128_bb_and_bb(ei.attackKingCheCan[BLACKCOLOR],p);
			while (m128_is_have_bit(bKPC)){
				int kpawnche = pop_1st_bit(&bKPC);
				if(StoX(kpawnche) != StoX(bk)){
					continue;
				}
				else if(PB90[kpawnche] == BPAWN){ //�ٿ�һ���ҷ����ܲ��ܳԵ��Է��Ľ�						
					if(m128_is_have_bit(m128_bb_and_bb(
						one_bpawn_bk_attacks(kpawnche),attacks_by_bpawn_bk(rk)))){ //board_display(POSITION,"��֧�ű�!!"); //fen 3k1a3/Rc2a4/4b1n2/4p4/P1p1n1bC1/4RN3/2P1Pr2P/N3B1r2/3pA4/2BAK4 w					
							ei.Battack_R_Count += King_CheSameLineAtt ;
							break;
					}
				}
			}

			//------- ���ӱ������ļӷ�
			int gh_num  = count_1s(_mm_andnot_si128(_mm_load_si128((__m128i*)Rank9BB),p));	// ȥ�˵��߱�
			valu       -= PAWN_NUM_OVER_RIVER_point[gh_num]; // fen 3ckab2/4a4/4b4/P2R1P2p/2r1P4/P1N6/5n2P/3AB4/9/2BK1A3 w - - 5 5
			
			B = p; // fen 4ka3/1PP1a4/9/9/4p1p2/7R1/4p4/4B4/3rA4/3AK1B2 b
			//------- ����Է�û������,Ҫ�ӷ���
			int yshi    = POSITION->pieceCount[RSHI];
			//int pnum    = 0;
			while(m128_is_have_bit(B)){
				int pawn = pop_1st_bit(&B);		//fen 1N1k1a3/1N7/3a5/9/4C3p/4p4/4p3n/4B4/1n7/2BA1K3 b - - 0 0 	y	
				valu -= point_R_01Shi_B_Pawn90[yshi][pawn];
				if(yshi == 0){
					if(   (ei.B_att_Rside[RK_RIGHT] & (KS_S_CHE_MY_SIDE_1_OPEN + KS_S_CHE_MY_SIDE_2_OPEN))
						||(ei.B_att_Rside[RK_LEFT]  & (KS_S_CHE_MY_SIDE_1_OPEN + KS_S_CHE_MY_SIDE_2_OPEN))){
							valu -= point_R_01Shi_B_Pawn90_My_CheOpen[pawn]; //�ټ�һЩ��
					}
				}
				int pawnSafe = PrePawnAttKingMul_Safe[yshi][pawn][rk];
				if(pawnSafe){
					valu -= pawnSafe;
					if(StoX(pawn) == 0x4){
						ei.B_att_Rside[RK_RIGHT]        |= KS_S_PAWN_SIDE_ATT;  //�б����������
						ei.B_att_Rside[RK_LEFT]         |= KS_S_PAWN_SIDE_ATT;
					}
					else{
						ei.B_att_Rside[King_4_Side(pawn)] |= KS_S_PAWN_SIDE_ATT;	
					}
				}
			}

			B = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);  // ȥ�������
			m128_RightShift(B,1);                   //���к������һ��
			ei.attackedBy[BPAWN] = m128_bb_or_bb(ei.attackedBy[BPAWN],B);
			POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,B);
			B = m128_bb_and_bb(B,bit_rk);
			m128_LeftShift(B,1);
			POSITION->DYN->white_king_check = m128_bb_or_bb(POSITION->DYN->white_king_check,B);
			//
			B = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
			m128_LeftShift(B,1);                   //���к������һ��
			ei.attackedBy[BPAWN] = m128_bb_or_bb(ei.attackedBy[BPAWN],B);
			POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,B);
			B = m128_bb_and_bb(B,bit_rk);
			m128_RightShift(B,1);
			POSITION->DYN->white_king_check = m128_bb_or_bb(POSITION->DYN->white_king_check,B);

			// �õ����䱣���Լ������ӵķ�
			B = m128_bb_and_bb(ei.attackedBy[BPAWN],occ);
			while (m128_is_have_bit(B))	{
				int p1 = pop_1st_bit(&B);
			    valu -= Point_B_pawn_Att_Score[PB90[p1]];
			}
		}

		