#ifndef BUILD_mossa_gen
#define BUILD_mossa_gen

#include "chess.h" 



#include "preGen.h"
#include "iniz_gen.h"  // ���ӵĳ��ӷ�

#define flag_check 0x8000  // #define pietra_scacco 0x8000 �����ı�־

#ifdef MULTIPLE_HISTORY
#define LIST_ADD_noncap(L,from,to,piece,sca) \
	{(L++)->move =  MOVE_FromTo(from,to)  \
	| (HISTORY[POSITION->cpu][piece][to] << 16)\
	| (bit_is_set(sca,to) ? flag_check : 0); }
// �����಻���ܽ���
#define LIST_ADD_noncap_no(L,from,to,piece) \
	{(L++)->move =  MOVE_FromTo(from,to)  \
	| (HISTORY[POSITION->cpu][piece][to] << 16);}
#else
	#define MoveAdd(L, x, pi, to, check) \
	  { (L++)->move = (x) | ( (SqSet[to] & (check) ) ? FLAG_CHECK : 0) \
	  | ( HISTORY[pi][to] << 16); }
#endif


#define LIST_ADD_cap(L,from,to,piece) \
	{ (L++)->move = MOVE_FromTo(from,to) | CAPTURE_VALU[piece][PB90(to)]; }


#ifdef MULTIPLE_POS_GAIN
//teest
#define GAIN_ADD(L,from,to,piece,ai) \
		{ mossa =  MOVE_FromTo(from,to); \
		v = ( (int) MAX_POSITIONAL_GAIN[POSITION->cpu][piece][(mossa) & GAIN_MASK]); \
		if (v >= av) (L++)->move = (mossa) | (v << 16); }

//#define GAIN_ADD(L,from,to,piece,ai) \
//		{ mossa =  MOVE_FromTo(from,to); \
//		v = ( (int) MAX_POSITIONAL_GAIN[POSITION->cpu][piece][(mossa) & GAIN_MASK]); \
//		(L++)->move = (mossa) | (v << 16); }
#else
	//#define guadagno_ALLEGA(L, x, pezzo, ai) \
	//{ int v = ( (int) massimo_posizionale_guadagno[pezzo][(x) & 07777]); \
	//	if (v >= av) (L++)->mossa = (x) | (v << 16); }
#endif

#define SORTA\
	for (p = LISTA - 1; p >= sm; p--)\
	{ mossa = p->move;\
	for (q = p + 1; q < LISTA; q++)\
	{ if ( mossa<(int)(q->move) ) (q - 1)->move = q->move;\
		  else break;\
	}\
	q--;\
	q->move = mossa; }


#define OK(x)	(((x & 0x7fff) != s1) && ((x & 0x7fff) != s2) && ((x & 0x7fff) != s3))


#ifdef USE_STOCK_FISH_FILE
#else

void SortOrdinary	(typeMoveList * m1, typeMoveList * m2, uint32 s1, uint32 s2, uint32 s3)
{	
	typeMoveList *p, *q;
	uint32 mossa;
	if (m1 == m2)
		return;
	for (p = m2 - 1; p >= m1; p--)
	{
		if (OK (p->move))
			break;
		p->move = 0;
	}
	while (p > m1)
	{
		p--;
		mossa = p->move;
		if (OK (mossa))
		{
			for (q = p + 1; q < m2; q++)
			{
				if (mossa < (q->move))
					(q - 1)->move = q->move;
				else
					break;
			}
			q--;
			q->move = mossa;
		}
		else
		{
			m2--;
			for (q = p; q < m2; q++)
				q->move = (q + 1)->move;
			m2->move = 0;
		}
	}
}

typeMoveList * EvasionMoves (const typePOS *POSITION, typeMoveList * lista, Bitboard cel)
{
	if(POS_SIDE)
		return WhiteEvasions (POSITION, lista, cel);
	return BlackEvasions (POSITION, lista, cel);
}

typeMoveList * OrdinaryMoves (const typePOS *POSITION, typeMoveList * lista)
{
	if (POS_SIDE)
		return WhiteOrdinary (POSITION, lista);
	return BlackOrdinary (POSITION, lista);
}

typeMoveList * CaptureMoves (const typePOS *POSITION, typeMoveList * lista, Bitboard cel)
{
	if(POS_SIDE){
		return WhiteCaptures (POSITION, lista, m_and(cel,bitboard_occ_black));  // capture_white
	}
	return BlackCaptures (POSITION, lista, m_and(cel,bitboard_occ_white));
}

#endif

#include "move_gen.cpp"
#include "white.h"
#else
#include "black.h"
#endif

#ifdef USE_STOCK_FISH_FILE
#else

// �ҷ����߲��ǲ��ǺϷ��߲���
bool myIsLegalEvasionMove(const typePOS *POSITION,int from, int to){
	Bitboard occ = POSITION->byWhiteBlack;
	int myk = my_king_pos;
	
	clear_bit(occ,from);
	set_bit(occ,to);
	// fen 2bak4/4a4/4b4/N3p1R1p/5N3/2p2c3/4P3P/9/2cCAK3/3A1r3 w
	if(PB90(from) == my_king){  //����ߵ��ǽ�����Ҫ������һ�¡� 
		myk = to;
	}

	// 2.1.1. �ǲ��Ǹ��Է��� ��,�� ����, ** �����������˶Է�����.ͬʱȥ�˶Է�������
	if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],
		m_or(POSITION->byChessBB[your_king],POSITION->byChessBB[your_che])),
		rook_attacks_bb(myk,occ)))) {
			return FALSE; 
	}

	// 2.1.2. �ǲ��ǻ����Է����ڽ���
	if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION->byChessBB[your_pao]),
		pao_eat_attacks_bb(myk,occ)))){
			return FALSE;
	}

	// 2.1.3. �ǲ��ǻ����Է�������
	if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION->byChessBB[your_ma]),
		king_to_ma_attacks_bb(myk,occ)))){
			return FALSE;
	}

	// 2.1.4 �ǲ��ǻ����Է��ı�����
	if(m128_is_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION->byChessBB[your_pawn]),
		your_attack_by_pawn(myk)))){
			return FALSE;
	}
	
	return TRUE;
}

//  �⽫��
typeMoveList * MyEvasion  (const typePOS *POSITION, typeMoveList * LISTA, Bitboard c2)
{
	Bitboard occ              = POSITION->byWhiteBlack;
	Bitboard paoJia_BB        = _mm_setzero_si128 ();        // �ڼ��ϵ�����, ���ߵ������ĵط�ȥ�⽫. 
	Bitboard PaoJia_CannotEva = _mm_setzero_si128 ();        // ���ڼ��ϵģ������ߵ��ڼ���ȥ�⽫��
	Bitboard can_eva_BB   = _mm_set1_epi32(0xFFFFFFFF);    // ���ܽ⽫�����
	Bitboard att;
	Bitboard mpawnBB;
	Bitboard btmp;
	Bitboard ghp;
	Bitboard checker      = my_king_check;           // �õ����������.	
	int myk = my_king_pos;
	int check_sq;
	int i;
	int from,to;
	//int check90[90];
	//int pao_check_num = 0;

	// ȥ���Լ������ӡ�
	c2 = _mm_andnot_si128(MyOccupied,c2);  //�����ߵ��Լ�����������⽫��

	//ASSERT(m128_is_have_bit(checker));

#ifdef DEBUG_TMP
	if(m128_is_have_bit(checker) == 0){
		board_display(POSITION,"no_checker!");
		// Attack_By_Rpawn_Rking[sq]
		// OneRpawnOrRking_AttackBB
		//print_bb(Attack_By_Rpawn_Rking[12]);
		//print_bb(OneRpawnOrRking_AttackBB[12]);
		myk = myk;
	}
#endif
	//fen 2bak4/4a4/4b4/N3p1R1p/5N3/2p2c3/4P3P/9/2cCAK3/3A1r3 w

	//board_display(POSITION,"move_check!");

	while(m128_is_have_bit(checker)){  // ��������ж�,�϶��������ڽ���
		check_sq = pop_1st_bit(&checker);
		switch(PB90(check_sq)){
			case your_pawn:
				can_eva_BB = m_and(can_eva_BB,SetMaskBB[check_sq]);
				break;
			case your_ma:
				can_eva_BB = m_and(can_eva_BB,
					m_or(SetMaskBB[check_sq],SetMaskBB[maleg(check_sq,myk)]));  // ����������
				//print_bb(can_eva_BB);board_display(board,"eva ma");
				break;	
			case your_che:
				can_eva_BB = m_and(can_eva_BB,
					m_or(BetweenBB[check_sq][myk],SetMaskBB[check_sq]));        // ����,�Գ���	
				break;
			case your_pao:
				can_eva_BB = m_and(can_eva_BB,
					m_or(BetweenBB[check_sq][myk],SetMaskBB[check_sq]));        // ����,���ڲ�
				paoJia_BB  = m_or(paoJia_BB,                                    // �ڼ��ϵ�������������
					m_and(BetweenBB[check_sq][myk],occ));
				//pao_check_num++;
				PaoJia_CannotEva = m_or(PaoJia_CannotEva,BetweenBB[check_sq][myk]); //�����ڲ������ߵ���һ���ڵ�����ȥ��
				break;					
			case your_king:
				ASSERT(0);
				break;
			default:
				ASSERT(0);
				break;
		}
	}

	// ��һ���ǲ���ֻ�ܶ����⽫
	if(m128_is_have_bit(m_or(can_eva_BB,paoJia_BB)) == 0){
		goto ONLY_MOVE_KING_EVASION;
	}

	// ===================================================================================
	// ���ܲ��ܽ⽫��. �ҷ������������ܲ����ߵ��Ƕ�.
	// �ҷ����ڵĽ⽫��
	for(i = 0; i < my_pao_num; i++){
		from = S90_from_piecelist(POSITION,my_pao,i);
		 att = m_and(m_or(
			 m_and(pao_eat_attacks_bb(from,occ),OppOccupied),   // ���Ӳ�,
			 _mm_andnot_si128(occ,rook_attacks_bb(from,occ))),c2);       // �����Ӳ�.
		 if(bit_is_set(paoJia_BB,from)){                                 // ����������ڼ�, Ҫ������е����				
			 att = _mm_andnot_si128(PaoJia_CannotEva,att);	             // �����ڲ������ߵ���һ���ڵ�����ȥ��		
		 }
		 else{
			 att = m_and(att,can_eva_BB);
		 }		
		 while(m128_is_have_bit(att)){  // no test leagel
			 to = pop_1st_bit(&att);
			 if(myIsLegalEvasionMove(POSITION,from,to)){
			     LIST_ADD_cap(LISTA,from,to,my_pao);
			 }
		 }
	}
	// �ҷ��ĳ��Ľ⽫��
	for(i = 0; i < my_che_num; i++){
		from = S90_from_piecelist(POSITION,my_che,i);
		att =  m_and(rook_attacks_bb(from,occ),c2);     //
		if(bit_is_set(paoJia_BB,from)){                          // ����������ڼ�, Ҫ������е����
			att = _mm_andnot_si128(PaoJia_CannotEva,att);	     // �����ڲ������ߵ���һ���ڵ�����ȥ��			
		}
		else{
			att = m_and(att,can_eva_BB);
		}		
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			if(myIsLegalEvasionMove(POSITION,from,to)){
			   LIST_ADD_cap(LISTA,from,to,my_che);
			}
		}
	}
	// �ҷ�����Ľ⽫��
	for(i = 0; i < my_ma_num; i++){
		from = S90_from_piecelist(POSITION,my_ma,i);
		att =  m_and(ma_to_king_attacks_bb(from,occ),c2);   //
		if(bit_is_set(paoJia_BB,from)){           // ����������ڼ�, Ҫ������е����
		}
		else{
			att = m_and(att,can_eva_BB);
		}
		
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			if(myIsLegalEvasionMove(POSITION,from,to)){
			    LIST_ADD_cap(LISTA,from,to,my_ma);
			}
		}
	}
	// �ҷ�����Ľ⽫��
	for(i = 0; i < my_xiang_num; i++){
		from = S90_from_piecelist(POSITION,my_xiang,i);
		att =  m_and(xiang_attacks_bb(from,occ),c2);   // �õ�������λ�õ����п��߲�
		if(bit_is_set(paoJia_BB,from)){                         // ����������ڼ�, Ҫ������е����
		}
		else{
			att = m_and(att,can_eva_BB);
		}		
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			if(myIsLegalEvasionMove(POSITION,from,to)){
			    LIST_ADD_cap(LISTA,from,to,my_xiang);
			}
		}
	}
	// �ҷ����˵Ľ⽫��
	for(i = 0; i < my_shi_num; i++){
		from = S90_from_piecelist(POSITION,my_shi,i);
		att =  m_and(shi_attacks(from),c2);   // �õ�������λ�õ����п��߲�
		if(bit_is_set(paoJia_BB,from)){                // ����������ڼ�, Ҫ������е����
		}
		else{
			att = m_and(att,can_eva_BB);
		}		
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			if(myIsLegalEvasionMove(POSITION,from,to)){
			     LIST_ADD_cap(LISTA,from,to,my_shi);
			}
		}
	}

	// ===================================================================================
	// ���еı��⽫��, ������Ľ⽫�Ƚϸ���
	// ����һ����. 
	//***********************************************************
	//�������б��Ĳ������߲� 5����һ������߲�
	//***********************************************************
	mpawnBB = POSITION->byChessBB[my_pawn];
	btmp    = mpawnBB;
	//���б���ǰ�Ĳ����Ӳ�
	//BB_and_BB2(tmp,rpawnBB,NotRank0BB); //ȥ�����һ�ŵı�
	btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),btmp);
	//���б���ǰһ��
	my_m_Rsf(btmp,9);
	//��Ŀ�����AND
	//BB_and_BB(tmp,target);	
	btmp =  m_and(btmp,c2);   //
	while(m128_is_have_bit(btmp)){			
		to   = pop_1st_bit(&btmp);
		from = my_pawn_add_9(to);
		if(bit_is_set(paoJia_BB,from)){           // ����������ڼ�, Ҫ������е����
			if(!bit_is_set(PaoJia_CannotEva,to)){
				if(myIsLegalEvasionMove(POSITION,from,to)){
				   LIST_ADD_cap(LISTA,from,to,my_pawn);  
				}
			}			
		}
		else{
			if(bit_is_set(can_eva_BB,to)){
				if(myIsLegalEvasionMove(POSITION,from,to)){
				   LIST_ADD_cap(LISTA,from,to,my_pawn);
				}
			}
		}
	}
	
	//�õ����ӱ� //���б����ҵĲ�
	ghp = my_guo_he_pawn(mpawnBB);
	if(m128_is_have_bit(ghp)){			
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),ghp);	    // ȥ��������ı�		
		m_Rsf(btmp,1);                    // ���б�����һ��	
		btmp =  m_and(btmp,c2);   //
		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			from = to + 1;
			if(bit_is_set(paoJia_BB,from)){           // ����������ڼ�, Ҫ������е����
				if(myIsLegalEvasionMove(POSITION,from,to)){
				    LIST_ADD_cap(LISTA,from,to,my_pawn);
				}
			}
			else{
				if(bit_is_set(can_eva_BB,to)){
					if(myIsLegalEvasionMove(POSITION,from,to)){
					      LIST_ADD_cap(LISTA,from,to,my_pawn);
					}
				}
			}
		}			
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),ghp);	      // ȥ��������ı�
		m_Lsf(btmp,1);                   // ���б�����һ��
		btmp =  m_and(btmp,c2);   //
		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			from = to - 1;
			if(bit_is_set(paoJia_BB,from)){           // ����������ڼ�, Ҫ������е����
				if(myIsLegalEvasionMove(POSITION,from,to)){
				   LIST_ADD_cap(LISTA,from,to,my_pawn);
				}
			}
			else{
				if(bit_is_set(can_eva_BB,to)){
					if(myIsLegalEvasionMove(POSITION,from,to)){
					   LIST_ADD_cap(LISTA,from,to,my_pawn);
					}
				}
			}
		}
	} 

ONLY_MOVE_KING_EVASION:
	// ===================================================================================
	// ��󶯽����⽫�� 
	// ===================================================================================
	att =  m_and(my_pawn_k_attacks(myk),c2);   // �õ�������λ�õ����п��߲�
	//att = _mm_andnot_si128(OppAttacked,att);            // �ҷ��Ľ������ߵ��Է�������������档
	//�����������ۣ����ǿ��ڵ�ʱ��
	while(m128_is_have_bit(att)){
		to = pop_1st_bit(&att);
		if(myIsLegalEvasionMove(POSITION,myk,to)){
		   LIST_ADD_cap(LISTA,myk,to,my_king);
		}
	}	
	LISTA->move = 0;
	return LISTA;
}
// my_gain
typeMoveList * MyPositionalGain	(const typePOS *POSITION, typeMoveList * LISTA, int av)
{    
	Bitboard occ = POSITION->byWhiteBlack;
	//int yk_pos = your_king_pos;  // �õ��ԵĽ���λ��
	Bitboard bbMyPawn;
	Bitboard btmp;
	Bitboard ghp;
	Bitboard att;
	typeMoveList *sm, *p, *q;
	int mossa;	
	int from,to;
	int i;
	int v;
	sm = LISTA;	
		
	//***********************************************************
	// ���е����Ĳ����Ӳ�
	//***********************************************************
	from = my_king_pos;
	att = _mm_andnot_si128(occ,my_pawn_k_attacks(from));
	//att = _mm_andnot_si128(OppAttacked,att);  // �ҷ��Ľ������ߵ��Է�������������档
	while(m128_is_have_bit(att)){
		to = pop_1st_bit(&att);
		GAIN_ADD(LISTA,from,to,my_king,ai);
	}

	//***********************************************************
	// �������б��Ĳ������߲� 5����һ������߲�
	//***********************************************************
	bbMyPawn = POSITION->byChessBB[my_pawn];
	btmp     = bbMyPawn;
	btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),btmp);	
	my_m_Rsf(btmp,9); // ���б���ǰһ
	btmp = _mm_andnot_si128(occ,btmp);          //��Ŀ�����xorAND
	while(m128_is_have_bit(btmp)){
		to = pop_1st_bit(&btmp);	
		GAIN_ADD(LISTA,my_pawn_add_9(to),to,my_pawn,ai);
	}
	// �õ����ӱ�	
	ghp = my_guo_he_pawn(bbMyPawn);  // Bitboard ghp = m_and(rpawnBB,RpawnOverBB);
	if(m128_is_have_bit(ghp)){			
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),ghp); // BB_and_BB2(tmp,ghp,NotFile0BB);         //ȥ��������ı�	
		m_Rsf(btmp,1);                     //���к������һ��			
		btmp = _mm_andnot_si128(occ,btmp);           //��Ŀ�����xorAND
		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			GAIN_ADD(LISTA,to+1,to,my_pawn,ai);
		}	
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),ghp); //BB_and_BB2(tmp,ghp,NotFile8BB);  //ȥ��������ı�
		m_Lsf(btmp,1);           //���к������һ��	
		btmp = _mm_andnot_si128(occ,btmp);         //��Ŀ�����xorAND
		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			GAIN_ADD(LISTA,to-1,to,my_pawn,ai);
		}
	}
	//***********************************************************
	//����������Ĳ������߲�
	//***********************************************************
	for(i = 0; i < my_xiang_num; i++){
		from = S90_from_piecelist(POSITION,my_xiang,i);
		att = _mm_andnot_si128(occ,xiang_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			GAIN_ADD(LISTA,from,to,my_xiang,ai);
		}
	}
	//***********************************************************
	//�������к��˵Ĳ������߲�
	//***********************************************************
	for(i = 0; i < my_shi_num; i++){
		from = S90_from_piecelist(POSITION,my_shi,i);
		att = _mm_andnot_si128(occ,shi_attacks(from));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			GAIN_ADD(LISTA,from,to,my_shi,ai);
		}
	}
	//***********************************************************
	//���������ڵĲ������߲�
	//***********************************************************
	for(i = 0; i < my_pao_num; i++){
		from = S90_from_piecelist(POSITION,my_pao,i);
		att = _mm_andnot_si128(occ,rook_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			GAIN_ADD(LISTA,from,to,my_pao,ai);
		}
	}
	//***********************************************************
	//����������Ĳ������߲�
	//***********************************************************
	for(i = 0; i < my_ma_num; i++){
		from = S90_from_piecelist(POSITION,my_ma,i);
		att = _mm_andnot_si128(occ,ma_to_king_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			GAIN_ADD(LISTA,from,to,my_ma,ai);
		}
	}	
	//***********************************************************
	//�������г��Ĳ������߲�
	//***********************************************************
	for(i = 0; i < my_che_num; i++){
		from = S90_from_piecelist(POSITION,my_che,i);
		att = _mm_andnot_si128(occ,rook_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			GAIN_ADD(LISTA,from,to,my_che,ai);
		}
	}
	

	//
	LISTA->move = 0;
	SORTA;
	return LISTA;
}
// my_capture 
typeMoveList * MyCapture (const typePOS *POSITION, typeMoveList * LISTA, Bitboard cel)
{	
	Bitboard att;
	Bitboard bbMyPawn;
    Bitboard btmp;
	Bitboard ghp;
	Bitboard occ = POSITION->byWhiteBlack;
	int i;
	int from,to;
	if(m128_is_have_bit(m_and(cel,MyAttacked)) == 0){
		goto TARGA_NON;  // û�г��Ӳ�
	}
	//***********************************************************
	//�������б��Ĳ������߲� 5����һ������߲�
	//***********************************************************
	//board_display(POSITION,"capture_move\n");
	//print_bb(cel);
	bbMyPawn = POSITION->byChessBB[my_pawn];
	btmp     = bbMyPawn;
	btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),btmp);	
	my_m_Rsf(btmp,9); //���б���ǰһ��
	btmp = m_and(btmp,cel);          //��Ŀ�����AND
	while(m128_is_have_bit(btmp)){
		to = pop_1st_bit(&btmp);
		LIST_ADD_cap(LISTA,my_pawn_add_9(to),to,my_pawn);
	}	
	ghp = my_guo_he_pawn(bbMyPawn); // �õ����ӱ�
	if(m128_is_have_bit(ghp)){	   
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),ghp);  //ȥ��������ı�	
		m_Rsf(btmp,1);                                         //���к������һ��			
		btmp = m_and(btmp,cel);                                 //��Ŀ�����AND
		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			LIST_ADD_cap(LISTA,to+1,to,my_pawn);
		}
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),ghp);  //ȥ��������ı�
		m_Lsf(btmp,1);           //���к������һ��	
		btmp = m_and(btmp,cel);          //��Ŀ�����AND
		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			LIST_ADD_cap(LISTA,to-1,to,my_pawn);
		}
	}
	//***********************************************************
	// ����������ĳ����߲�
	//***********************************************************
	for(i = 0; i < my_xiang_num; i++){
		from = S90_from_piecelist(POSITION,my_xiang,i);
		att = m_and(cel,xiang_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_xiang);
		}
	}
	//***********************************************************
	// �������к��˵ĳ����߲�
	//***********************************************************
	for(i = 0; i < my_shi_num; i++){
		from = S90_from_piecelist(POSITION,my_shi,i);
		att = m_and(cel,shi_attacks(from));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_shi);
		}
	}
	//***********************************************************
	// ���������ڵĳ����߲�
	//***********************************************************
	for(i = 0; i < my_pao_num; i++){
		from = S90_from_piecelist(POSITION,my_pao,i);
		att = m_and(cel,pao_eat_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_pao);
		}
	}
	//***********************************************************
	// ����������ĳ����߲�
	//***********************************************************
	for(i = 0; i < my_ma_num; i++){
		from = S90_from_piecelist(POSITION,my_ma,i);
		att = m_and(cel,ma_to_king_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_ma);
		}
	}
	//***********************************************************
	// �������г��ĳ����߲�
	//***********************************************************
	for(i = 0; i < my_che_num; i++){
		from = S90_from_piecelist(POSITION,my_che,i);
		att = m_and(cel,rook_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_che);
		}
	}
	//***********************************************************
	// ���е����ĳ��Ӳ�
	//***********************************************************
	from = my_king_pos; // 
	att = m_and(cel,my_pawn_k_attacks(from)); // fen rnbakCbnr/4a4/1c5c1/p1p3p1p/3RN4/9/P1P1P1P1P/3C5/5K3/R1BA1ABN1 b - - 	
	// att = _mm_andnot_si128(OppAttacked,att); // �ҷ��Ľ������ߵ������Ľ��Ĺ�����ȥ��ȥ�˶Է��Ĺ�������// print_bb(att);	
	while(m128_is_have_bit(att)){
		to = pop_1st_bit(&att);
		LIST_ADD_cap(LISTA,from,to,my_king);
	}
TARGA_NON: // ����Ҳ����Ӳ�
	LISTA->move = 0;
	return LISTA;
}

//  ���ڳ�׽�жϵ� my_capture_not_include_king_pawn
typeMoveList * mio_cattura_not_include_pawn_king (const typePOS *POSITION, typeMoveList * LISTA){	
	Bitboard att;
	//Bitboard bbMyPawn;
    //Bitboard btmp;
	//Bitboard ghp;
	Bitboard occ = POSITION->byWhiteBlack;

	//if(m128_is_have_bit(m_and(cel,my_attack)) == 0){
	//	goto TARGA_NON;  // û�г��Ӳ�
	//}
	Bitboard cel = OppOccupied;
	int i;
	int from,to;

	////***********************************************************
	////�������б��Ĳ������߲� 5����һ������߲�
	////***********************************************************
	//bbMyPawn = POSITION->byChessBB[my_pawn];
	//btmp     = bbMyPawn;
	////���б���ǰһ��
	//my_m_Rsf(btmp,9);

	//// BB_and_BB(tmp,target);        
	//btmp = m_and(btmp,cel);          //��Ŀ�����AND
	//while(m128_is_have_bit(btmp)){
	//	int to = pop_1st_bit(&btmp);
	//	// LIST_ADD(list,MOVE_FromTo(my_pawn_add_9,to));
	//	LIST_ADD_cap(LISTA,my_pawn_add_9(to),to,my_pawn);
	//}

	//// �õ����ӱ�
	//// Bitboard ghp = m_and(rpawnBB,RpawnOverBB);
	//ghp = my_guo_he_pawn(bbMyPawn);

	//// BB_and_BB2(ghp,rpawnBB,RpawnOverBB);
	//if(m128_is_have_bit(ghp)){			
	//	//BB_and_BB2(tmp,ghp,NotFile0BB);         //ȥ��������ı�	
	//	btmp = _mm_andnot_si128(File0BB,ghp);
	//	m_Rsf(btmp,1);                     //���к������һ��			
	//	btmp = m_and(btmp,cel);          //��Ŀ�����AND
	//	while(m128_is_have_bit(btmp)){
	//		int to = pop_1st_bit(&btmp);
	//		//LIST_ADD(list,MOVE_FromTo(to+1,to));
	//		LIST_ADD_cap(LISTA,to+1,to,my_pawn);
	//	}			
	//	//BB_and_BB2(tmp,ghp,NotFile8BB);  //ȥ��������ı�
	//	btmp = _mm_andnot_si128(File8BB,ghp);
	//	m_Lsf(btmp,1);           //���к������һ��	
	//	btmp = m_and(btmp,cel);          //��Ŀ�����AND
	//	while(m128_is_have_bit(btmp)){
	//		int to = pop_1st_bit(&btmp);
	//		LIST_ADD_cap(LISTA,to-1,to,my_pawn);
	//	}
	//}

	//***********************************************************
	// ����������ĳ����߲�
	//***********************************************************
	for(i = 0; i < my_xiang_num; i++){
		from = S90_from_piecelist(POSITION,my_xiang,i);
		att = m_and(cel,xiang_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_xiang);
		}
	}

	//***********************************************************
	// �������к��˵ĳ����߲�
	//***********************************************************
	for(i = 0; i < my_shi_num; i++){
		from = S90_from_piecelist(POSITION,my_shi,i);
		att = m_and(cel,shi_attacks(from));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_shi);
		}
	}

	//***********************************************************
	// ���������ڵĳ����߲�
	//***********************************************************
	for(i = 0; i < my_pao_num; i++){
		from = S90_from_piecelist(POSITION,my_pao,i);
		att = m_and(cel,pao_eat_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_pao);
		}
	}
	//***********************************************************
	// ����������ĳ����߲�
	//***********************************************************
	for(i = 0; i < my_ma_num; i++){
		from = S90_from_piecelist(POSITION,my_ma,i);
		att = m_and(cel,ma_to_king_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_ma);
		}
	}

	//***********************************************************
	// �������г��ĳ����߲�
	//***********************************************************
	for(i = 0; i < my_che_num; i++){
		from = S90_from_piecelist(POSITION,my_che,i);
		att = m_and(cel,rook_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_cap(LISTA,from,to,my_che);
		}
	}

	//***********************************************************
	// ���е����ĳ��Ӳ�
	//***********************************************************

	//from = my_king_pos;
	//att = m_and(cel,my_pawn_k_attacks(from));
	//while(m128_is_have_bit(att)){
	//	to = pop_1st_bit(&att);
	//	LIST_ADD_cap(LISTA,from,to,my_king);
	//}

//TARGA_NON: // ����Ҳ����Ӳ�
	LISTA->move = 0;
	return LISTA;
}

// �����Ӳ�.
typeMoveList * MyOrdinary (const typePOS *POSITION, typeMoveList * LISTA)
{	
	Bitboard att;
	Bitboard bbMyPawn;
    Bitboard btmp;
	Bitboard ghp;
	Bitboard occ = POSITION->byWhiteBlack;
	Bitboard RE;
	int i;
	int from,to;
	int yk_pos = your_king_pos;  // �õ��ԵĽ���λ��

	//***********************************************************
	// ���е����Ĳ����Ӳ�
	//***********************************************************

	from = my_king_pos;
	att = _mm_andnot_si128(occ,my_pawn_k_attacks(from));
	//att = _mm_andnot_si128(OppAttacked,att);  // �ҷ��Ľ������ߵ��Է�������������档
	while(m128_is_have_bit(att)){
		to = pop_1st_bit(&att);
		LIST_ADD_noncap_no(LISTA,from,to,my_king);
	}
	
	RE = my_attack_by_pawn(yk_pos);   // Attack_By_Rpawn_Rking
	//***********************************************************
	// �������б��Ĳ������߲� 5����һ������߲�
	//***********************************************************
	bbMyPawn = POSITION->byChessBB[my_pawn];
	btmp     = bbMyPawn;
	//���б���ǰһ��
	//���Ȱѵ�һ�ߵı�ȥ�ˡ� //MyLastRankPawnBB
	btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),btmp);
	my_m_Rsf(btmp,9);
	// fen 4k4/9/9/8p/4P4/9/9/6C2/9/4K4 b
	//BB_and_BB(tmp,target);        
	btmp = _mm_andnot_si128(occ,btmp);          // ��Ŀ�����xorAND
	while(m128_is_have_bit(btmp)){
		to = pop_1st_bit(&btmp);
		LIST_ADD_noncap(LISTA,my_pawn_add_9(to),to,my_pawn,RE);
	}

	// �õ����ӱ�
	// Bitboard ghp = m_and(rpawnBB,RpawnOverBB);
	ghp = my_guo_he_pawn(bbMyPawn);
	// BB_and_BB2(ghp,rpawnBB,RpawnOverBB);
	if(m128_is_have_bit(ghp)){			
		// BB_and_BB2(tmp,ghp,NotFile0BB);           // ȥ��������ı�	
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),ghp);
		m_Rsf(btmp,1);                     // ���к������һ��			
		btmp = _mm_andnot_si128(occ,btmp);           // ��Ŀ�����xorAND

		//print_bb(btmp); // fen 2bak4/4a4/4b4/p1P6/2n6/2R4R1/3r2r2/3N4B/4A4/2B1KA3 w

		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			LIST_ADD_noncap(LISTA,to+1,to,my_pawn,RE);
		}			
		// BB_and_BB2(tmp,ghp,NotFile8BB);         // ȥ��������ı�
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),ghp);
		m_Lsf(btmp,1);                    // ���к������һ��	
		btmp = _mm_andnot_si128(occ,btmp);         // ��Ŀ�����xorAND
		while(m128_is_have_bit(btmp)){
			to = pop_1st_bit(&btmp);
			LIST_ADD_noncap(LISTA,to-1,to,my_pawn,RE);
		}
	}

	//***********************************************************
	// ����������Ĳ������߲�
	//***********************************************************
	for(i = 0; i < my_xiang_num; i++){
		from = S90_from_piecelist(POSITION,my_xiang,i);
		att = _mm_andnot_si128(occ,xiang_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_noncap_no(LISTA,from,to,my_xiang);
		}
	}

	//***********************************************************
	// �������к��˵Ĳ������߲�
	//***********************************************************
	for(i = 0; i < my_shi_num; i++){
		from = S90_from_piecelist(POSITION,my_shi,i);
		att = _mm_andnot_si128(occ,shi_attacks(from));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_noncap_no(LISTA,from,to,my_shi);
		}
	}

	RE = pao_eat_attacks_bb(yk_pos,occ);
	//***********************************************************
	// ���������ڵĲ������߲�
	//***********************************************************
	for(i = 0; i < my_pao_num; i++){
		from = S90_from_piecelist(POSITION,my_pao,i);
		att = _mm_andnot_si128(occ,rook_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_noncap(LISTA,from,to,my_pao,RE);
		}
	}

	RE = king_to_ma_attacks_bb(yk_pos,occ); 
	//***********************************************************
	// ����������Ĳ������߲�
	//***********************************************************
	for(i = 0; i < my_ma_num; i++){
		from = S90_from_piecelist(POSITION,my_ma,i);
		att = _mm_andnot_si128(occ,ma_to_king_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_noncap(LISTA,from,to,my_ma,RE);
		}
	}

	RE = rook_attacks_bb(yk_pos,occ);
	//***********************************************************
	// �������г��Ĳ������߲�
	//***********************************************************
	for(i = 0; i < my_che_num; i++){
		from = S90_from_piecelist(POSITION,my_che,i);
		att = _mm_andnot_si128(occ,rook_attacks_bb(from,occ));
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			LIST_ADD_noncap(LISTA,from,to,my_che,RE);
		}
	}

	

	LISTA->move = 0;
	return LISTA;
}

// �����ӵĽ�����
typeMoveList * MyQuietChecks (const typePOS *POSITION, typeMoveList * LISTA, Bitboard cel )
{
	
	Bitboard check_target;
	Bitboard king_super;
	Bitboard king_pao;
	Bitboard king_che;
	Bitboard king_ma;
	Bitboard pao_super_att;
	Bitboard pao_eat_att;
	Bitboard ma_att;
	Bitboard kong_pao_att;
	Bitboard chouJiangChessBB2    = _mm_setzero_si128 ();  // ���Գ齫�����ӣ�
	Bitboard dianJiangBB          = _mm_setzero_si128 ();  // ���Ե��������
	Bitboard att;
	Bitboard p;
	//Bitboard T;
	Bitboard ktoma;
	int mossa;
	int i;
	int yk_pos;
	int mk_pos;
	int from,to;
	int sq;

	Bitboard occ = POSITION->byWhiteBlack;

	cel = m_not(cel);
	cel = _mm_andnot_si128(occ,cel); // cel = ( ~cel) &~MyOccupied;

	yk_pos = your_king_pos;          // �õ��ԵĽ���λ��

	king_super = pao_super_attacks_bb(yk_pos,occ);
	king_pao   = pao_eat_attacks_bb  (yk_pos,occ);
	king_ma    = Ma_Pseudo_Att[yk_pos];
	king_che   = rook_attacks_bb(yk_pos,occ);
	
	// A. �ҵ��齫������.�����ֿ��ܣ��������ڣأؽ��������ǳ��ؽ�, 3, ��X��.
	
	// 1, Ҫ������XX��,
	pao_super_att = m_and(POSITION->byChessBB[my_pao], king_super);
	while(m128_is_have_bit(pao_super_att)){
		sq = pop_1st_bit(&pao_super_att); 
		chouJiangChessBB2 = m_or(BetweenBB[sq][yk_pos], chouJiangChessBB2); 
	}

	// 2, ��X��
	pao_eat_att = m_and(POSITION->byChessBB[my_che],	king_pao);
	while(m128_is_have_bit(pao_eat_att)){
		sq = pop_1st_bit(&pao_eat_att);
		chouJiangChessBB2 = m_or(BetweenBB[sq][yk_pos], chouJiangChessBB2);  // ����齫������.		  
	}

	// 3, ��X��,
	ma_att = m_and(POSITION->byChessBB[my_ma], king_ma);
	while(m128_is_have_bit(ma_att)){       // board_display(board, "");
		int ma  = pop_1st_bit(&ma_att);    //
		int leg = maleg(ma,yk_pos);
		set_bit(chouJiangChessBB2,leg);    // ����齫������.
	}

	// B. �ҵ���������񣨿��ڣ����������ܲ����ߵ���Щ��񣮲�Ҫ�������ѳ齫�����ӣ�
	kong_pao_att = m_and(POSITION->byChessBB[my_pao], king_che);
	while(m128_is_have_bit(kong_pao_att)){
		sq = pop_1st_bit(&kong_pao_att);		  
		dianJiangBB = m_or(BetweenBB[sq][yk_pos], dianJiangBB);	
	}

	//***********************************************************
	// �������г��Ĳ����ӽ����߲�
	//***********************************************************
	for(i = 0; i < my_che_num; i++){
		from = S90_from_piecelist(POSITION,my_che,i);
		att =  rook_attacks_bb(from,occ);  
		att = m_and(att,cel);
		if(bit_is_set(chouJiangChessBB2,from)){   // ������ӿɳ齫,��ɲ������е��߲�.���������ߵ��齫�Ĳ���
		    // ����ߵ�������Է��Ľ���һ��
			if(bit_is_set(ChePseudoMask_FR[yk_pos],from)){
				att = _mm_andnot_si128(chouJiangChessBB2,att);	
			}
			//att = _mm_andnot_si128(occ,att);   // ȥ�˳��Ӳ�.
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				mossa = MOVE_FromTo(from,to);
				//if(MySEE(POSITION, mossa)){ // �齫��Ҫ�ж�
					(LISTA++)->move = mossa;
				//}
			}
		}
		else {  // ������Ӳ��ɳ齫, ��ɲ���������, ��ֱ�ӽ�����.
			check_target = m_or(m_and(king_che,att),  // �ҵ������
					dianJiangBB);   // ���ϵ��������
			att = m_and(att,check_target);
			//att = _mm_andnot_si128(occ,att);   // ȥ�˳��Ӳ�.
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				mossa = MOVE_FromTo(from,to);
				//if(MySEE(POSITION, mossa)){
					(LISTA++)->move = mossa;
				//}
			}
		}		
	}
	//***********************************************************
	// ���������ڵĲ����ӽ����߲�
	//***********************************************************
	for(i = 0; i < my_pao_num; i++){
		from = S90_from_piecelist(POSITION,my_pao,i);
		att = rook_attacks_bb(from,occ);          // �ڵĲ����� only use rook_attack
		att = m_and(att,cel);
		if(bit_is_set(chouJiangChessBB2,from)){   // ������ӿɳ齫,��ɲ������е��߲�.���������ߵ��齫�Ĳ���
			// ����ߵ�������Է��Ľ���һ��
			if(bit_is_set(ChePseudoMask_FR[yk_pos],from)){
				att = _mm_andnot_si128(chouJiangChessBB2,att);	
			} //fen 4k1b2/5C3/2nrbN2n/p1p6/4P3p/2P3P2/P7P/4C3B/4A4/2B1KA1rc w - - 0 0	
			//att = _mm_andnot_si128(occ,att);   // ȥ�˳��Ӳ�.
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				mossa = MOVE_FromTo(from,to);
				//if(MySEE (POSITION, mossa)){
					(LISTA++)->move = mossa;
				//}
			}
		}
		else{                                    // ������Ӳ��ɳ齫, ��ɲ���������, ��ֱ�ӽ�����.
			// fen rnbakabnr/9/7c1/p1p1p1p1p/9/9/P1P1c1P1P/1C4NC1/9/R1BAKABNR b - - 0 0
			// �����������ڽ��ĳ�ATT��,�򲻿������������Ľ�.
			if(bit_is_set(king_che,from)){
				continue;
			}
			check_target = m_or(m_and(king_pao,att),  // �ҵ������,���복��һ��.
				dianJiangBB);  // ���ϵ��������
			att = m_and(att,check_target);
			//att = _mm_andnot_si128(occ,att);   // ȥ�˳��Ӳ�.
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				mossa = MOVE_FromTo(from,to);
				//if(MySEE (POSITION, mossa)){
					(LISTA++)->move = mossa;
				//}
			}
		}		
	}
	//***********************************************************
	// ����������Ĳ����ӽ����߲�
	//***********************************************************
	ktoma = king_to_ma_attacks_bb(yk_pos,occ);
	for(i = 0; i < my_ma_num; i++){
		from = S90_from_piecelist(POSITION,my_ma,i);
		att = ma_to_king_attacks_bb(from,occ);
		att = m_and(att,cel);
		if(bit_is_set(chouJiangChessBB2,from)){   // ������ӿɳ齫,��ɲ������е��߲�.���������ߵ��齫�Ĳ���
			//att = _mm_andnot_si128(chouJiangChessBB,att);	
			//att = _mm_andnot_si128(occ,att);   //ȥ�˳��Ӳ�.
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				mossa = MOVE_FromTo(from,to);
				//if(MySEE (POSITION, mossa)){
					(LISTA++)->move = mossa;
				//}
			}		
		}
		else{                                     // ������Ӳ��ɳ齫, ��ɲ���������, ��ֱ�ӽ�����.
			check_target = m_or(m_and(ktoma,att),  // �ҵ������,
				dianJiangBB);  // ���ϵ��������
			att = m_and(att,check_target);
		}
		//att = _mm_andnot_si128(occ,att);   //ȥ�˳��Ӳ�.
		while(m128_is_have_bit(att)){
			to = pop_1st_bit(&att);
			mossa = MOVE_FromTo(from,to);
			//if(MySEE (POSITION, mossa)){
				(LISTA++)->move = mossa;
			//}
		}
	}

	//***********************************************************
	// �������б��Ĳ����ӽ����߲�
	//***********************************************************
    // 1, ֻ�й��˺ӵı����ܲ���������
	p = my_guo_he_pawn(bitboard_my_pawn);
	if(m128_is_have_bit(p)){  // ��ǰ���˹��ӱ�
		// �õ��ɳ齫�ı� ----------------------------------------------------------------------
		p = m_and(chouJiangChessBB2,p);
		if(m128_is_have_bit(p)){
			// ���б���ǰһ��		
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),p); //���Ȱѵ�һ�ߵı�ȥ�ˡ� //MyLastRankPawnBB
			my_m_Rsf(att,9);
			att = m_and(att,cel); // Ŀ�����
			att = _mm_andnot_si128(chouJiangChessBB2,att);	// ȥ����һ���ϵ��岽
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);			
				//if(MySEE (POSITION, mossa)){
				(LISTA++)->move = MOVE_FromTo(my_pawn_add_9(to),to);
				//}
			}
			// ���б�����һ��
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);
			m_Rsf(att,1);                     // ���к������һ��
			att = m_and(att,cel); // Ŀ�����
			att = _mm_andnot_si128(chouJiangChessBB2,att);	// ȥ����һ���ϵ��岽
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);			
				//if(MySEE (POSITION, mossa)){
				(LISTA++)->move = MOVE_FromTo(to+1,to);
				//}
			}
			// ���б�����һ��
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
			m_Lsf(att,1);                     // ���к������һ��
			att = m_and(att,cel); // Ŀ�����
			att = _mm_andnot_si128(chouJiangChessBB2,att);	// ȥ����һ���ϵ��岽
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);			
				//if(MySEE (POSITION, mossa)){
				(LISTA++)->move = MOVE_FromTo(to-1,to);
				//}
			}
		}
		// �������ɳ齫�ı� ----------------------------------------------------------------------
		p = _mm_andnot_si128(chouJiangChessBB2,my_guo_he_pawn(bitboard_my_pawn));	
		if(m128_is_have_bit(p)){
			// Attack_By_Rpawn_Rking my_attack_by_pawn
			check_target = m_or(my_attack_by_pawn(your_king_pos),dianJiangBB);  // ���ϵ��������
			check_target = m_and(check_target,cel); 
			// ���б���ǰһ��		
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),p); //���Ȱѵ�һ�ߵı�ȥ�ˡ� //MyLastRankPawnBB
			my_m_Rsf(att,9);
			att = m_and(att,check_target); // Ŀ�����
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);			
				//if(MySEE (POSITION, mossa)){
				(LISTA++)->move = MOVE_FromTo(my_pawn_add_9(to),to);
				//}
			}
			// ���б�����һ��
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);
			m_Rsf(att,1);                     // ���к������һ��
			att = m_and(att,check_target); // Ŀ�����
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);			
				//if(MySEE (POSITION, mossa)){
				(LISTA++)->move = MOVE_FromTo(to+1,to);
				//}
			}
			// ���б�����һ��
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
			m_Lsf(att,1);                     // ���к������һ��
			att = m_and(att,check_target); // Ŀ�����
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);			
				//if(MySEE (POSITION, mossa)){
				(LISTA++)->move = MOVE_FromTo(to-1,to);
				//}
			}
		}
	}

	// ��, ��, ��, ����ֱ�ӽ�. 
	if(m128_is_have_bit(chouJiangChessBB2) || m128_is_have_bit(dianJiangBB)){
		//***********************************************************
		// �������к���Ĳ����ӽ����߲�
		//***********************************************************
		for(i = 0; i < my_xiang_num; i++){
			from = S90_from_piecelist(POSITION,my_xiang,i);
			att =  xiang_attacks_bb(from,occ);  // �õ�������λ�õ����п��߲�
			att = m_and(att,cel);
			if(bit_is_set(chouJiangChessBB2,from)){   // ������ӿɳ齫,��ɲ������е��߲�.���������ߵ��齫�Ĳ���
				// att = _mm_andnot_si128(chouJiangChessBB,att);		  
			}
			else{                                    // ������Ӳ��ɳ齫, ��ɲ���������, 
				att = m_and(att,dianJiangBB);
			}
			//att = _mm_andnot_si128(occ,att);   // ȥ�˳��Ӳ�.
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				(LISTA++)->move = MOVE_FromTo(from,to);
			}
		}

		//***********************************************************
		// �������к��˵Ĳ����ӽ����߲�
		//***********************************************************
		for(i = 0; i < my_shi_num; i++){
			from = S90_from_piecelist(POSITION,my_shi,i);
			att = shi_attacks(from);  // �õ�������λ�õ����п��߲�
			att = m_and(att,cel);
			if(bit_is_set(chouJiangChessBB2,from)){   // ������ӿɳ齫,��ɲ������е��߲�.���������ߵ��齫�Ĳ���
				// att = _mm_andnot_si128(chouJiangChessBB,att);		  
			}
			else{                                    // ������Ӳ��ɳ齫, ��ɲ���������, 
				att = m_and(att,dianJiangBB);
			}
			//att = _mm_andnot_si128(occ,att);   // ȥ�˳��Ӳ�.
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				(LISTA++)->move = MOVE_FromTo(from,to);
			}
		}

		//***********************************************************
		// �������к콫�Ĳ����ӽ����߲�
		//***********************************************************
		mk_pos = my_king_pos;
		if(bit_is_set(chouJiangChessBB2,mk_pos)){          // ������ӿɳ齫,��ɲ������е��߲�.���������ߵ��齫�Ĳ���
			att = my_pawn_k_attacks(mk_pos);               // �õ�������λ�õ����п��߲�  
			att = _mm_andnot_si128(chouJiangChessBB2,att);	
			//att = _mm_andnot_si128(occ,att);                  //ȥ�˳��Ӳ�.
			att = m_and(att,cel);
			//att = _mm_andnot_si128(OppAttacked,att);  // �ҷ��Ľ������ߵ��Է�������������档
			while(m128_is_have_bit(att)){
				to = pop_1st_bit(&att);
				(LISTA++)->move = MOVE_FromTo(mk_pos,to);
			}
		}
	}


	LISTA->move = 0;
	return LISTA;
}


#endif
