
	//***********************************************************
	// ���� ������, ����, ��Ϊ�ڿ���ǣ�ƶԷ��ĳ�,��,
	//***********************************************************
	for(int i = 0; i < RPao_num(); i++){
		int s = S90_from_piecelist(POSITION,RPAO,i);		
		// -------------------------------------------------------------------------------------------- 
		// 1. �ڵ���������, ���Ǹ��Ӵ���.
		// --------------------------------------------------------------------------------------------
		Bitboard A = pao_eat_attacks_bb(s,occ); 
		ei.RPaoAtt[i] = A;
		POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,A); 
		// �������
		if(have_bit(A,bit_bk)){
			set_bit(POSITION->DYN->black_king_check,s);      // �ڽ���
		}  
		// �ڵ�ǣ�Ʒŵ�����������.
	}  // rpao end
	//***********************************************************
	// ���� ������, ����, ��Ϊ�ڿ���ǣ�ƶԷ��ĳ�,��,
	//***********************************************************
	for(int i = 0; i < BPao_num(); i++){
		int s = S90_from_piecelist(POSITION,BPAO,i);
		Bitboard A = pao_eat_attacks_bb(s,occ); 
		ei.BPaoAtt[i] = A;
		POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,A); 
		// �������
		if(have_bit(A,bit_rk)){
			set_bit(POSITION->DYN->white_king_check,s);      // �ڽ���
		}	
	} // bpao end