#include "chess.h"
//#include "bitboard.h"


#ifdef NOT_USE_FIND_MUL
#else
uint64   CHE_Mult_R[90];
uint64   CHE_Mult_F[90];
 uint64  PAO_EAT_Mult_R[90];
uint64  PAO_EAT_Mult_F[90];
uint64   PAO_SUPER_Mult_R[90];
uint64  PAO_SUPER_Mult_F[90];
uint64   Ma_to_King_Mult[90];
 uint64   King_to_Ma_Mult[90];
uint64 XIANG_Mult[90]; 

uint64 random_64(){
	uint64 u1 = ((uint64)rand()) & 0xffff;
	uint64 u2 = ((uint64)rand()) & 0xffff;
	uint64 u3 = ((uint64)rand()) & 0xffff;
	uint64 u4 = ((uint64)rand()) & 0xffff;
	return u1 | (u2 << 16) | (u3 << 32) | (u4 << 48);
}
uint64 random_uint64_fewbits(void){
	//return random_64() & random_64() & random_64() ;
	return random_64() & random_64() ;
}


#endif

void ma_to_king_att_by_block(Bitboard* result, int sq, Bitboard block){

	int rk = StoY(sq);
	int fl = StoX(sq);	

	*result = _mm_setzero_si128();

	//���8������,1,����
	if(rk >= 2 && fl >= 1){
		if(bit_is_set(block,XYtoS(fl,rk-1)) == 0){
			set_bit(*result,XYtoS(fl-1,rk-2));
		}
	}
	//���8������,1,����
	if(rk >= 2 && fl <= 7){
		if(bit_is_set(block,XYtoS(fl,rk-1)) == 0){
			set_bit(*result,XYtoS(fl+1,rk-2));
		}
	}

	//���8������,1,����
	if(rk >= 1 && fl <= 6){
		if(bit_is_set(block,XYtoS(fl+1,rk)) == 0){
			set_bit(*result,XYtoS(fl+2,rk-1));
		}
	}

	//���8������,1,����
	if(rk <= 8 && fl <= 6){
		if(bit_is_set(block,XYtoS(fl+1,rk)) == 0){
			set_bit(*result,XYtoS(fl+2,rk+1));
		}
	}

	//���8������,1,����
	if(rk <= 7 && fl <= 7){
		if(bit_is_set(block,XYtoS(fl,rk+1)) == 0){
			set_bit(*result,XYtoS(fl+1,rk+2));
		}
	}

	//���8������,1,����
	if(rk <= 7 && fl >= 1){
		if(bit_is_set(block,XYtoS(fl,rk+1)) == 0){
			set_bit(*result,XYtoS(fl-1,rk+2));
		}
	}

	//���8������,1,����
	if(rk <= 8 && fl >= 2){
		if(bit_is_set(block,XYtoS(fl-1,rk)) == 0){
			set_bit(*result,XYtoS(fl-2,rk+1));
		}
	}

	//���8������,1,����
	if(rk >= 1 && fl >= 2){
		if(bit_is_set(block,XYtoS(fl-1,rk)) == 0){
			set_bit(*result,XYtoS(fl-2,rk-1));
		}
	}
}

void king_to_ma_att_by_block(Bitboard* result, int sq, Bitboard block){

	int rk = StoY(sq);
	int fl = StoX(sq);	

	*result = _mm_setzero_si128();

	//���8������,1,����
	if(rk >= 2 && fl >= 1){
		if(bit_is_set(block,XYtoS(fl-1,rk-1)) == 0){
			set_bit(*result,XYtoS(fl-1,rk-2));
		}
	}
	//���8������,1,����
	if(rk >= 2 && fl <= 7){
		if(bit_is_set(block,XYtoS(fl+1,rk-1)) == 0){
			set_bit(*result,XYtoS(fl+1,rk-2));
		}
	}

	//���8������,1,����
	if(rk >= 1 && fl <= 6){
		if(bit_is_set(block,XYtoS(fl+1,rk-1)) == 0){
			set_bit(*result,XYtoS(fl+2,rk-1));
		}
	}

	//���8������,1,����
	if(rk <= 8 && fl <= 6){
		if(bit_is_set(block,XYtoS(fl+1,rk+1)) == 0){
			set_bit(*result,XYtoS(fl+2,rk+1));
		}
	}

	//���8������,1,����
	if(rk <= 7 && fl <= 7){
		if(bit_is_set(block,XYtoS(fl+1,rk+1)) == 0){
			set_bit(*result,XYtoS(fl+1,rk+2));
		}
	}

	//���8������,1,����
	if(rk <= 7 && fl >= 1){
		if(bit_is_set(block,XYtoS(fl-1,rk+1)) == 0){
			set_bit(*result,XYtoS(fl-1,rk+2));
		}
	}

	//���8������,1,����
	if(rk <= 8 && fl >= 2){
		if(bit_is_set(block,XYtoS(fl-1,rk+1)) == 0){
			set_bit(*result,XYtoS(fl-2,rk+1));
		}
	}

	//���8������,1,����
	if(rk >= 1 && fl >= 2){
		if(bit_is_set(block,XYtoS(fl-1,rk-1)) == 0){
			set_bit(*result,XYtoS(fl-2,rk-1));
		}
	}
}

void xiang_att_by_block(Bitboard* result, int sq,Bitboard block){

	*result = _mm_setzero_si128(); 

	if(sq == 2){
		if(bit_is_set(block,Square(10)) == FALSE){
			set_bit(*result,18);
		}
		if(bit_is_set(block,Square(12)) == FALSE){
			set_bit(*result,22);
		}
	}
	if(sq == 6){
		if(bit_is_set(block,Square(14)) == FALSE){
			set_bit(*result,22);
		}
		if(bit_is_set(block,Square(16)) == FALSE){
			set_bit(*result,26);
		}
	}
	if(sq == 18){
		if(bit_is_set(block,Square(10)) == FALSE){
			set_bit(*result,2);
		}
		if(bit_is_set(block,Square(28)) == FALSE){
			set_bit(*result,38);
		}
	}
	if(sq == 22){

		if(bit_is_set(block,Square(12)) == FALSE){
			set_bit(*result,2);
		}
		if(bit_is_set(block,Square(14)) == FALSE){
			set_bit(*result,6);
		}

		if(bit_is_set(block,Square(30)) == FALSE){
			set_bit(*result,38);
		}
		if(bit_is_set(block,Square(32)) == FALSE){
			set_bit(*result,42);
		}
	}
	if(sq == 26){
		if(bit_is_set(block,Square(16)) == FALSE){
			set_bit(*result,6);
		}
		if(bit_is_set(block,Square(34)) == FALSE){
			set_bit(*result,42);
		}
	}
	if(sq == 38){
		if(bit_is_set(block,Square(28)) == FALSE){
			set_bit(*result,18);
		}
		if(bit_is_set(block,Square(30)) == FALSE){
			set_bit(*result,22);
		}
	}
	if(sq == 42){
		if(bit_is_set(block,Square(32)) == FALSE){
			set_bit(*result,22);
		}
		if(bit_is_set(block,Square(34)) == FALSE){
			set_bit(*result,26);
		}
	}

	//
	if(sq == 47){
		if(bit_is_set(block,Square(55)) == FALSE){
			set_bit(*result,63);
		}
		if(bit_is_set(block,Square(57)) == FALSE){
			set_bit(*result,67);
		}
	}

	if(sq == 51){
		if(bit_is_set(block,Square(59)) == FALSE){
			set_bit(*result,67);
		}
		if(bit_is_set(block,Square(61)) == FALSE){
			set_bit(*result,71);
		}
	}

	if(sq == 63){
		if(bit_is_set(block,Square(55)) == FALSE){
			set_bit(*result,47);
		}
		if(bit_is_set(block,Square(73)) == FALSE){
			set_bit(*result,83);
		}
	}

	if(sq == 67){
		if(bit_is_set(block,Square(57)) == FALSE){
			set_bit(*result,47);
		}
		if(bit_is_set(block,Square(59)) == FALSE){
			set_bit(*result,51);
		}
		if(bit_is_set(block,Square(75)) == FALSE){
			set_bit(*result,83);
		}
		if(bit_is_set(block,Square(77)) == FALSE){
			set_bit(*result,87);
		}
	}

	if(sq == 71){
		if(bit_is_set(block,Square(61)) == FALSE){
			set_bit(*result,51);
		}
		if(bit_is_set(block,Square(79)) == FALSE){
			set_bit(*result,87);
		}
	}

	if(sq == 83){
		if(bit_is_set(block,Square(73)) == FALSE){
			set_bit(*result,Square(63));
		}
		if(bit_is_set(block,Square(75)) == FALSE){
			set_bit(*result,Square(67));
		}
	}

	if(sq == 87){
		if(bit_is_set(block,Square(77)) == FALSE){
			set_bit(*result,67);
		}
		if(bit_is_set(block,Square(79)) == FALSE){
			set_bit(*result,71);
		}
	}
}

void pao_eat_by_block_f(Bitboard* result, int sq,Bitboard block){

	int rk = StoY(sq);
	int fl = StoX(sq);
	int pao;
	int r;
	*result = _mm_setzero_si128();

	//Square rk = StoY(sq);
	//int fl = StoX(sq);


	//����
	pao = 0;
	for(r = rk+1; r <= 9; r++){

		if(pao == 1){
			set_bit(*result,XYtoS(fl,r)); //����  
		}

		if(bit_is_set(block,XYtoS(fl,r))){
			pao++;
		};
		if(pao == 2){
			//���Ҫ��ǰ��ļ�λ�����
			//for(int a = r - 1; a > rk; a--){
			//	clear_bit(result,XYtoS(fl,a));
			//}
			break;
		}
	}

	//����
	pao = 0;
	for(r = rk-1; r >= 0; r--){
		if(pao == 1){
			set_bit(*result,XYtoS(fl,r)); //����  
		}

		if(bit_is_set(block,XYtoS(fl,r))){
			pao++;
		};
		if(pao == 2){
			//���Ҫ��ǰ��ļ�λ�����
			//for(int a = r + 1; a < rk; a++){
			//	clear_bit(result,XYtoS(fl,a));
			//}
			break;
		}		
	}

	//if(sq == 70){
	//	//if(
	//}

}

void pao_eat_by_block_r(Bitboard* result, int sq,Bitboard block){

	int rk = StoY(sq);
	int fl = StoX(sq);

	//int pao;



	int f;
	//����
	int pao = 0;

	*result = _mm_setzero_si128();
	for(f = fl+1; f <= 8; f++){

		if(pao == 1){
			set_bit(*result,XYtoS(f,rk)); //����  
		}

		if(bit_is_set(block,XYtoS(f,rk))){
			pao++;
		};
		if(pao == 2){
			//���Ҫ��ǰ��ļ�λ�����	
			//for(int a = f - 1; a > fl; a--){
			//	clear_bit(result,XYtoS(a,rk));
			//}			
			break;
		}
	}
	//����
	pao = 0;
	for(f = fl-1; f >= 0; f--){
		if(pao == 1){
			set_bit(*result,XYtoS(f,rk)); //����  
		}

		if(bit_is_set(block,XYtoS(f,rk))){
			pao++;
		};
		if(pao == 2){
			//���Ҫ��ǰ��ļ�λ�����	
			//for(int a = f + 1; a < fl; a++){
			//	clear_bit(result,XYtoS(a,rk));
			//}
			break;
		}
	}

	//print_bb(block);
	//print_bb(result);

}

void pao_super_by_block_f(Bitboard* result, int sq,Bitboard block){



	int rk = StoY(sq);
	int fl = StoX(sq);


	//����
	int pao = 0;

	int r;

	*result = _mm_setzero_si128();

	for(r = rk+1; r <= 9; r++){

		if(pao == 2){
			set_bit(*result,XYtoS(fl,r)); //����  
		}

		if(bit_is_set(block,XYtoS(fl,r))){
			pao++;
		};
		if(pao == 3){
			//���Ҫ��ǰ��ļ�λ�����
			//for(int a = r - 1; a > rk; a--){
			//	clear_bit(result,XYtoS(fl,a));
			//}

			break;
		}
	}

	//����
	pao = 0;
	for(r = rk-1; r >= 0; r--){

		if(pao == 2){
			set_bit(*result,XYtoS(fl,r)); //����  
		}

		if(bit_is_set(block,XYtoS(fl,r))){
			pao++;
		};
		if(pao == 3){
			//���Ҫ��ǰ��ļ�λ�����
			//for(int a = r + 1; a < rk; a++){
			//	clear_bit(result,XYtoS(fl,a));
			//}
			break;
		}	
	}
}

void pao_super_by_block_r(Bitboard* result, int sq,Bitboard block){



	int rk = StoY(sq);
	int fl = StoX(sq);
	int f;



	//����
	int pao = 0;

	*result = _mm_setzero_si128();
	for(f = fl+1; f <= 8; f++){

		if(pao == 2){
			set_bit(*result,XYtoS(f,rk)); //����  
		}

		if(bit_is_set(block,XYtoS(f,rk))){
			pao++;
		};
		if(pao == 3){

			//���Ҫ��ǰ��ļ�λ�����
			//for(int a = f - 1; a > fl; a--){
			//	clear_bit(result,XYtoS(a,rk));
			//}

			break;
		}
	}
	//����
	pao = 0;
	for(f = fl-1; f >= 0; f--){
		if(pao == 2){
			set_bit(*result,XYtoS(f,rk)); //����  
		}

		if(bit_is_set(block,XYtoS(f,rk))){
			pao++;
		};
		if(pao == 3){

			//���Ҫ��ǰ��ļ�λ�����
			//for(int a = f + 1; a < fl; a++){
			//	clear_bit(result,XYtoS(a,rk));
			//}

			break;
		}
	}

	//print_bb(block);
	//print_bb(result);

}

void che_att_by_block_r(Bitboard* result, int sq,Bitboard block){

	//m128_from_2u64(result,0,0);
	int rk = StoY(sq);
	int fl = StoX(sq);
	int f;

	*result = _mm_setzero_si128();

	//����
	for(f = fl+1; f <= 8; f++){
		set_bit(*result,XYtoS(f,rk));
		if(bit_is_set(block,XYtoS(f,rk))) break;
	}
	//����
	for(f = fl-1; f >= 0; f--){
		set_bit(*result,XYtoS(f,rk));
		if(bit_is_set(block,XYtoS(f,rk))) break;
	}
}

void che_att_by_block_f(Bitboard* result, int sq,Bitboard block){

	int rk = StoY(sq);
	int fl = StoX(sq);
	int r;
	*result = _mm_setzero_si128();
	//����
	for(r = rk+1; r <= 9; r++){
		set_bit(*result,XYtoS(fl,r));
		if(bit_is_set(block,XYtoS(fl,r))) break;
	}
	//����
	for(r = rk-1; r >= 0; r--){
		set_bit(*result,XYtoS(fl,r));
		if(bit_is_set(block,XYtoS(fl,r))) break;
	}
}

void index_to_Bitboard(Bitboard* result, int index, int bits, Bitboard mask){
	int i,j;
	*result = _mm_setzero_si128();      //print_bb(mask);
	for(i = 0; i < bits; i++){
		j = pop_1st_bit_sq(mask);   // ����д�
		if(index & (1 << i)){
			set_bit(*result,j);
		}
	}
};

#ifndef NOT_USE_FIND_MUL

//#undef  NOT_USE_FIND_MUL


#define MAX_ARR (23040)
Bitboard b[MAX_ARR];
Bitboard a[MAX_ARR];
Bitboard used[MAX_ARR];
#define NO_CAN_ATT_MUL -1


//�ҵ��ڵ����ҹ�����
void find_pao_eat_magic_r(uint64* BB_magic, int sq, int m){
	Bitboard mask = m_and(RankBB_A[StoY(sq)],Che_Mask_FR[sq]);
	int n = (int)count_1s(mask);  //�õ�mask��λ��
	int fail;
	int i,j;
	uint64 k;
	uint64 t64;
	const uint64 testchenum = 10000000000;
	printf_s("\n Now find >>>>>>>>>Pao Eat sq= %d", sq);
	for(i = 0; i < (1 << n); i++) {
		index_to_Bitboard(&b[i],i,n,mask);  //b[i] = index_to_uint64(i, n, mask);
		pao_eat_by_block_r(&a[i],sq,b[i]);  // a[i] = bishop? batt(sq, b[i]) : ratt(sq, b[i]);
	}
	for(k = 0; k < testchenum; k++) {
		if((k & 0xffffff) == 0){
			printf_s("\n >>now PAO Eat SQ=%d, %.16I64X, remain: %.16I64X total k = %.16I64X,\n",sq,k, testchenum - k, testchenum);
		}
		*BB_magic = random_uint64_fewbits();
		t64 = get_transfrom_u64(mask,*BB_magic);
		if(_mm_popcnt_u64(t64 & 0xFFC0000000000000ULL ) < 8){
			continue;
		}
		for(i = 0; i < MAX_ARR; i++){
			m128_from_2u64(used[i],NO_CAN_ATT_MUL,NO_CAN_ATT_MUL);
		}
		for(i = 0, fail = 0; !fail && i < (1 << n); i++) {
			j = transform_mul(b[i],*BB_magic,m);
			if(used[j].m128i_u64[0]==NO_CAN_ATT_MUL  && used[j].m128i_u64[1] ==NO_CAN_ATT_MUL){
				used[j] = a[i];
			}
			else if(used[j].m128i_u64[0] != a[i].m128i_u64[0] || used[j].m128i_u64[1] != a[i].m128i_u64[1]){
				fail = 1;
			}
		}
		if(!fail) {
			printf_s("\n ok %%%%%%%% find sq= %d", sq);
			return;
		}
	}
	//not find
	*BB_magic = 0; //������һ��0
	printf_s("\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>ERR not find sq= %d", sq);
}
//�ҵ��ڵĹ�����
void find_pao_eat_magic_f(uint64* BB_magic, int sq, int m){
	Bitboard mask = m_and(Che_Mask_FR[sq],FileBB_A[StoX(sq)]);
	int n = (int)count_1s(mask);  //�õ�mask��λ��
	int fail;
	int i,j;
	uint64 k;
	uint64 t64;	
	const uint64 testchenum = 10000000000;
	printf_s("\n Now find >>>>>>>>>Pao Eat file sq= %d", sq);
	for(i = 0; i < (1 << n); i++) {
		index_to_Bitboard(&b[i],i,n,mask);  //b[i] = index_to_uint64(i, n, mask);
		pao_eat_by_block_f(&a[i],sq,b[i]);  // a[i] = bishop? batt(sq, b[i]) : ratt(sq, b[i]);
	}
	for(k = 0; k < testchenum; k++) {
		if((k & 0xffffff) == 0){ //����
			printf_s("\n >>now PAO Eat SQ=%d, %.16I64X, remain: %.16I64X total k = %.16I64X,\n",sq,k, testchenum - k, testchenum);
		}
		*BB_magic = random_uint64_fewbits();
		t64 = get_transfrom_u64(mask,*BB_magic);
		if(_mm_popcnt_u64(t64 & 0xFFC0000000000000ULL ) < 8){
			continue;
		}
		for(i = 0; i < MAX_ARR; i++){
			m128_from_2u64(used[i],NO_CAN_ATT_MUL,NO_CAN_ATT_MUL);
		}
		for(i = 0, fail = 0; !fail && i < (1 << n); i++) {
			j = transform_mul(b[i],*BB_magic,m);
			if(used[j].m128i_u64[0]==NO_CAN_ATT_MUL  && used[j].m128i_u64[1] ==NO_CAN_ATT_MUL){
				used[j] = a[i];//BB_from_BB(used[j],a[i]);
			}
			else if(used[j].m128i_u64[0] != a[i].m128i_u64[0] || used[j].m128i_u64[1] != a[i].m128i_u64[1]){
				fail = 1;
			}
		}
		if(!fail) {
			printf_s("\n ok %%%%%%%% find sq= %d", sq);
			return;
		}
	}
	//not find
	*BB_magic = 0; //������һ��0
	printf_s("\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>ERR not find sq= %d", sq);
}

void find_pao_super_magic_f(uint64* BB_magic, int sq, int m){
	Bitboard mask = m_and(Che_Mask_FR[sq],FileBB_A[StoX(sq)]);
	int n = (int)count_1s(mask);  //�õ�mask��λ��
	int fail;
	int i,j;
	uint64 k;
	uint64 t64;
	const uint64 testchenum = 10000000000/2;
	printf_s("\n Now find >>>>>>>>>Pao Super sq= %d", sq);
	for(i = 0; i < (1 << n); i++) {
		index_to_Bitboard(&b[i],i,n,mask);  // b[i] = index_to_uint64(i, n, mask);
		pao_super_by_block_f(&a[i],sq,b[i]);  // a[i] = bishop? batt(sq, b[i]) : ratt(sq, b[i]);
	}
	for(k = 0; k < testchenum; k++) {
		if((k & 0xffffff) == 0){
			printf_s("\n >>now PAO SuperEat rank SQ=%d, %.16I64X, remain: %.16I64X total k = %.16I64X,\n",sq,k, testchenum - k, testchenum);
		}
		*BB_magic = random_uint64_fewbits();
		t64 = get_transfrom_u64(mask,*BB_magic);
		if(_mm_popcnt_u64(t64 & 0xFFC0000000000000ULL ) < 8){
			continue;
		}
		for(i = 0; i < MAX_ARR; i++){
			m128_from_2u64(used[i],NO_CAN_ATT_MUL,NO_CAN_ATT_MUL);
		}
		for(i = 0, fail = 0; !fail && i < (1 << n); i++) {
			j = transform_mul(b[i],*BB_magic,m);
			if(used[j].m128i_u64[0]==NO_CAN_ATT_MUL  && used[j].m128i_u64[1] ==NO_CAN_ATT_MUL){
				used[j] = a[i];//BB_from_BB(used[j],a[i]);
			}
			else if(used[j].m128i_u64[0] != a[i].m128i_u64[0] || used[j].m128i_u64[1] != a[i].m128i_u64[1]){
				fail = 1;
			}
		}
		if(!fail) {
			printf_s("\n ok %%%%%%%% find sq= %d", sq);
			return;
		}
	}
	//not find
	*BB_magic = 0; //������һ��0
	printf_s("\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>ERR not find sq= %d", sq);
}

void find_pao_super_magic_r(uint64* BB_magic, int sq, int m){
	Bitboard mask = m_and(Che_Mask_FR[sq],RankBB_A[StoY(sq)]);
	int n = (int)count_1s(mask);  //�õ�mask��λ��
	int fail;
	int i,j;
	uint64 k;
	uint64 t64;
	const uint64 testchenum = 10000000000/2;
	printf_s("\n Now find >>>>>>>>>Pao Super sq= %d", sq);
	for(i = 0; i < (1 << n); i++) {
		index_to_Bitboard(&b[i],i,n,mask);  // b[i] = index_to_uint64(i, n, mask);
		pao_super_by_block_r(&a[i],sq,b[i]);  // a[i] = bishop? batt(sq, b[i]) : ratt(sq, b[i]);
	}
	for(k = 0; k < testchenum; k++) {
		if((k & 0xffffff) == 0){
			printf_s("\n >>now PAO SuperEat rank SQ=%d, %.16I64X, remain: %.16I64X total k = %.16I64X,\n",sq,k, testchenum - k, testchenum);
		}
		*BB_magic = random_uint64_fewbits();
		t64 = get_transfrom_u64(mask,*BB_magic);
		if(_mm_popcnt_u64(t64 & 0xFFC0000000000000ULL ) < 8){
			continue;
		}
		for(i = 0; i < MAX_ARR; i++){
			m128_from_2u64(used[i],NO_CAN_ATT_MUL,NO_CAN_ATT_MUL);
		}
		for(i = 0, fail = 0; !fail && i < (1 << n); i++) {
			j = transform_mul(b[i],*BB_magic,m);
			if(used[j].m128i_u64[0]==NO_CAN_ATT_MUL  && used[j].m128i_u64[1] ==NO_CAN_ATT_MUL){
				used[j] = a[i];//BB_from_BB(used[j],a[i]);
			}
			else if(used[j].m128i_u64[0] != a[i].m128i_u64[0] || used[j].m128i_u64[1] != a[i].m128i_u64[1]){
				fail = 1;
			}
		}
		if(!fail) {
			printf_s("\n ok %%%%%%%% find sq= %d", sq);
			return;
		}
	}
	//not find
	*BB_magic = 0; //������һ��0 RankBB_A[StoY(sq)]);
	printf_s("\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>ERR not find sq= %d", sq);
}

//�ҵ�Ӱ���һλ��magic���� >>57λ
void find_ma_magic(uint64* BB_magic, int sq, int m){ //BB_Get_90bitOnly
	Bitboard mask = Ma_to_King_Mask[sq];
	int n = (int)count_1s(mask);
	//Bitboard occ;	
	int fail;
	int i,j;
	uint64 k;
	uint64 t64;
	const uint64 testchenum = 100000000000000;	
	printf_s("\n Now find >>>>>>>>>Ma sq= %d", sq);
	for(i = 0; i < (1 << n); i++) {
		index_to_Bitboard(&b[i],i,n,mask);  //b[i] = index_to_uint64(i, n, mask);
		ma_to_king_att_by_block(&a[i],sq,b[i]);    //a[i] = bishop? batt(sq, b[i]) : ratt(sq, b[i]);		
	}	

	for(k = 0; k < testchenum; k++) {
		if((k & 0xffffff) == 0){
			printf_s("\n >>now MaKing SQ=%d, %.16I64X, remain: %.16I64X total k = %.16I64X,\n",sq,k, testchenum - k, testchenum);
		}
		//�õ�
		*BB_magic = random_uint64_fewbits();
		t64 = get_transfrom_u64(mask,*BB_magic);
		if(_mm_popcnt_u64(t64 & 0xFF80000000000000ULL ) < 8){
			continue;
		}
		for(i = 0; i < MAX_ARR; i++){
			m128_from_2u64(used[i],NO_CAN_ATT_MUL,NO_CAN_ATT_MUL);
		}
		//memset(used,0,sizeof(used));
		for(i = 0, fail = 0; !fail && i < (1 << n); i++) {
			j = transform_mul(b[i],*BB_magic,m);
			if(used[j].m128i_u64[0]==NO_CAN_ATT_MUL  && used[j].m128i_u64[1] ==NO_CAN_ATT_MUL){
				used[j] = a[i];//BB_from_BB(used[j],a[i]);
			}
			else if(used[j].m128i_u64[0] != a[i].m128i_u64[0] || used[j].m128i_u64[1] != a[i].m128i_u64[1]){
				fail = 1;
			}
		}
		if(!fail) {
			printf_s("\n ok %%%%%%%% find sq= %d", sq);
			return;
		}
	}
	//not find
	*BB_magic = 0; //������һ��0
	printf_s("\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>ERR not find sq= %d", sq);
}

void find_king_to_ma_magic(uint64* BB_magic, int sq, int m){ //BB_Get_90bitOnly
	Bitboard mask = King_to_Ma_Mask[sq];
	int n  = (int)count_1s(mask);
	const uint64 testchenum = 100000000000000;
	int fail;
	int i,j;
	uint64 k;
	uint64 t64;
	printf_s("\n Now find >>>>>>>>>Ma sq= %d", sq);
	for(i = 0; i < (1 << n); i++) {
		index_to_Bitboard(&b[i],i,n,mask);  //b[i] = index_to_uint64(i, n, mask);
		king_to_ma_att_by_block(&a[i],sq,b[i]);    //a[i] = bishop? batt(sq, b[i]) : ratt(sq, b[i]);
	}
	for(k = 0; k < testchenum; k++) {
		if((k & 0xffffff) == 0){
			printf_s("\n >>now KingMa SQ=%d, %.16I64X, remain: %.16I64X total k = %.16I64X,\n",sq,k, testchenum - k, testchenum);
		}
		//�õ�
		*BB_magic = random_uint64_fewbits();
		t64 = get_transfrom_u64(mask,*BB_magic);
		if(_mm_popcnt_u64(t64 & 0xFF80000000000000ULL ) < 8){
			continue;
		}
		memset(used,0,sizeof(used));
		for(i = 0, fail = 0; !fail && i < (1 << n); i++) {
			j = transform_mul(b[i],*BB_magic,m);
			if(used[j].m128i_u64[0]==0  && used[j].m128i_u64[1] ==0){
				used[j] = a[i];// BB_from_BB(used[j],a[i]);
			}
			else if(used[j].m128i_u64[0] != a[i].m128i_u64[0] || used[j].m128i_u64[1] != a[i].m128i_u64[1]){
				fail = 1;
			}
		}
		if(!fail) {
			printf_s("\n ok %%%%%%%% find sq= %d", sq);
			return;
		}
	}
	//not find
	*BB_magic = 0; //������һ��0
	printf_s("\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>ERR not find sq= %d", sq);
}

void find_xiang_magic(uint64* BB_magic, int sq, int m){ //BB_Get_90bitOnly
	Bitboard mask = XiangMask[sq];	
	int n = (int)count_1s(mask);  //�õ�mask��λ��6
	uint64 t64;
	const uint64 testchenum = 100000000000000;
	int fail;
	int i,j;
	uint64 k;
	printf_s("\n Now find >>>>>>>>>Xiang sq= %d", sq);
	for(i = 0; i < (1 << n); i++) {
		index_to_Bitboard(&b[i],i,n,mask);  //b[i] = index_to_uint64(i, n, mask);
		xiang_att_by_block(&a[i],sq,b[i]);    //a[i] = bishop? batt(sq, b[i]) : ratt(sq, b[i]);
	}
	for(k = 0; k < testchenum; k++) {
		if((k & 0xffffff) == 0){
			printf_s("\n >>now Xiang SQ=%d, %.16I64X, remain: %.16I64X total k = %.16I64X,\n",sq,k, testchenum - k, testchenum);
		}
		//�õ�
		*BB_magic = random_uint64_fewbits();
		t64 = get_transfrom_u64(mask,*BB_magic);
		if(_mm_popcnt_u64(t64 & 0xFF00000000000000ULL ) < 5){
			continue;
		}
		for(i = 0; i < MAX_ARR; i++){
			m128_from_2u64(used[i],NO_CAN_ATT_MUL,NO_CAN_ATT_MUL);
		}
		for(i = 0, fail = 0; !fail && i < (1 << n); i++) {
			j = transform_mul(b[i],*BB_magic,m);
			if(used[j].m128i_u64[0]==NO_CAN_ATT_MUL  && used[j].m128i_u64[1] ==NO_CAN_ATT_MUL){
				used[j] = a[i];//BB_from_BB(used[j],a[i]);
			}
			else if(used[j].m128i_u64[0] != a[i].m128i_u64[0] || used[j].m128i_u64[1] != a[i].m128i_u64[1]){
				fail = 1;
			}
		}
		if(!fail) {
			printf_s("\n ok %%%%%%%% find sq= %d", sq);
			return;
		}
	}
	//not find
	*BB_magic = 0; //������һ��0
	printf_s("\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>ERR not find sq= %d", sq);
}

void find_che_magic_f(uint64* BB_magic, int sq, int m) { 
	Bitboard mask = m_and(Che_Mask_FR[sq],FileBB_A[StoX(sq)]);
	int n = (int)count_1s(mask);
	int fail;
	int i,j;
	uint64 k;
	uint64 t64;
	const uint64 testchenum = 100000000000000;
	printf_s("\n Now find >>>>>>>>>Che file sq= %d", sq);
	for(i = 0; i < (1 << n); i++) {
		index_to_Bitboard(&b[i],i,n,mask);    // b[i] = index_to_uint64(i, n, mask);
		che_att_by_block_f(&a[i],sq,b[i]);    // a[i] = bishop? batt(sq, b[i]) : ratt(sq, b[i]);
	}
	for(k = 0; k < testchenum; k++) {
		if((k & 0xfffff) == 0){
			printf_s("\n >>now CHE SQ=%d, %.16I64X, remain: %.16I64X total k = %.16I64X,\n",sq,k, testchenum - k, testchenum);
		}
		//�õ�
		*BB_magic = random_uint64_fewbits();
		t64 = get_transfrom_u64(mask,*BB_magic);
		if(_mm_popcnt_u64(t64 & 0xFF80000000000000ULL ) < 8){
			continue;  // ��������һ�� magic64
		}
		for(i = 0; i < MAX_ARR; i++){			
			m128_from_2u64(used[i],NO_CAN_ATT_MUL,NO_CAN_ATT_MUL);
		}
		// У���������.
		for(i = 0, fail = 0; !fail && i < (1 << n); i++) {
			j = transform_mul(b[i],*BB_magic,m);
			if(used[j].m128i_u64[0] == NO_CAN_ATT_MUL && used[j].m128i_u64[1] == NO_CAN_ATT_MUL){
				used[j] = a[i]; // BB_from_BB(used[j],a[i]);
			}
			else if((used[j].m128i_u64[0] != a[i].m128i_u64[0]) || (used[j].m128i_u64[1] != a[i].m128i_u64[1])){
				fail = 1;
			}			 
		}
		if(!fail) {
			printf_s("\n ok %%%%%%%% find sq= %d", sq);
			return;
		}
	}
	//not find
	*BB_magic = 0; //������һ��0
	printf_s("\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>ERR not find sq= %d", sq);
}

void find_che_magic_r(uint64* BB_magic, int sq, int m){ 	
	Bitboard mask = m_and(RankBB_A[StoY(sq)],Che_Mask_FR[sq]);
	int n = (int)count_1s(mask);
	int fail;
	int i,j;
	uint64 k;
	uint64 t64;
	const uint64 testchenum = 100000000000000;
	printf_s("\n Now find >>>>>>>>>Che sq= %d", sq);
	for(i = 0; i < (1 << n); i++) {
		index_to_Bitboard(&b[i],i,n,mask);    // b[i] = index_to_uint64(i, n, mask);
		che_att_by_block_r(&a[i],sq,b[i]);    // a[i] = bishop? batt(sq, b[i]) : ratt(sq, b[i]);
	}
	for(k = 0; k < testchenum; k++) {
		if((k & 0xfffff) == 0){
			printf_s("\n >>now CHE SQ=%d, %.16I64X, remain: %.16I64X total k = %.16I64X,\n",sq,k, testchenum - k, testchenum);
		}
		//�õ�
		*BB_magic = random_uint64_fewbits();
		t64 = get_transfrom_u64(mask,*BB_magic);
		if(_mm_popcnt_u64(t64 & 0xFFC0000000000000ULL ) < 8){
			continue;
		}
		for(i = 0; i < MAX_ARR; i++){
			m128_from_2u64(used[i],NO_CAN_ATT_MUL,NO_CAN_ATT_MUL);
		}
		for(i = 0, fail = 0; !fail && i < (1 << n); i++) {
			j = transform_mul(b[i],*BB_magic,m);
			if(used[j].m128i_u64[0]==NO_CAN_ATT_MUL  && used[j].m128i_u64[1] ==NO_CAN_ATT_MUL){
				used[j] = a[i];  // BB_from_BB(used[j],a[i]);
			}
			else if(used[j].m128i_u64[0] != a[i].m128i_u64[0] || used[j].m128i_u64[1] != a[i].m128i_u64[1]){
				fail = 1;
			}
		}
		if(!fail) {
			printf_s("\n ok %%%%%%%% find sq= %d", sq);
			return;
		}
	}
	//not find
	*BB_magic = 0; //������һ��0
	printf_s("\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>ERR not find sq= %d", sq);
}

void find_mul(bool isZero){
	
	int find = 0;
	uint64* PMul;
	int sq;
	PMul = (uint64*)CHE_Mult_R;
	//goto findma;
	//�ҵ�����ħ������
	for(sq = 0; sq < 90; sq++){
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_che_magic_r(&PMul[sq], sq, 7);    // Rank ��� 7
			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n che rank mage_num: sq: %4d\n",sq);
		//print_bb(_Mult[sq],log_file);
		fflush(llog_file);
#endif
	}
#ifdef  USE_LOG_FILE
	fprintf_s(llog_file,"\n che rank array ******************************** �ַ����� %d ��\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(llog_file,"0x%.16I64X,",PMul[sq]);
		//fprintf_s(llog_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(llog_file,"\n");
	}
	fflush(llog_file);
#endif
	//----------------------------------------------------------------------------
	PMul = (uint64*)CHE_Mult_F;
	find = 0;
	//�ҵ�����ħ������
	for(sq = 0; sq < 90; sq++){
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_che_magic_f(&PMul[sq], sq, 8);    // Rank ��� 7
			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n che file mage_num: sq: %4d\n",sq);
		fflush(llog_file);
#endif
	}
#ifdef  USE_LOG_FILE
	//�ٴ�ӡ����
	fprintf_s(llog_file,"\n che file array ******************************** �ַ����� %d ��\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(llog_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(llog_file,"\n");
	}
	fflush(llog_file);
#endif
	//----------------------------------------------------------------------------
	PMul = PAO_EAT_Mult_R;
	find = 0;
	for(sq = 0; sq < 90; sq++){	
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_pao_eat_magic_r(&PMul[sq], sq, 7);  //R���7
			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n pao eat rank mage_num: sq: %4d\n",sq);
		fflush(llog_file);
#endif
	}
#ifdef  USE_LOG_FILE
	//�ٴ�ӡ����
	fprintf_s(llog_file,"\n pao eat rank array ******************************** �ַ����� %d ��\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(llog_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(llog_file,"\n");
	}
	fflush(llog_file);
#endif
	//-----------------------------------------------------------------
	PMul = PAO_EAT_Mult_F;
	find = 0;
	for(sq = 0; sq < 90; sq++){	
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_pao_eat_magic_f(&PMul[sq], sq, 8);  //File ��� 8
			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n pao eat file mage_num: sq: %4d\n",sq);
		fflush(llog_file);
#endif
	}
#ifdef  USE_LOG_FILE
	//�ٴ�ӡ����
	fprintf_s(llog_file,"\n pao eat file array ******************************** �ַ����� %d ��\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(llog_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(llog_file,"\n");
	}
	fflush(llog_file);
#endif
	//----------------------------------------------------------------------------
	PMul = PAO_SUPER_Mult_R;
	find = 0;
	for(sq = 0; sq < 90; sq++){	
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_pao_super_magic_r(&PMul[sq], sq, 7);

			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n pao super rank mage_num: sq: %4d\n",sq);
		fflush(llog_file);
#endif
	}
#ifdef  USE_LOG_FILE
	fprintf_s(llog_file,"\n pao super rank array ******************************** �ַ����� %d ��\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(llog_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(llog_file,"\n");
	}
	fflush(llog_file);
#endif
	//----------------------------------------------------------------------------
	PMul = PAO_SUPER_Mult_F;
	find = 0;
	for(sq = 0; sq < 90; sq++){	
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_pao_super_magic_f(&PMul[sq], sq, 8);
			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n pao super file mage_num: sq: %4d\n",sq);
		fflush(llog_file);
#endif
	}
#ifdef  USE_LOG_FILE
	//�ٴ�ӡ����
	fprintf_s(llog_file,"\n pao super file array ******************************** �ַ����� %d ��\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(llog_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(llog_file,"\n");
	}
	fflush(llog_file);
#endif
	//MA_Mult
//findma:
	//----------------------------------------------------------------------------
	PMul = Ma_to_King_Mult;
	find = 0;
	for(sq = 0; sq < 90; sq++){	
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_ma_magic(&PMul[sq], sq, 4);
			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n ma_ma eat mage_num: sq: %4d\n",sq);
		fflush(llog_file);
#endif
	}
#ifdef  USE_LOG_FILE
	//�ٴ�ӡ����
	fprintf_s(llog_file,"\n ma_ma eat array ******************************** �ַ����� %d ��\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(llog_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(llog_file,"\n");
	}
	fflush(llog_file);
#endif

	//----------------------------------------------------------------------------
	PMul = King_to_Ma_Mult;
	find = 0;
	for(sq = 0; sq < 90; sq++){	
		if(isZero){
			PMul[sq] = 0;
		}
		if(PMul[sq] == 0){
			find_king_to_ma_magic(&PMul[sq], sq, 4);
			if(PMul[sq] != 0){
				find++;
			}
		}		
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n king_to_ma eat mage_num: sq: %4d\n",sq);
		fflush(llog_file);
#endif
	}
#ifdef  USE_LOG_FILE
	//�ٴ�ӡ����
	fprintf_s(llog_file,"\n king_to_ma eat array ******************************** �ַ����� %d ��\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(llog_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(llog_file,"\n");
	}
	fflush(llog_file);
#endif
	//----------------------------------------------------------------------------
	PMul = XIANG_Mult;
	find = 0;
	for(sq = 0; sq < 90; sq++){	
		if(isZero){
			PMul[sq] = 0;
		}
		if((sq == 2 || sq == 6 || sq == 18 || sq == 22 || sq == 26
			|| sq == 38 || sq == 42
			|| sq == 47 || sq == 51 || sq == 63 || sq == 67 || sq == 71
			|| sq == 83 || sq == 87) == FALSE) continue;
		if(PMul[sq] == 0){
			find_xiang_magic(&PMul[sq], sq, 4);
			if(PMul[sq] != 0){
				find++;
			}
		}
#ifdef  USE_LOG_FILE
		fprintf_s(stdout,"\n xiang eat mage_num: sq: %4d\n",sq);
		fflush(llog_file);
#endif
	}
#ifdef  USE_LOG_FILE
	//�ٴ�ӡ����
	fprintf_s(llog_file,"\n xiang eat array ******************************** �ַ����� %d ��\n",find);
	for(sq = 0; sq < 90; sq++){
		fprintf_s(llog_file,"0x%.16I64X,",PMul[sq]);
		if((sq%6)==5) fprintf_s(llog_file,"\n");
	}
	fflush(llog_file);
#endif
}
#endif
