//***********************************************************
	// StringBB ǣ�Ƶ�������, ���ֻ���۳�X���������� 
	// �ǲ��ǻ�Ҫ������ 0 X ��������(�����Ҫ��,������3������������)
	// ��Ҫ�ж�������ǲ����б���,����б���,�Ͳ���ǣ����???
	//***********************************************************
    //fen 4kabr1/4a2c1/9/p3P1P1p/2b4R1/P8/4P3P/4B1N2/4Ac3/4KA3 w - - 0 0
//Next_String:
//	while(m128_is_have_bit(ei.StringBB)){
//		int t = pop_1st_bit(&ei.StringBB); //  
//		if(PIECE_SIDE(PB90(t)) == WHITE_TO_MOVE){
//			// ���˳�,���ı���,���������ı���
//			//if(m128_is_have_bit(
//			//	m_and(SetMaskBB[t],
//			//	m128_bb_or_bb(ei.attackedBy[RPAO],
//			//	m128_bb_or_bb(ei.attackedBy[RMA],
//			//	m128_bb_or_bb(ei.attackedBy[RSHI],
//			//	m128_bb_or_bb(ei.attackedBy[RXIANG],
//			//	ei.attackedBy[RPAWN]))))))){
//			//		continue;
//			//}
//
//			//1. ��������ܽ���, �Ͳ���ǣ��
//
//
//			//�ٿ�һ��������ӵ���Χ���
//			//����������ĳ��и�,���������û�б�ǣ��
//			Bitboard TBche = rook_attacks_bb(t,occ);
//			TBche = m_and(TBche,bitboard_white_che);	
//			while(m128_is_have_bit(TBche)){
//				int che = pop_1st_bit(&TBche);
//				if(bit_is_set(POSITION->DYN->attack_white,che)){
//                    goto Next_String;
//				}
//			}
//		}
//		else{
//			//if(m128_is_have_bit(
//			//	m_and(SetMaskBB[t],
//			//	m128_bb_or_bb(ei.attackedBy[BPAO],
//			//	m128_bb_or_bb(ei.attackedBy[BMA],
//			//	m128_bb_or_bb(ei.attackedBy[BSHI],
//			//	m128_bb_or_bb(ei.attackedBy[BXIANG],
//			//	ei.attackedBy[BPAWN]))))))){   // �������������ڱ���,������ǣ��
//			//		continue;
//			//}
//			//�ٿ�һ��������ӵ���Χ���
//			//����������ĳ��и�,���������û�б�ǣ��
//			Bitboard TBche = rook_attacks_bb(t,occ);
//			TBche = m_and(TBche,bitboard_black_che);
//			while(m128_is_have_bit(TBche)){
//				int che = pop_1st_bit(&TBche);
//				if(bit_is_set(POSITION->DYN->attack_black,che)){
//					goto Next_String;
//				}
//			} //fen 3ak4/4a4/9/5r3/P5b2/2B6/1R3N1r1/3AB3p/4AKR2/c8 b - - 0 0
//		}		
//		valu -= Point_StringScoreByChe[PB90(t)]; //board_display(POSITION,"che string\n");
//	}