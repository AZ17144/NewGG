

// 1. ���ۺڷ�������, ȥ�˶Է���,��,�ౣ��������
// 2. ҲҪȥ���Լ��ı���.
Bitboard weakEnemies = _mm_andnot_si128(
	m128_bb_or_bb(ei.BpawnAtt,ei.BShiXiangAtt),  // ȥ�˱�,����
	m_and(
	_mm_andnot_si128(bitboard_black_pawn,bitboard_occ_black),
	POSITION->DYN->attack_white));

if(m128_is_have_bit(weakEnemies)){
	Bitboard b;
	// ����,�����ڹ���
	b = m_and(ei.RShiXiangAtt,weakEnemies);	
	while(m128_is_have_bit(b)){
		int sq2    = pop_1st_bit(&b);
		valu += SHI_XIANG_ThreatBonus[PIECE_TYPE(PB90(sq2))];
	}
	// ���
	b = m_and(ei.RpawnAtt,weakEnemies);	
	while(m128_is_have_bit(b)){
		int sq2    = pop_1st_bit(&b);
		valu += PAWN_ThreatBonus[PIECE_TYPE(PB90(sq2))];
	}
	// ����, ���ӵ��Ա���Ҳ��һ��?
	for(int i = 0; i < RPao_num(); i++){
		b = m_and(ei.RPaoAtt[i],weakEnemies);	
		while(m128_is_have_bit(b)){
			int sq2    = pop_1st_bit(&b);
			valu += PAO_ThreatBonus[PIECE_TYPE(PB90(sq2))];
		}
	}
	// ����
	for(int i = 0; i < RMa_num(); i++){
		b = m_and(ei.RmaAtt[i],weakEnemies);	
		while(m128_is_have_bit(b)){
			int sq2    = pop_1st_bit(&b);
			valu += MA_ThreatBonus[PIECE_TYPE(PB90(sq2))];
		}
	}
	// �쳵
	for(int i = 0; i < RChe_num(); i++){
		b = m_and(ei.RcheAtt[i],weakEnemies);	
		while(m128_is_have_bit(b)){
			int sq2    = pop_1st_bit(&b);
			valu += CHE_ThreatBonus[PIECE_TYPE(PB90(sq2))];
		}
	}
}


// 1. ���ۺ췽������, ȥ�˶Է���,��,�ౣ��������
weakEnemies = _mm_andnot_si128(
	m128_bb_or_bb(ei.RpawnAtt,ei.RShiXiangAtt),  // ȥ�˱�,����
	m_and(
	_mm_andnot_si128(bitboard_white_pawn,bitboard_occ_white),POSITION->DYN->attack_black));

if(m128_is_have_bit(weakEnemies)){
	Bitboard b;
	// ����,�����ڹ���
	b = m_and(ei.BShiXiangAtt,weakEnemies);	
	while(m128_is_have_bit(b)){
		int sq2    = pop_1st_bit(&b);
		valu -= SHI_XIANG_ThreatBonus[PIECE_TYPE(PB90(sq2))];
	}
	// �ڱ�
	b = m_and(ei.BpawnAtt,weakEnemies);	
	while(m128_is_have_bit(b)){
		int sq2    = pop_1st_bit(&b);
		valu -= PAWN_ThreatBonus[PIECE_TYPE(PB90(sq2))];
	}
	// ����, ���ӵ��Ա���Ҳ��һ��?
	for(int i = 0; i < BPao_num(); i++){
		b = m_and(ei.BPaoAtt[i],weakEnemies);	
		while(m128_is_have_bit(b)){
			int sq2    = pop_1st_bit(&b);
			valu -= PAO_ThreatBonus[PIECE_TYPE(PB90(sq2))];
		}
	}
	// ����
	for(int i = 0; i < BMa_num(); i++){
		b = m_and(ei.BmaAtt[i],weakEnemies);	
		while(m128_is_have_bit(b)){
			int sq2    = pop_1st_bit(&b);
			valu -= MA_ThreatBonus[PIECE_TYPE(PB90(sq2))];
		}
	}
	// �ڳ�
	for(int i = 0; i < BChe_num(); i++){
		b = m_and(ei.BcheAtt[i],weakEnemies);	
		while(m128_is_have_bit(b)){
			int sq2    = pop_1st_bit(&b);
			valu -= CHE_ThreatBonus[PIECE_TYPE(PB90(sq2))];
		}
	}
}