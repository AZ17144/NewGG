	   
        // ���
		Bitboard p = bitboard_white_pawn;
		Bitboard B = p;
		//Bitboard Btmp;
		// ��ǰһ��.
		B = _mm_andnot_si128(_mm_load_si128((__m128i*)Rank0BB),B);
		m_Rsf(B,9);
		ei.RpawnAtt = m128_bb_or_bb(ei.RpawnAtt,B);
		POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,B);	
		B = m_and(B,bit_bk);
		m_Lsf(B,9);	
		POSITION->DYN->black_king_check = m128_bb_or_bb(POSITION->DYN->black_king_check,B);
		// ���ӱ�	
		//fen 9/4k4/3a5/1P7/9/3N1R3/4r4/4Bn3/9/2BK1p3 w - - 0 0
		p = m_and(p,_mm_load_si128((__m128i*)RpawnOverBB));
		if(m128_is_have_bit(p)){
			B = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);  // ȥ�������
			m_Rsf(B,1);                   //���к������һ��
			ei.RpawnAtt = m128_bb_or_bb(ei.RpawnAtt,B);
			POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,B);
			B = m_and(B,bit_bk);
			m_Lsf(B,1);		
			POSITION->DYN->black_king_check = m128_bb_or_bb(POSITION->DYN->black_king_check,B);
			//
			B = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
			m_Lsf(B,1);                   //���к������һ��
			ei.RpawnAtt = m128_bb_or_bb(ei.RpawnAtt,B);
			POSITION->DYN->attack_white = m128_bb_or_bb(POSITION->DYN->attack_white,B);
			B = m_and(B,bit_bk);
			m_Rsf(B,1);
			POSITION->DYN->black_king_check = m128_bb_or_bb(POSITION->DYN->black_king_check,B);

			// �õ��䱣���Լ������ӵķ� ei.RpawnAtt = m128_bb_or_bb(ei.RpawnAtt,B);
			//ei.RPaoMaShiXiangAtt = m128_bb_or_bb(ei.RPaoMaShiXiangAtt,ei.RpawnAtt);
		
			B = m_and(ei.RpawnAtt,occ);
			while (m128_is_have_bit(B))	{
				int p1 = pop_1st_bit(&B);
				valu += Point_R_pawn_Att_Score[PB90(p1)];
			}	
        
		}	

		// ******************************************************************************
		// black ��
		p = bitboard_black_pawn;
		B = p;
		// ��ǰһ��.
		B = _mm_andnot_si128(_mm_load_si128((__m128i*)Rank9BB),B);
		m_Lsf(B,9);
		ei.BpawnAtt = m128_bb_or_bb(ei.BpawnAtt,B);
		POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,B);
		B = m_and(B,bit_rk);
		m_Rsf(B,9);
		POSITION->DYN->white_king_check = m128_bb_or_bb(POSITION->DYN->white_king_check,B);
		// ���ӱ�	
		p = m_and(p,_mm_load_si128((__m128i*)BpawnOverBB));
		if(m128_is_have_bit(p)){
			
			B = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);  // ȥ�������
			m_Rsf(B,1);                   //���к������һ��
			ei.BpawnAtt = m128_bb_or_bb(ei.BpawnAtt,B);
			POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,B);
			B = m_and(B,bit_rk);
			m_Lsf(B,1);
			POSITION->DYN->white_king_check = m128_bb_or_bb(POSITION->DYN->white_king_check,B);
			//
			B = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
			m_Lsf(B,1);                   //���к������һ��
			ei.BpawnAtt = m128_bb_or_bb(ei.BpawnAtt,B);
			POSITION->DYN->attack_black = m128_bb_or_bb(POSITION->DYN->attack_black,B);
			B = m_and(B,bit_rk);
			m_Rsf(B,1);
			POSITION->DYN->white_king_check = m128_bb_or_bb(POSITION->DYN->white_king_check,B);


			//ei.BPaoMaShiXiangAtt = m128_bb_or_bb(ei.BPaoMaShiXiangAtt,ei.BpawnAtt);
			// �õ����䱣���Լ������ӵķ�
			
			B = m_and(ei.BpawnAtt,occ);
			while (m128_is_have_bit(B))	{
				int p1 = pop_1st_bit(&B);
			    valu -= Point_B_pawn_Att_Score[PB90(p1)];
			}
           
		}

		