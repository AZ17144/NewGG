//#define TwoCheZhouJianPoint point(2,32)

// �쳵
for(int i = 0; i < RChe_num(); i++){
	int s = S90_from_piecelist(POSITION,RCHE,i);
	Bitboard A // 1. ���Ĺ���,Ҫ����һ��,��Ϊ���������߹���.
		=  rook_attacks_bb(s,_mm_andnot_si128(POSITION->byChessBB[RCHE],occ)); //rook_attacks_bb(s,occ);
	ei.RcheAtt[i] = A;
	POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,A);
	if(have_bit(A,bit_bk)){
		set_bit(POSITION->DYN->black_king_check,s);        // �ڽ���
	}
	//��������ܻص��Լ��ļ���,��Ҫ�۷�
	if(m128_is_have_bit(m_and(A,LowBB[0x4])) == FALSE){
		ei.attPoint[BLACKCOLOR] += Other_Che_Can_Not_back;
	}

	// ��һ�³��ǲ��ǿ�����
	if(m128_is_have_bit(
		m_and(A,UpBB[StoY(bk)+CHE_OPEN_SUB_LINE]))){
		//valu += my_che_open_score;
		ei.attPoint[WHITECOLOR] += CheOpenAtt;
		//�����Ҳ�����˽�����
		set_bit(ei.attackKingBoard,s); 
	}
}


// ----------------------------------------------------------------------------
// �ڳ� **************************************************************
// ----------------------------------------------------------------------------
//che_check = 0;
for(int i = 0; i < BChe_num(); i++){
	int s = S90_from_piecelist(POSITION,BCHE,i);
	Bitboard A // 1. ���Ĺ���,Ҫ����һ��,��Ϊ���������߹���.
		=  rook_attacks_bb(s,_mm_andnot_si128(POSITION->byChessBB[BCHE],occ)); //rook_attacks_bb(s,occ);
	ei.BcheAtt[i] = A;
	POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,A);
	if(have_bit(A,bit_rk)){
		set_bit(POSITION->DYN->white_king_check,s);        // �ڽ���
	}

	//��������ܻص��Լ��ļ���,��Ҫ�۷�
	if(m128_is_have_bit(m_and(A,UpBB[0x5])) == FALSE){
		ei.attPoint[WHITECOLOR]  += Other_Che_Can_Not_back;
	}

	// ��һ�³��ǲ��ǿ�����
	if(m128_is_have_bit(
		m_and(A,LowBB[StoY(rk)-CHE_OPEN_SUB_LINE]))){
		//valu -= my_che_open_score;
		ei.attPoint[BLACKCOLOR] += CheOpenAtt;
		set_bit(ei.attackKingBoard,s); 
	}

} // �ڳ� end

//if(che_check == 2){
//	if(StoY(rk) != 0x9){
//		valu -= TwoCheZhouJianPoint;
//	}
//}