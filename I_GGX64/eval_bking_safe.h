

// �췽������˧

//Bitboard undefended;
attackCounter = count_1s(m_and(ei.attackKingBoard,bitboard_occ_white));

if(attackCounter >= 2){
	undefended = m_and(POSITION->DYN->attack_white,attacks_by_rpawn_rk(bk));

	Bitboard protect = m128_bb_or_bb(ei.BShiXiangAtt,  // ���ѵı����ܱ����Լ����Ͻ�.
		m128_bb_or_bb(ei.BmaAtt[0],
		m128_bb_or_bb(ei.BmaAtt[1],
		m128_bb_or_bb(ei.BPaoAtt[0],
		m128_bb_or_bb(ei.BPaoAtt[1],
		m128_bb_or_bb(ei.BcheAtt[0],ei.BcheAtt[1]))))));

	undefended = _mm_andnot_si128(protect,undefended);  //print_bb(undefended);

	ei.attPoint[WHITECOLOR] += 6 * (ei.kingAdjacentZoneAttacksCount[WHITECOLOR] + count_1s(undefended));

	// ���ǲ��Ǹ���������
	Bitboard att = m_and(ei.attackKingBoard,bitboard_white_pawn);

	if(m128_is_have_bit(att)){
	    ei.attPoint[WHITECOLOR] += PawnAttWeight * count_1s(att);
	}

	// ���ǲ��Ǹ���������
	att = m_and(ei.attackKingBoard,bitboard_white_che);
	if(m128_is_have_bit(att)){
		int che_num = count_1s(att);
		ei.attPoint[WHITECOLOR] += CheAttWeight * che_num;
		// fen 3ak1b2/4a4/1R2b1n2/4p1C1p/p5P2/P1B4r1/4P3P/N4R3/4AK3/2BA3rc w - 
		//if(num == 2){

		//}
	}

	// ���ǲ��Ǹ�������
	att = m_and(ei.attackKingBoard,bitboard_white_ma);
	if(m128_is_have_bit(att)){
		int ma_num = count_1s(att);
	    ei.attPoint[WHITECOLOR] += MaAttWeight * ma_num;
	}

	// ���ǲ��Ǹ��ڹ�����
	att = m_and(ei.attackKingBoard,bitboard_white_pao);
	if(m128_is_have_bit(att)){
		int pao_num = count_1s(att);
	    ei.attPoint[WHITECOLOR] += PaoAttWeight * pao_num;
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