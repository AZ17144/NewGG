
//����������1.�췽�����߶������� 2.�ڷ��ĳ齫 ʱ
//set_bit(POSITION->DYN->black_xray,msq);
//xray_black_list[msq] = s;

//����������1.�ڷ������߶������� 2.�췽�ĳ齫 ʱ

#define BCanNotMove_attNum GetWhiteAtt_SQcount_CheMaPaoPawn(POSITION,&ei,msq)

CannotMove = POSITION->DYN->white_xray;
while(m128_is_have_bit(CannotMove)){	
	int msq     = pop_1st_bit(&CannotMove);
	int s       = xray_white_list[msq];

	//ֻ�кڷ���Ҫ����
	//int attNum  = GetWhiteAtt_SQcount_CheMaPaoPawn(POSITION,&ei,msq);

	// 1, ���ܶ�, 
	switch(PB90(msq)){
	// �ڷ������߶�����
	//=======================================
	case BPAWN:
		// �ٿ�һ���Ǹ��Ǹ�ǣ����.
		switch(PB90(s)){
		case RCHE:  // �ڳ� ��� ��˧
			ei.attPoint[WHITECOLOR] += att_Che_String[BCanNotMove_attNum]/2;
			break;
		case RPAO:  // ���� X ��� ��˧
			ei.attPoint[WHITECOLOR] += att_Pao_String[BCanNotMove_attNum]/2;
			break;
		case RMA:   // ���� ��� ��˧  // ���������
			ei.attPoint[WHITECOLOR] += att_Ma_String[BCanNotMove_attNum]/2;
			break;
		}
		break;
	//=======================================
	case BMA:
		// �ٿ�һ���Ǹ��Ǹ�ǣ����.
		switch(PB90(s)){
		case RCHE:  // �ڳ�_����_��˧
			ei.attPoint[WHITECOLOR] += att_�ڳ�_����_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Che_String[BCanNotMove_attNum];
			break;
		case RPAO: // ����_����_��˧
			ei.attPoint[WHITECOLOR] += att_����_����_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Pao_String[BCanNotMove_attNum];
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_����_����_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Ma_String[BCanNotMove_attNum];
			valu += att_Ma_String_Valu[BCanNotMove_attNum];
			break;
		}
		break;
	//=======================================
	case BPAO:
		// �ٿ�һ���Ǹ��Ǹ�ǣ����.
		switch(PB90(s)){ 
		case RCHE:    // �ڳ�_����_��˧
			ei.attPoint[WHITECOLOR] += att_�ڳ�_����_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Che_String[BCanNotMove_attNum];
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_����_����_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Pao_String[BCanNotMove_attNum];
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_����_����_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Ma_String[BCanNotMove_attNum];
			valu += att_Ma_String_Valu[BCanNotMove_attNum];
			break;
		}
		break;
	//=======================================
	case BCHE:
		// �ٿ�һ���Ǹ��Ǹ�ǣ����.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_�ڳ�_�쳵_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Che_String[BCanNotMove_attNum];
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_����_�쳵_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Pao_String[BCanNotMove_attNum];
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_����_�쳵_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Ma_String[BCanNotMove_attNum];
			valu += att_Ma_String_Valu[BCanNotMove_attNum];
			break;
		}
		break;
	//=======================================
	case BSHI:
		// �ٿ�һ���Ǹ��Ǹ�ǣ����.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_�ڳ�_����_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Che_String[BCanNotMove_attNum]/2;
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_����_����_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Pao_String[BCanNotMove_attNum]/2;
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_����_����_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Ma_String[BCanNotMove_attNum]/2;
			break;
		}
		break;
	//=======================================
	case BXIANG:
		// �ٿ�һ���Ǹ��Ǹ�ǣ����.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_�ڳ�_����_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Che_String[BCanNotMove_attNum]/2;
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_����_����_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Pao_String[BCanNotMove_attNum]/2;
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_����_����_��˧_string;
			ei.attPoint[WHITECOLOR] += att_Ma_String[BCanNotMove_attNum]/2;
			break;
		}
		break;

	//***************************************
	case RPAWN:
		// �ٿ�һ���Ǹ��Ǹ��ں���齫��.
		if(StoY(msq) <= 0x4){
			switch(PB90(s)){
			case RCHE:
				ei.attPoint[WHITECOLOR] += att_�ڳ�_����_��˧_zhou;
				break;
			case RPAO:
				ei.attPoint[WHITECOLOR] += att_����_����_��˧_zhou;
				break;
			case RMA:
				ei.attPoint[WHITECOLOR] += att_����_����_��˧_zhou;
				break;
			}
		}
		break;
	//***************************************
	case RMA:
		// �ٿ�һ���Ǹ��Ǹ��ں���齫��.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_�ڳ�_����_��˧_zhou;
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_����_����_��˧_zhou;
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_����_����_��˧_zhou;
			break;
		}
		break;
	//***************************************
	case RPAO:
		// �ٿ�һ���Ǹ��Ǹ��ں���齫��.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_�ڳ�_����_��˧_zhou;
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_����_����_��˧_zhou;
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_����_����_��˧_zhou;
			break;
		}
		break;
	//***************************************
	case RCHE:
		// �ٿ�һ���Ǹ��Ǹ��ں���齫��.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_�ڳ�_�ڳ�_��˧_zhou;
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_����_�ڳ�_��˧_zhou;
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_����_�ڳ�_��˧_zhou;
			break;
		}
		break;
	//***************************************
	case RSHI:
		// �ٿ�һ���Ǹ��Ǹ��ں���齫��.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_�ڳ�_��ʿ_��˧_zhou;
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_����_��ʿ_��˧_zhou;
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_����_��ʿ_��˧_zhou;
			break;
		}
		break;
	//***************************************
	case RXIANG:
		// �ٿ�һ���Ǹ��Ǹ��ں���齫��.
		switch(PB90(s)){
		case RCHE:
			ei.attPoint[WHITECOLOR] += att_�ڳ�_����_��˧_zhou;
			break;
		case RPAO:
			ei.attPoint[WHITECOLOR] += att_����_����_��˧_zhou;
			break;
		case RMA:
			ei.attPoint[WHITECOLOR] += att_����_����_��˧_zhou;
			break;
		}
		break;
	default:
		break;
	}	
} 