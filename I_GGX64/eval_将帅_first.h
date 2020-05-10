

	rk = RKpos();
	bk = BKpos();
	occ = POSITION->byWhiteBlack;
	bit_rk = SetMaskBB[rk];
	bit_bk = SetMaskBB[bk];	


	valu += POSITION->DYN->statico;  // ����������ַ���оַ� value = (DYNAMIC->statik) + (PAWN_VALUE->points);
	
	//stringBeChe = _mm_setzero_si128();
	POSITION->DYN->white_xray = _mm_setzero_si128();
	POSITION->DYN->black_xray = _mm_setzero_si128();

	POSITION->DYN->black_pao_null = _mm_setzero_si128();        // �ڿɳ齫�����
	POSITION->DYN->white_pao_null = _mm_setzero_si128();        // 

	POSITION->DYN->black_king_check = _mm_setzero_si128();      // ���������
	POSITION->DYN->white_king_check = _mm_setzero_si128();

	
	//***********************************************************
	// �ڽ�
	//*********************************************************** 
	POSITION->DYN->attack_black = one_bpawn_bk_attacks(bk);   // 

	ei.attackKingCheCan[BLACKCOLOR] = rook_attacks_bb(bk,occ);            // �Է��ĳ��ܽ��������	
	// �Խ����
	if(m128_is_have_bit(m_and(ei.attackKingCheCan[BLACKCOLOR],bit_rk))){ // ��һ���ǲ��ǶԽ���
		POSITION->DYN->black_king_check = bit_rk;  // �Խ�
		POSITION->DYN->white_king_check = bit_bk;
	}
	
	// ������ж��ǲ��ǶԷ��п���,(������)

	// �ٿ�һ���ǲ����к��ڣ���Ϊ���Ե���������Ҳ��ǿ����
	Bitboard kPao = m_and(ei.attackKingCheCan[BLACKCOLOR],bitboard_white_pao);
	if(m128_is_have_bit(kPao)){
		ei.KongPaoBB = m128_bb_or_bb(ei.KongPaoBB,kPao);
		while(m128_is_have_bit(kPao)){
			int pao = pop_1st_bit(&kPao);
			POSITION->DYN->white_pao_null = m128_bb_or_bb(POSITION->DYN->white_pao_null,
				BetweenBB[pao][bk]);
		}
	}

	ei.attackKingMaCan[BLACKCOLOR]   = king_to_ma_attacks_bb(bk,occ);       // �Է������ܽ��������
	ei.attackKingPaoCan[BLACKCOLOR]  = pao_eat_attacks_bb(bk,occ);          // �Է������ܽ��������	

	//***********************************************************
	// �콫
	//***********************************************************

    POSITION->DYN->attack_white = one_rpawn_rk_attacks(rk);            // ���Ŀɹ�����   

	ei.attackKingCheCan[WHITECOLOR] = rook_attacks_bb(rk,occ);            // �Է��ĳ��ܽ��������

	if(ABS(StoX(rk) - StoX(bk)) <= 1){  // ���뽫���໥�����ԡ�
		POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,
			m_and(ei.attackKingCheCan[BLACKCOLOR],KingKingAttBB[rk]));  
		POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,
			m_and(ei.attackKingCheCan[WHITECOLOR],KingKingAttBB[bk]));	
	}

	// �ٿ�һ���ǲ����к��ڣ���Ϊ���Ե���������Ҳ��ǿ����
	kPao = m_and(ei.attackKingCheCan[WHITECOLOR],bitboard_black_pao);
	if(m128_is_have_bit(kPao)){
		ei.KongPaoBB = m128_bb_or_bb(ei.KongPaoBB,kPao);
		while(m128_is_have_bit(kPao)){
			int pao = pop_1st_bit(&kPao);
			POSITION->DYN->black_pao_null = m128_bb_or_bb(POSITION->DYN->black_pao_null,
				BetweenBB[pao][rk]);  // �õ��ɿ��ڵĽ������
		}
	}	

	ei.attackKingMaCan[WHITECOLOR]  = king_to_ma_attacks_bb(rk,occ);       // �Է������ܽ��������
	ei.attackKingPaoCan[WHITECOLOR] = pao_eat_attacks_bb(rk,occ);          // �Է������ܽ��������


	// ������һ�ºڳ���˧�Ĺ�ϵ
	BString = m_and(ei.attackKingPaoCan[WHITECOLOR],bitboard_black_che);
	while(m128_is_have_bit(BString)){
		int che = pop_1st_bit(&BString);
		Bitboard p = m_and(BetweenBB[rk][che],occ);
		int x   = pop_1st_bit(&p);
		// Xray
		set_bit(POSITION->DYN->black_xray,x);
		xray_black_list[x] = che;
	}
	// ������һ�º쳵��˧�Ĺ�ϵ
	BString = m_and(ei.attackKingPaoCan[BLACKCOLOR],bitboard_white_che);
	while(m128_is_have_bit(BString)){
		int che = pop_1st_bit(&BString);
		Bitboard p = m_and(BetweenBB[bk][che],occ);
		int x   = pop_1st_bit(&p);
		// Xray
		set_bit(POSITION->DYN->white_xray,x);
		xray_white_list[x] = che;
	}

	// ������һ�º�����˧�Ĺ�ϵ, ����,����
	BString = m_and(pao_super_attacks_bb(rk,occ), bitboard_black_pao);
	while(m128_is_have_bit(BString)){
		int pao = pop_1st_bit(&BString);
		Bitboard p2_bb = m_and(BetweenBB[pao][rk],
			m_and(ei.attackKingPaoCan[WHITECOLOR],occ));  // pao_eat_att = A
		int p2 = pop_1st_bit(&p2_bb);
		Bitboard p1_bb = m_and(BetweenBB[rk][p2],occ);
		int p1 = pop_1st_bit(&p1_bb);

		// xray
		set_bit(POSITION->DYN->black_xray,p1);
		set_bit(POSITION->DYN->black_xray,p2);

		xray_black_list[p1] = pao;
		xray_black_list[p2] = pao;
		// ������������(����˨), ����, ������,��....
		set_bit(ei.ZhongDiPaoBB,pao);  // board_display(board,"���ڻ����\n",stdout);

		//����Щ����һ�������ı�־ 
		set_bit(ei.attackKingBoard,pao);
	}

	// ������һ�º������˧�Ĺ�ϵ, ����,����
	BString = m_and(pao_super_attacks_bb(bk,occ), bitboard_white_pao);
	while(m128_is_have_bit(BString)){
		int pao = pop_1st_bit(&BString);
		Bitboard p2_bb = m_and(BetweenBB[pao][bk],
			m_and(ei.attackKingPaoCan[BLACKCOLOR],occ));  // pao_eat_att = A
		int p2 = pop_1st_bit(&p2_bb);
		Bitboard p1_bb = m_and(BetweenBB[bk][p2],occ);
		int p1 = pop_1st_bit(&p1_bb);

		// xray
		set_bit(POSITION->DYN->white_xray,p1);
		set_bit(POSITION->DYN->white_xray,p2);

		xray_white_list[p1] = pao;
		xray_white_list[p2] = pao;
		// ������������(����˨), ����, ������,��....
		set_bit(ei.ZhongDiPaoBB,pao);  // board_display(board,"���ڻ����\n",stdout);

		set_bit(ei.attackKingBoard,pao);
	}

