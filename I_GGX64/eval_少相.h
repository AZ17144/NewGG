
//point(opening,endgame) (((opening) << 16) + (endgame))
const static int LackXiangAttackByCheMaPoint[] = {
	(((0) << 0) + (0)), (((32) << 16) + (96)), (((48) << 16) + (128))
};
// ����б�����Ҫ�ӷ�
const static int LackXiangAttackByCheMaPawnPoint =  (((16) << 16) + (48));

// fen 2b1ka3/4a4/9/p1N3R1p/2P3p2/4r3P/P3c4/4B4/4A4/3AK1B2 b - - 0 0
//ȱ���³�������
switch(RXiang_num()){
case 2:
	break;
case 1:
case 0:{ // �Է��г�������ˣ��ҷ�û�г������ڼ�
	Bitboard b1 = m_and(LowBB[0x4],
		m128_bb_or_bb(bitboard_white_che,
		m128_bb_or_bb(bitboard_white_ma,bitboard_white_pao)));
	if(m128_is_have_bit(b1) == 0){
		Bitboard yatt = m_and(bitboard_black_che,LowBB[0x4]);
		if(m128_is_have_bit(yatt)){
			yatt = m_and(bitboard_black_ma,LowBB[0x4]);
			if(m128_is_have_bit(yatt)){
				valu -= LackXiangAttackByCheMaPoint[RXiang_num()];
				yatt = m_and(bitboard_black_pawn,LowBB[0x4]);
				if(m128_is_have_bit(yatt)){
					valu -= LackXiangAttackByCheMaPawnPoint;
				}
			}
		}
	}
	   }
	break;
default:
	break;
}
// fen 2b1ka3/4a4/9/p1N3R1p/2P3p2/4r3P/P3c4/4B4/4A4/3AK1B2 b - - 0 0
// fen 2b1ka3/4a4/9/p1N3R1p/2P3p2/5r2P/P3c4/4B4/4A4/3AK1B2 b (58,
//ȱ���³�������
switch(BXiang_num()){
case 2:
	break;
case 1:
case 0:{ // �Է��г�������ˣ��ҷ�û�г������ڼ�
	Bitboard b1 = m_and(UpBB[0x5],
		m128_bb_or_bb(bitboard_black_che,
		m128_bb_or_bb(bitboard_black_ma,bitboard_black_pao)));
	if(m128_is_have_bit(b1) == 0){
		Bitboard yatt = m_and(bitboard_white_che,UpBB[0x5]);
		if(m128_is_have_bit(yatt)){
			yatt = m_and(bitboard_white_ma,UpBB[0x5]);
			if(m128_is_have_bit(yatt)){
				valu += LackXiangAttackByCheMaPoint[BXiang_num()];
				yatt = m_and(bitboard_white_pawn,UpBB[0x5]);
				if(m128_is_have_bit(yatt)){
					valu += LackXiangAttackByCheMaPawnPoint;
				}
			}
		}
	}
		}
	break;
default:
	break;
}