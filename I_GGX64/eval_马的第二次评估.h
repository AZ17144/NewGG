
	//***********************************************************
	// ���� ( �ڶ������� )
	//***********************************************************
	for(int i = 0; i < RMa_num(); i++){
		int s = S90_from_piecelist(POSITION,RMA,i);
		Bitboard A = ei.RmaAtt[i];

		// 1. ��һ���ܲ����ݽ�
		if(m128_is_have_bit(m_and(POSITION->DYN->white_pao_null,A))){
			ei.attPoint[WHITECOLOR] += MaCanPaoNullCHeckPoint;
			ei.kingAdjacentZoneAttacksCount[WHITECOLOR] ++;
			set_bit(ei.attackKingBoard,s);                  // ��һ����־, ��������ݽ�,�����Ҳ�������������
		}

		Bitboard ckatt = m_and(A,ei.attackKingMaCan[BLACKCOLOR]);
		// 2. ��һ���ܲ���ֱ�ӽ�
		if(m128_is_have_bit(ckatt)){
			ei.attPoint[WHITECOLOR] += MaCanCHeckPoint;
			set_bit(ei.attackKingBoard,s);                  // ��һ����־

			// ��һ���ǲ��ǰ�ȫ�Ľ�
			if(have_bit(white_safe,ckatt)){
				ei.attPoint[WHITECOLOR] += MaSafeCheckBonus * count_1s(m_and(white_safe,ckatt));
				ei.kingAdjacentZoneAttacksCount[WHITECOLOR] ++;
			}
		}


		// 3. �������Է������߲�
		if(m128_is_have_bit(m_and(A,KingAttackZone[bk]))){
			set_bit(ei.attackKingBoard,s);  
			Bitboard bb = m_and(A,one_bpawn_bk_attacks(bk));				
			ei.kingAdjacentZoneAttacksCount[WHITECOLOR] += count_1s(bb);	
		}

		// ����Ϊ���������, 
		A = m_and(A,Ma_Pseudo_Good_Att[s]);		  // ������кò�
		A = _mm_andnot_si128(LowBB[0x7],A);                   // ȥ���������
		A = _mm_andnot_si128(bitboard_occ_white,A);           // ȥ�����ѵ����
		B = A;
		A = _mm_andnot_si128(POSITION->DYN->attack_black,A);  // ȥ�˶Է��Ĺ������

		int mob = count_1s(A);
		valu += Point_MaMob(MaMoveAddNoProtect[mob]);

		if(mob == 0){ // ��û�кò���
			if(m128_is_have_bit(B)){  // ԭ���кò�
				if(m128_is_have_bit(_mm_andnot_si128(ei.BpawnAtt,B)) == FALSE){
					valu -= point(32,48); // �����ڸ���������,û�кò���
				}
			}
		}
	}
	//***********************************************************
	// ���� ( �ڶ������� )
	//***********************************************************
	for(int i = 0; i < BMa_num(); i++){
		int s = S90_from_piecelist(POSITION,BMA,i);
		Bitboard A = ei.BmaAtt[i];

		// 1. ��һ���ܲ����ݽ�
		if(m128_is_have_bit(m_and(POSITION->DYN->black_pao_null,A))){
			ei.attPoint[BLACKCOLOR] += MaCanPaoNullCHeckPoint;
			ei.kingAdjacentZoneAttacksCount[WHITECOLOR] ++;
			set_bit(ei.attackKingBoard,s);                  // ��һ����־, ��������ݽ�,�����Ҳ�������������
		}

		Bitboard ckatt = m_and(A,ei.attackKingMaCan[WHITECOLOR]);
		// 2. ��һ���ܲ���ֱ�ӽ�
		if(m128_is_have_bit(ckatt)){
			ei.attPoint[BLACKCOLOR] += MaCanCHeckPoint;
			set_bit(ei.attackKingBoard,s);                  // ��һ����־

			// ��һ���ǲ��ǰ�ȫ�Ľ�
			if(have_bit(black_safe,ckatt)){
				ei.attPoint[BLACKCOLOR] += MaSafeCheckBonus * count_1s(m_and(black_safe,ckatt));
				ei.kingAdjacentZoneAttacksCount[BLACKCOLOR] ++;
			}
		}

		// 3. �������Է������߲�
		if(m128_is_have_bit(m_and(A,KingAttackZone[rk]))){
			set_bit(ei.attackKingBoard,s);  
			Bitboard bb = m_and(A,one_rpawn_rk_attacks(rk));				
			ei.kingAdjacentZoneAttacksCount[BLACKCOLOR] += count_1s(bb);	
		}
				

		A = m_and(A,Ma_Pseudo_Good_Att[s]);		
		A = _mm_andnot_si128(UpBB[0x2],A);   //A = _mm_andnot_si128(RankBB_A[0x0],A);
		A = _mm_andnot_si128(bitboard_occ_black,A);           // ȥ�������˵����
		B = A;
		A = _mm_andnot_si128(POSITION->DYN->attack_white,A);  //

		int mob = count_1s(A);
		valu -= Point_MaMob(MaMoveAddNoProtect[mob]);

		if(mob == 0){ // ��û�кò��� POSITION->DYN->white_xray
			if(m128_is_have_bit(B)){  // ԭ���кò�
				if(m128_is_have_bit(_mm_andnot_si128(ei.RpawnAtt,B)) == FALSE){
					valu += point(32,48); // �����ڸ���������,û�кò���
				}
			}// fen 1c2kab2/4a1n2/b8/p2P2p1p/9/2P3P2/P1R6/3A1A3/3N5/c1BnK4 w - - 39 39
		}
	}
	
	
    //// ***********************************************************
	//// �����������.   board_display(board,"�� ������!!",stdout);
	////*********************************************************** 
	//if(ei.ev_stat & EV_STAT_Rwoxin_By_B){   // �췽��������
	//	ei.Battack_R_Count += Wo_Xing_Ma_att_point; // 
	//    valu -= point(64,512);
	//}

	//if(ei.ev_stat & EV_STAT_Bwoxin_By_R){   // �ڷ���������
	//	ei.Rattack_B_Count += Wo_Xing_Ma_att_point; // 
	//	 valu += point(64,512);
	//}
	//fen 3a3CC/4k4/bc3ac2/1R6p/6b2/2P2p3/P3r3P/9/4N4/3AKA3 w - - 16 16
	//�����ڵĿ��ܽ����֣�