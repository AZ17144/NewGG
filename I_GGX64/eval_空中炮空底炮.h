

    //***********************************************************
	// ���ڵ�����. (�п���,�׿���) Ҫ��һ��ȷ���ǲ��ǿ���
	//***********************************************************
    Bitboard bkp = ei.KongPaoBB; // fen rnbak3C/4a1r2/1c2b1nc1/p1p1p1p1p/9/9/P1P1P1P1P/1C7/9/RNBAKABNR w
	while(m128_is_have_bit(bkp)){
		int msq      = pop_1st_bit(&bkp);
		uint8 mchess = PB90(msq);
		if(FALSE){
		}
		else if(mchess == RPAO){  // �췽�п����ǿ�����,��յ���

			// ������Ǻ췽�׿���
			if(StoY(msq) == StoY(bk)){	

				if(ABS(StoX(msq) - 0x4) <= 1){
					continue;
				}

				if(ABS(StoX(msq) - StoX(bk)) >= 2){			// 
					// Ҫ�жϽ��ܲ��������ƶ�
					//fen 5a1nN/1R2a4/C2k5/p7p/2p3n2/4p3P/Pc3r3/3CB4/4A4/3A1KB2 w - - 0 0</
					if(ei.BKing_Info & KING_CAN_UP_DOWN){
						ei.attPoint[WHITECOLOR] +=  Di_Pao_att_point; 
					}
					else{
						ei.attPoint[WHITECOLOR] +=  Di_KongPao_att_point;   // ���ڼӹ�����	
					}
				}

				//��Ҫ�ж�һ���ǲ����ܵ��Է��Ĺ���
				if(bit_is_set(POSITION->DYN->attack_black,msq)){
					ei.attPoint[WHITECOLOR] -= Kong_Di_Pao_att_By_Other;
				}

			}
			// ����� �췽 ���п���
			else if(StoX(msq) == StoX(bk)){
				if(StoY(msq) <= 0x2){
					//fen 3C2b2/3k4C/2N2n3/3P5/8P/4cn3/9/2pAB4/4A4/4K1B2 w - - 0 0
					continue;
				}
				if(ABS(StoY(msq) - StoY(bk)) >= 2){ // ֻ������������ڲſ����ǿ���

					set_bit(ei.attackKingBoard,msq);                          // ��һ����־

					// Ҫ�жϽ��ܲ��������ƶ�
					//fen 5a1nN/1R2a4/C2k5/p7p/2p3n2/4p3P/Pc3r3/3CB4/4A4/3A1KB2 w - - 0 0</
					if(ei.BKing_Info & KING_CAN_RIGHT_LEFT){
						ei.attPoint[WHITECOLOR]  +=  KongPao_att_point[RChe_num()]/2;   // ���ڼӹ�����
					}
					else{
						ei.attPoint[WHITECOLOR]  +=  KongPao_att_point[RChe_num()];      // ���ڼӹ�����
					}
				}	
			}			
		}
		else if(mchess == BPAO){ // �ڷ��п����ǿ���

			// ������Ǻڵ׿���
			if(StoY(msq) == StoY(rk)){						
				if(ABS(StoX(msq) - 0x4) <= 1){
					continue;
				}
				if(ABS(StoX(msq) - StoX(rk)) >= 2){ // ֻ������������ڲſ����ǿ���
					// Ҫ�жϽ��ܲ��������ƶ�
					//fen 5a1nN/1R2a4/C2k5/p7p/2p3n2/4p3P/Pc3r3/3CB4/4A4/3A1KB2 w - - 0 0</
					if(ei.RKing_Info & KING_CAN_UP_DOWN){
						ei.attPoint[BLACKCOLOR] +=  Di_Pao_att_point; 
					}
					else{
						ei.attPoint[BLACKCOLOR] +=  Di_KongPao_att_point;   // ���ڼӹ�����	
					}					
				}
				//��Ҫ�ж�һ���ǲ����ܵ��Է��Ĺ���
				if(bit_is_set(POSITION->DYN->attack_white,msq)){
					ei.attPoint[BLACKCOLOR] -= Kong_Di_Pao_att_By_Other;
				}			
			}
			// ������Ǻ��п���
			else if(StoX(msq) == StoX(rk)){
				if(StoY(msq) >= 0x7){
					//fen 3C2b2/3k4C/2N2n3/3P5/8P/4cn3/9/2pAB4/4A4/4K1B2 w - - 0 0
					continue;
				}	
				if(ABS(StoY(msq) - StoY(rk)) >= 2){	

					// ����Է��ж���,ҲҪ��һЩ.
					set_bit(ei.attackKingBoard,msq);                          // ��һ����־

					// �ٸ��ݶԷ����������һЩ��
					if(ei.RKing_Info & KING_CAN_RIGHT_LEFT){
						ei.attPoint[BLACKCOLOR] +=  KongPao_att_point[BChe_num()]/2; 
					}
					else{
						ei.attPoint[BLACKCOLOR] +=  KongPao_att_point[BChe_num()];      // ���ڼӹ�����
					}
				}		
			}
		}
	}