
    // ����
	for(int i = 0; i < RMa_num(); i++){
		int s = S90_from_piecelist(POSITION,RMA,i);		
        Bitboard A =  ma_to_king_attacks_bb(s,occ);
		ei.RmaAtt[i] = A;
		POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,A); 
		if(have_bit(A,bit_bk)){
			set_bit(POSITION->DYN->black_king_check,s);      // �ڽ���
		}
		else{ // �õ������ϵ�����.
			if(have_bit(Ma_Pseudo_Att[s],bit_bk)){
			    int leg = maleg(s,bk);
				set_bit(POSITION->DYN->white_xray,leg);
				xray_white_list[leg] = s;	// ����Ѽ�¼���˹������λ��
			}
		}

		

//#ifdef USE_���ӵı�����
		A = m_and(A,occ);
		while(m128_is_have_bit(A)){
			int t = pop_1st_bit(&A);
			valu += Point_R_ma_Att_Score[PB90(t)]; // �����Լ������ӵĵ÷�
		}
//#endif
	}


	// ����
	for(int i = 0; i < BMa_num(); i++){
		int s = S90_from_piecelist(POSITION,BMA,i);
		Bitboard A =  ma_to_king_attacks_bb(s,occ);
		ei.BmaAtt[i] = A;
		POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,A); 
		if(have_bit(A,bit_rk)){
			set_bit(POSITION->DYN->white_king_check,s);      // �ڽ���
		}
		else{ // �õ������ϵ�����.
			if(have_bit(Ma_Pseudo_Att[s],bit_rk)){
				int leg = maleg(s,rk);
				set_bit(POSITION->DYN->black_xray,leg);
				xray_black_list[leg] = s;				
			}
		}

		// 

//#ifdef USE_���ӵı�����
		A = m_and(A,occ);
		while(m128_is_have_bit(A)){
			int t = pop_1st_bit(&A);
			valu -= Point_B_ma_Att_Score[PB90(t)]; // �����Լ������ӵĵ÷�
		}
//#endif

	} // black ma end

