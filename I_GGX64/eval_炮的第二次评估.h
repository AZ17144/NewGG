for(int i = 0; i < RPao_num(); i++){
	
	int s = S90_from_piecelist(POSITION,RPAO,i);
	Bitboard A = ei.RPaoAtt[i];

	// 1, �ڳ��ӽ���, 
	Bitboard ckatt = m_and(bitboard_occ_black,
		m_and(A,ei.attackKingPaoCan[BLACKCOLOR]));
	if(m128_is_have_bit(ckatt)){  // �����ܳ��ӽ���
		ei.attPoint[WHITECOLOR] += PaoCan_Eat_Check;  
		// ��ȫ�ĳ��ӽ���
		if(have_bit(white_safe,ckatt)){
			ei.attPoint[WHITECOLOR] += PaoCan_Safe_Eat_Check;
			set_bit(ei.attackKingBoard,s);   
		}
	}
	// 2. �ڲ�����ֱ�ӽ���
	Bitboard B = _mm_andnot_si128(occ,rook_attacks_bb(s,occ));  // �ڲ��������ߵ������
	ckatt = m_and(B,ei.attackKingPaoCan[BLACKCOLOR]);
	if(m128_is_have_bit(ckatt)){  // �ڲ�����ֱ�ӽ���
		ei.attPoint[WHITECOLOR] += PaoCan_Direct_Check;  
		// ��ȫ�Ĳ����ӽ���
		if(have_bit(white_safe,ckatt)){
			ei.attPoint[WHITECOLOR] += PaoCan_Safe_Direct_Check;
			set_bit(ei.attackKingBoard,s);   
		}
	}

	// 3. �����ݽ�
	if(m128_is_have_bit(m_and(B,
		_mm_andnot_si128(BetweenBB[s][bk],POSITION->DYN->white_pao_null)))){
			ei.attPoint[WHITECOLOR] += PaoCan_TwoPao_Check;            // 3. �����ݽ�
		set_bit(ei.attackKingBoard,s);   
	}

	if(bit_is_set(PaoCanAttKing[bk],s)){                // ���ڼ����˽���.Ҫ���ڹ�����
		if(m128_is_have_bit(m_and(A,KingAttackZone[bk]))){
			set_bit(ei.attackKingBoard,s);                         // ��һ����־
			// ���ܿ��ƽ���
			ei.kingAdjacentZoneAttacksCount[WHITECOLOR] += 1;				
		}
		//// ����
		//if(m128_is_have_bit(m_and(B,KingAttackZone[bk]))){ // ����Ҳ���ڽ���
		//	set_bit(ei.attackKingBoard,s);                          // ��һ����־
		//}
	}
}

for(int i = 0; i < BPao_num(); i++){

	int s = S90_from_piecelist(POSITION,BPAO,i);
	Bitboard A = ei.BPaoAtt[i];

	// 1, �ڳ��ӽ���, 
	Bitboard ckatt = m_and(bitboard_occ_white,
		m_and(A,ei.attackKingPaoCan[WHITECOLOR]));
	if(m128_is_have_bit(ckatt)){  // ���ܳ��ӽ���
		ei.attPoint[BLACKCOLOR] += PaoCan_Eat_Check;  
		// ��ȫ�ĳ��ӽ���
		if(have_bit(black_safe,ckatt)){
			ei.attPoint[BLACKCOLOR] += PaoCan_Safe_Eat_Check;
			set_bit(ei.attackKingBoard,s);   
		}
	}
	// 2. �ڲ�����ֱ�ӽ���
	Bitboard B = _mm_andnot_si128(occ,rook_attacks_bb(s,occ));  // �ڲ��������ߵ������
	ckatt = m_and(B,ei.attackKingPaoCan[WHITECOLOR]);
	if(m128_is_have_bit(ckatt)){  // �ڲ�����ֱ�ӽ���
		ei.attPoint[BLACKCOLOR] += PaoCan_Direct_Check;  
		// ��ȫ�Ĳ����ӽ���
		if(have_bit(black_safe,ckatt)){
			ei.attPoint[BLACKCOLOR] += PaoCan_Safe_Direct_Check;
			set_bit(ei.attackKingBoard,s);   
		}
	}

	// 3. �����ݽ�
	if(m128_is_have_bit(m_and(B,
		_mm_andnot_si128(BetweenBB[s][rk],POSITION->DYN->black_pao_null)))){
			ei.attPoint[BLACKCOLOR] += PaoCan_TwoPao_Check;            // 3. �����ݽ�
			set_bit(ei.attackKingBoard,s);   
	}

	if(bit_is_set(PaoCanAttKing[rk],s)){                // ���ڼ����˽���.Ҫ���ڹ�����
		if(m128_is_have_bit(m_and(A,KingAttackZone[rk]))){
			set_bit(ei.attackKingBoard,s);                         // ��һ����־
			// ���ܿ��ƽ���
			ei.kingAdjacentZoneAttacksCount[BLACKCOLOR] += 1;				
		}
		//// ����
		//if(m128_is_have_bit(m_and(B,KingAttackZone[rk]))){ // ����Ҳ���ڽ���
		//	set_bit(ei.attackKingBoard,s);                          // ��һ����־
		//}
	}
}