
//point(opening,endgame) (((opening) << 16) + (endgame))
const static int LackShiAttackByChePoint[] = {
	(((0) << 0) + (0)), (((64) << 16) + (128)), (((128) << 16) + (256))
};
// fen 4ka3/rC3R3/2n1b3c/p3p3p/2b6/7RP/r8/4B4/4A4/2BAK4 b - - 0 25
// �ҶԷ����ˣ��Է��ж��������� 
switch(BShi_num()){
case 2:
	break;
case 1:
	// fen 4ka3/rC3R3/2n1b3c/p3p3p/2b6/7RP/r8/4B4/4A4/2BAK4 b - - 0 25
	// �ҶԷ����ˣ��Է��ж��������� 
	if(RChe_num() == 2){
		int shi = S90_from_piecelist(POSITION,BSHI,0);
		// ���������ܵ��Է����Ĺ��������ҷ�ֻ�н��ڱ������ͼӼ���
		int n = 0;
		for(int i = 0; i < RChe_num(); i++){
			if(bit_is_set(ei.RcheAtt[i],shi)){
				int s = S90_from_piecelist(POSITION,RCHE,i);
				if(WhiteSEE(POSITION,MOVE_FromTo(s,shi))){
					n++;
				}
			}
		}
		valu += LackShiAttackByChePoint[n];
	}
	break;
case 0:
	break;
}
// fen 4ka3/rC3R3/4b1n1c/p3p3p/2b6/8P/r6R1/4B4/4A4/2BAK4 w
// fen 4ka3/rC3R3/2n1b3c/p3p3p/2b6/7RP/r8/4B4/4A4/2BAK4 b - - 0 25
// fen 4ka1R1/rC3R3/2n1b3c/p3p3p/2b6/8P/r8/4B4/4A4/2BAK4 b
// �ҶԷ����ˣ��Է��ж��������� 
switch(RShi_num()){
case 2:
	break;
case 1:
	// fen 4ka3/rC3R3/2n1b3c/p3p3p/2b6/7RP/r8/4B4/4A4/2BAK4 b - - 0 25
	// �ҶԷ����ˣ��Է��ж��������� 
	if(BChe_num() == 2){
		////��һ���˵Ĺ���
		int shi = S90_from_piecelist(POSITION,RSHI,0);
		// ���������ܵ��Է����Ĺ��������ҷ�ֻ�н��ڱ������ͼӼ���
		int n = 0;
		for(int i = 0; i < BChe_num(); i++){
			if(bit_is_set(ei.BcheAtt[i],shi)){
				int s = S90_from_piecelist(POSITION,BCHE,i);
				if(BlackSEE(POSITION,MOVE_FromTo(s,shi))){
                   n++;
				}
			}
		}
		valu -= LackShiAttackByChePoint[n];
	}
	break;
case 0:
	break;
}