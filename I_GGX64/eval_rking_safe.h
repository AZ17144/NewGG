

// �ڷ�������˧

Bitboard undefended;
int attackCounter = count_1s(m_and(ei.attackKingBoard,bitboard_occ_black));

if(attackCounter >= 2){
	undefended = m_and(POSITION->DYN->attack_black,attacks_by_bpawn_bk(rk));

	Bitboard protect = m128_bb_or_bb(ei.RShiXiangAtt,
		m128_bb_or_bb(ei.RmaAtt[0],
		m128_bb_or_bb(ei.RmaAtt[1],
		m128_bb_or_bb(ei.RPaoAtt[0],
		m128_bb_or_bb(ei.RPaoAtt[1],
		m128_bb_or_bb(ei.RcheAtt[0],ei.RcheAtt[1]))))));

	undefended = _mm_andnot_si128(protect,undefended);  //print_bb(undefended);

	ei.attPoint[BLACKCOLOR] += 6 * (ei.kingAdjacentZoneAttacksCount[BLACKCOLOR] + count_1s(undefended));

	// ���ǲ��Ǹ���������
	Bitboard att = m_and(ei.attackKingBoard,bitboard_black_pawn);
    ei.attPoint[BLACKCOLOR] += PawnAttWeight * count_1s(att);
	
	// ���ǲ��Ǹ���������
	att = m_and(ei.attackKingBoard,bitboard_black_che);
	if(m128_is_have_bit(att)){
		int che_num = count_1s(att);
	    ei.attPoint[BLACKCOLOR] += CheAttWeight * che_num;
	}

	// ���ǲ��Ǹ�������
	att = m_and(ei.attackKingBoard,bitboard_black_ma);
	if(m128_is_have_bit(att)){
		int ma_num = count_1s(att);
	    ei.attPoint[BLACKCOLOR] += MaAttWeight * ma_num;
	}

	// ���ǲ��Ǹ��ڹ�����
	att = m_and(ei.attackKingBoard,bitboard_black_pao);
	if(m128_is_have_bit(att)){
		int pao_num = count_1s(att);
	    ei.attPoint[BLACKCOLOR] += PaoAttWeight * pao_num;
	}

	// Analyse safe distance checks �����Է��Ľ����İ�ȫ��, ǰ����,���ѷ�������

	// �齫,�����ĵ÷�
	
}



//
//Bitboard white_safe = m_not(m128_bb_or_bb(bitboard_occ_white,
//	POSITION->DYN->attack_black));  // �췽�ɰ�ȫ�ߵ������,���ü���pao_NULL��
//Bitboard black_safe = m_not(m128_bb_or_bb(bitboard_occ_black,
//	POSITION->DYN->attack_white));  // �ڷ��ɰ�ȫ�ߵ������


	//Bitboard RmaAtt[2];                                  // �����м������
	//Bitboard BmaAtt[2];
	//Bitboard RcheAtt[2];
	//Bitboard BcheAtt[2];
	//Bitboard RPaoAtt[2];
	//Bitboard BPaoAtt[2];
	//Bitboard RPaoCheAtt[2];                              // �ڿ��ߵ������.
	//Bitboard BPaoCheAtt[2];
	//Bitboard RpawnAtt;
	//Bitboard BpawnAtt;

	//Bitboard RShiXiangAtt;      // ���˺���
	//Bitboard BShiXiangAtt;      // ���˺���