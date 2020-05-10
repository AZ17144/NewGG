

// �쳵
for(int i = 0; i < RChe_num(); i++){
	int s = S90_from_piecelist(POSITION,RCHE,i);

	Bitboard A = ei.RcheAtt[i];
	// -------------------------------------------------------------------------------------------- 
	// 1. �ƶ����� Mobility
	// -------------------------------------------------------------------------------------------- 
	int mob; 
	Bitboard ratt = m_and(A,RankBB_A[StoY(s)]);
	ratt = _mm_andnot_si128(bitboard_occ_white,ratt);           // ȥ���Լ������
	ratt = _mm_andnot_si128(POSITION->DYN->attack_black,ratt);  // ȥ�˶Է��Ĺ��������
	mob =  count_1s(ratt);
	valu += r_CheMove[mob];  // �����ƶ��ķ�
	Bitboard fatt = m_and(A,FileBB_A[StoX(s)]);
	fatt = _mm_andnot_si128(bitboard_occ_white,fatt);
	fatt = _mm_andnot_si128(POSITION->DYN->attack_black,fatt);  //
	mob = count_1s(fatt);
	valu += f_CheMove[mob];
	
    // 1, �쳵�ܹ������Է�. 
	if(m128_is_have_bit(m_and(A,KingAttackZone[bk]))){
		set_bit(ei.attackKingBoard,s);                  // ��һ����־, ���ڽ�����
	}

	if(bit_is_set(POSITION->DYN->black_xray,s)){
		//��Ҫ��һЩ,��Ϊ�������ǣ����.
		ei.attPoint[WHITECOLOR] -= Rook_CanNotMove_Att;
		continue;  // �������ǣ����
	}

	// ****************************************************************
	Bitboard ckatt = m_and(A,ei.attackKingCheCan[BLACKCOLOR]);
	if(m128_is_have_bit(ckatt)){  // �쳵�ܽ���

		set_bit(ei.attackKingBoard,s);  
		ei.kingAdjacentZoneAttacksCount[WHITECOLOR] ++;         // �쳵��ֱ�ӽ�

		// ��һ���ǲ��ǰ�ȫ�Ľ�
		if(have_bit(white_safe,ckatt)){
			ei.attPoint[WHITECOLOR] += RookSafeCheckBonus * count_1s(m_and(white_safe,ckatt));
		}

		//��һ���ǲ��ǽ���һ����,
		if(bit_is_set(A,rk) && StoX(s) == StoX(rk)){ //fen 4ka3/4aR3/2n5b/4p1N1p/p5b2/4R4/1r2P3P/2r1B4/4A1C2/c1BA1K3 w
			ei.attPoint[WHITECOLOR] += King_CheSameLineAtt;
		}

		// ��һ���ܲ����ݽ�
		if(m128_is_have_bit(m_and(POSITION->DYN->white_pao_null,A))){
			ei.attPoint[WHITECOLOR] = CheCanPaoNullCHeckPoint;
		}

		if(have_bit(A,bit_bk)){  // ���ڽ�����, ���һ��Ҫ����, ��Ϊ�����
			continue;
		}


		//���������ԭλ����û�ж����� 
		//fen 5kb2/4a4/3ab4/9/5R3/2r6/5r3/9/4A4/2B1KA3 b - - 0 0</
		//�����Ϊ���ڽ�����
		if(0x04 != bk || BShi_num() == 0){   // ������ԭλ����û�����ˣ�
			while(m128_is_have_bit(ckatt)){   
				int ckq = pop_1st_bit(&ckatt);
				if(WhiteSEE(POSITION,MOVE_FromTo(s,ckq)) > 0){
					if(StoX(ckq) == StoX(bk)){  // �������½�,
						ei.rcx += 2;
					}
					else{
						ei.rcy += 2;
					}
				}
				else{
					if(StoX(ckq) == StoX(bk)){
						ei.rcx++;
					}
					else{
						ei.rcy++;
					}
				}
			}
		} // ������ɱ�����		
     }
}

// ----------------------------------------------------------------------------
// �ڳ� **************************************************************
// ----------------------------------------------------------------------------
//che_check = 0;
for(int i = 0; i < BChe_num(); i++){
	int s = S90_from_piecelist(POSITION,BCHE,i);

	Bitboard A = ei.BcheAtt[i];
	// -------------------------------------------------------------------------------------------- 
	// 1. �ƶ����� Mobility
	// -------------------------------------------------------------------------------------------- 
	int mob; 
	Bitboard ratt = m_and(A,RankBB_A[StoY(s)]);
	ratt = _mm_andnot_si128(bitboard_occ_black,ratt);  
	ratt = _mm_andnot_si128(POSITION->DYN->attack_white,ratt);  //
	mob =  count_1s(ratt);
	valu -= r_CheMove[mob];  // �����ƶ��ķ�
	Bitboard fatt = m_and(A,FileBB_A[StoX(s)]);
	fatt = _mm_andnot_si128(bitboard_occ_black,fatt);
	fatt = _mm_andnot_si128(POSITION->DYN->attack_white,fatt);  //
	mob = count_1s(fatt);
	valu -= f_CheMove[mob];

	// 1, �ڳ��ܹ������Է�. 
	if(m128_is_have_bit(m_and(A,KingAttackZone[rk]))){
		set_bit(ei.attackKingBoard,s);                  // ��һ����־, ���ڽ�����
	}

	if(bit_is_set(POSITION->DYN->white_xray,s)){
		//��Ҫ��һЩ,��Ϊ�������ǣ����.
		ei.attPoint[BLACKCOLOR] -= Rook_CanNotMove_Att;
		continue;  // �������ǣ����
	}

	// ****************************************************************
    // �ڳ�
	Bitboard ckatt = m_and(A,ei.attackKingCheCan[WHITECOLOR]);
	if(m128_is_have_bit(ckatt)){

		set_bit(ei.attackKingBoard,s);  
		ei.kingAdjacentZoneAttacksCount[BLACKCOLOR] ++;         // �쳵��ֱ�ӽ�
		
		// ��һ���ǲ��ǰ�ȫ�Ľ�
		if(have_bit(black_safe,ckatt)){
			ei.attPoint[BLACKCOLOR] += RookSafeCheckBonus * count_1s(m_and(black_safe,ckatt));
		}

		//��һ���ǲ��ǽ���һ����,
		if(bit_is_set(A,bk) && StoX(s) == StoX(bk)){ //fen 4ka3/4aR3/2n5b/4p1N1p/p5b2/4R4/1r2P3P/2r1B4/4A1C2/c1BA1K3 w
			ei.attPoint[BLACKCOLOR] += King_CheSameLineAtt;
		}

		// ��һ���ܲ����ݽ�
		if(m128_is_have_bit(m_and(POSITION->DYN->black_pao_null,A))){
			ei.attPoint[BLACKCOLOR] += CheCanPaoNullCHeckPoint;
		}

		if(have_bit(A,bit_rk)){  // ���ڽ�����
			continue;
		}

		//���������ԭλ����û�ж�����fen 3a1k3/4a4/4b1C2/5RP1p/6b2/5r2P/rn4N2/4C4/3RK4/9 b - - 0 0
		if(0x55 != rk || RShi_num() == 0) {      // ������ԭλ		
			//ckatt = _mm_andnot_si128(BetweenBB[s][rk],ckatt); //ȥ����ͬ�����
			while(m128_is_have_bit(ckatt)){ 
				int ckq = pop_1st_bit(&ckatt);
				if(BlackSEE(POSITION,MOVE_FromTo(s,ckq)) > 0){
					if(StoX(ckq) == StoX(rk)){
						ei.bcx += 2;
					}
					else{
						ei.bcy += 2;
					}
				}
				else{//fen 2b1kr3/4R4/4b4/R1p5p/9/2P1n1B1P/P8/3r5/3N5/3K1A3 b - - 0 0
					if(StoX(ckq) == StoX(rk)){
						ei.bcx++;
					}
					else{
						ei.bcy++;
					}
				}
			}				
		}
	}		
}