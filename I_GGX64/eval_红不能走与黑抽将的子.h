
//����������1.�췽�����߶������� 2.�ڷ��ĳ齫 ʱ
//set_bit(POSITION->DYN->black_xray,msq);
//xray_black_list[msq] = s;

//����������1.�췽�����߶������� 2.�ڷ��ĳ齫 ʱ
// ei.attPoint[BLACKCOLOR]

#define RCanNotMove_attNum GetBlackAtt_SQcount_CheMaPaoPawn(POSITION,&ei,msq)

Bitboard CannotMove = POSITION->DYN->black_xray;
while(m128_is_have_bit(CannotMove)){	
	int msq     = pop_1st_bit(&CannotMove);
	int s       = xray_black_list[msq];
	switch(PB90(msq)){
	// �췽�����߶�����
	//=======================================
	case RPAWN:
		// �ٿ�һ���Ǹ��Ǹ�ǣ����.
		switch(PB90(s)){
		case BCHE:  // �ڳ� ��� ��˧
			ei.attPoint[BLACKCOLOR] += att_Che_String[RCanNotMove_attNum]/2;
			break;
		case BPAO:  // ���� X ��� ��˧
			ei.attPoint[BLACKCOLOR] += att_Pao_String[RCanNotMove_attNum]/2;
			break;
		case BMA:   // ���� ��� ��˧  // ���������
			ei.attPoint[BLACKCOLOR] += att_Ma_String[RCanNotMove_attNum]/2;
			break;
		}
		break;
	//=======================================
	case RMA:
		// �ٿ�һ���Ǹ��Ǹ�ǣ����.
		switch(PB90(s)){
		case BCHE:  // �ڳ�_����_��˧
			ei.attPoint[BLACKCOLOR] += att_�ڳ�_����_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Che_String[RCanNotMove_attNum];
			break;
		case BPAO: // ����_����_��˧
			ei.attPoint[BLACKCOLOR] += att_����_����_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Pao_String[RCanNotMove_attNum];
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_����_����_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Ma_String[RCanNotMove_attNum];
			valu -= att_Ma_String_Valu[RCanNotMove_attNum];
			break;
		}
		break;
	//=======================================
	case RPAO:
		// �ٿ�һ���Ǹ��Ǹ�ǣ����.
		switch(PB90(s)){ 
		case BCHE:    // �ڳ�_����_��˧
			ei.attPoint[BLACKCOLOR] += att_�ڳ�_����_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Che_String[RCanNotMove_attNum];
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_����_����_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Pao_String[RCanNotMove_attNum];
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_����_����_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Ma_String[RCanNotMove_attNum];
			valu -= att_Ma_String_Valu[RCanNotMove_attNum];
			break;
		}
		break;
	//=======================================
	case RCHE:
		// �ٿ�һ���Ǹ��Ǹ�ǣ����.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_�ڳ�_�쳵_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Che_String[RCanNotMove_attNum];
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_����_�쳵_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Pao_String[RCanNotMove_attNum];
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_����_�쳵_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Ma_String[RCanNotMove_attNum];
			valu -= att_Ma_String_Valu[RCanNotMove_attNum];
			break;
		}
		break;
	//=======================================
	case RSHI:
		// �ٿ�һ���Ǹ��Ǹ�ǣ����.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_�ڳ�_����_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Che_String[RCanNotMove_attNum]/2;
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_����_����_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Pao_String[RCanNotMove_attNum]/2;
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_����_����_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Ma_String[RCanNotMove_attNum]/2;
			break;
		}
		break;
	//=======================================
	case RXIANG:
		// �ٿ�һ���Ǹ��Ǹ�ǣ����.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_�ڳ�_����_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Che_String[RCanNotMove_attNum]/2;
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_����_����_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Pao_String[RCanNotMove_attNum]/2;
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_����_����_��˧_string;
			ei.attPoint[BLACKCOLOR] += att_Ma_String[RCanNotMove_attNum]/2;
			break;
		}
		break;
	// ********************************************
	case BPAWN:
		// �ٿ�һ���Ǹ��Ǹ��ں���齫��.
		if(StoY(msq) >= 0x5){
			switch(PB90(s)){
			case BCHE:
				ei.attPoint[BLACKCOLOR] += att_�ڳ�_����_��˧_zhou;
				break;
			case BPAO:
				ei.attPoint[BLACKCOLOR] += att_����_����_��˧_zhou;
				break;
			case BMA:
				ei.attPoint[BLACKCOLOR] += att_����_����_��˧_zhou;
				break;
			}
		}
		break;
	//***************************************
	case BMA:
		// �ٿ�һ���Ǹ��Ǹ��ں���齫��.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_�ڳ�_����_��˧_zhou;
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_����_����_��˧_zhou;
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_����_����_��˧_zhou;
			break;
		}
		break;
	//***************************************
	case BPAO:
		// �ٿ�һ���Ǹ��Ǹ��ں���齫��.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_�ڳ�_����_��˧_zhou;
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_����_����_��˧_zhou;
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_����_����_��˧_zhou;
			break;
		}
		break;
	//***************************************
	case BCHE:
		// �ٿ�һ���Ǹ��Ǹ��ں���齫��.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_�ڳ�_�ڳ�_��˧_zhou;
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_����_�ڳ�_��˧_zhou;
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_����_�ڳ�_��˧_zhou;
			break;
		}
		break;
	//***************************************
	case BSHI:
		// �ٿ�һ���Ǹ��Ǹ��ں���齫��.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_�ڳ�_��ʿ_��˧_zhou;
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_����_��ʿ_��˧_zhou;
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_����_��ʿ_��˧_zhou;
			break;
		}
		break;
	//***************************************
	case BXIANG:
		// �ٿ�һ���Ǹ��Ǹ��ں���齫��.
		switch(PB90(s)){
		case BCHE:
			ei.attPoint[BLACKCOLOR] += att_�ڳ�_����_��˧_zhou;
			break;
		case BPAO:
			ei.attPoint[BLACKCOLOR] += att_����_����_��˧_zhou;
			break;
		case BMA:
			ei.attPoint[BLACKCOLOR] += att_����_����_��˧_zhou;
			break;
		}
		break;
	default:
		break;
	}
}

