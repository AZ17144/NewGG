
    // *************************************************************
	// ��һ�º���ɹ��ӵ�����
    // *************************************************************

	Bitboard NotB;

	//1, ȥ�˵��ߵı�
	NotB = _mm_load_si128((__m128i*)Rank0BB);
	B = _mm_andnot_si128(LowBB[0x6],
		_mm_andnot_si128(UpBB[0x3],POSITION->DYN->attack_black)); 
	NotB = m128_bb_or_bb(NotB,B);
	m_Lsf(B,9);
	NotB = m128_bb_or_bb(NotB,B);
	m_Lsf(B,9);
	NotB = m128_bb_or_bb(NotB,B);
	//print_bb(NotB);
	p = _mm_andnot_si128(NotB,bitboard_white_pawn);
	ei.rcan = count_1s(p);

	NotB = _mm_load_si128((__m128i*)Rank9BB);
	B = _mm_andnot_si128(UpBB[0x3],
		_mm_andnot_si128(LowBB[0x6],POSITION->DYN->attack_white));
	NotB = m128_bb_or_bb(NotB,B);
	m_Rsf(B,9);
	NotB = m128_bb_or_bb(NotB,B);
	m_Rsf(B,9);
	NotB = m128_bb_or_bb(NotB,B);
	//print_bb(NotB);
	p = _mm_andnot_si128(NotB,bitboard_black_pawn);
	ei.bcan = count_1s(p);


	ei.evscore += ei.rcan * PawnCanAddByChe[RChe_num()][BChe_num()];
	ei.evscore -= ei.bcan * PawnCanAddByChe[BChe_num()][RChe_num()];

	//if(FALSE){
	//}
	//else if(pMat->searchInfo16 & CK_R_12Che_B_NoChe){	// �췽�г�,�ڷ�û�г�
	//	ei.evscore += RChe_num() * rcan * 32;
	//	ei.evscore -= bcan * 16;
	//}
	//else if(pMat->searchInfo16 & CK_B_12Che_R_NoChe){	// �ڷ��г�,�췽û�г�
	//	ei.evscore -= BChe_num() * bcan * 32;
	//	ei.evscore += rcan * 16;
	//}
	//else if(pMat->searchInfo16 & CK_R_NoChe_B_NoChe){	// ˫��û�г�
	//	ei.evscore += rcan * 32;
	//	ei.evscore -= bcan * 32;
	//}	

