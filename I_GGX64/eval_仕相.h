
// ����
for(int i = 0; i < RXiang_num(); i++){
	int s = S90_from_piecelist(POSITION,RXIANG,i);
	// �������౻��ǣ����,�Ͳ�������
	if(bit_is_set(POSITION->DYN->black_xray,s)){
		continue;
	}
	Bitboard A = xiang_attacks_bb(s,occ);
	ei.RShiXiangAtt = m128_bb_or_bb(ei.RShiXiangAtt,A);
	POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,A); 

	// �õ��ౣ���Լ������ӵķ�
	A = m_and(A,occ);
	while (m128_is_have_bit(A))	{
		int p1 = pop_1st_bit(&A);
		valu += Point_R_XianProtectPoint[PB90(p1)];
	}
}

// black ��
for(int i = 0; i < BXiang_num(); i++){
	int s = S90_from_piecelist(POSITION,BXIANG,i);
	// �������౻��ǣ����,�Ͳ�������
	if(bit_is_set(POSITION->DYN->white_xray,s)){
		continue;
	}
	Bitboard A = xiang_attacks_bb(s,occ);
	ei.BShiXiangAtt = m128_bb_or_bb(ei.BShiXiangAtt,A);
	POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,A); 

	// �õ��ౣ���Լ������ӵķ�
	A = m_and(A,occ);
	while (m128_is_have_bit(A))	{
		int p1 = pop_1st_bit(&A);
		valu -= Point_B_XianProtectPoint[PB90(p1)];
	}
}

for(int i = 0; i < RShi_num(); i++){
	int s = S90_from_piecelist(POSITION,RSHI,i);
	// �������˱���ǣ����,�Ͳ�������
	if(bit_is_set(POSITION->DYN->black_xray,s)){
		continue;
	}
	Bitboard A = shi_attacks(s);
	ei.RShiXiangAtt = m128_bb_or_bb(ei.RShiXiangAtt,A);
	POSITION->DYN->attack_white 	= m128_bb_or_bb(POSITION->DYN->attack_white,A); 
}

for(int i = 0; i < BShi_num(); i++){
	int s = S90_from_piecelist(POSITION,BSHI,i);
	// �������˱���ǣ����,�Ͳ�������
	if(bit_is_set(POSITION->DYN->white_xray,s)){
		continue;
	}
	Bitboard A = shi_attacks(s);
	ei.BShiXiangAtt = m128_bb_or_bb(ei.BShiXiangAtt,A);
	POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,A); 
}





