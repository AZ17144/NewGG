
#ifndef BUILD_mossa_gen_ST
#define BUILD_mossa_gen_ST

#include "chess.h"
////
//// Includes
////

#include <cassert>


#include "movegen.h"

#define SERIALIZE_MOVES(from,to)  (*mlist++).move = make_move(from, to);


// Explicit template instantiations
template<> 
ExtMove* generate<CAPTURES>(Position& pos, ExtMove* mlist){
	
	//ASSERT(pos.pos_is_ok());
	ASSERT(!pos.in_check());

	if(pos.side_to_move() == WHITE){
		return WhiteCaptures(pos,mlist);
	}
	return BlackCaptures(pos,mlist);    
}

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////
template<> 
ExtMove* generate<QUIETS>(Position& pos, ExtMove* mlist){
	
		//ASSERT(pos.pos_is_ok());
		ASSERT(!pos.in_check());
	
		if(pos.side_to_move() == WHITE){
			return WhiteOrdinary(pos,mlist);
		}
		return BlackOrdinary(pos,mlist);  
}

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////
template<> 
ExtMove* generate<NON_EVASIONS>(Position& pos, ExtMove* mlist){

	mlist = generate<CAPTURES>(pos,mlist);
	mlist = generate<QUIETS>(pos,mlist);

	return mlist;
}

//////////////////////////////////////////////////////////////////////////
/// �����ӵĽ�����
/// generate<MV_NON_CAPTURE_CHECK> generates all pseudo-legal non-captures and knight
/// underpromotions that give check. Returns a pointer to the end of the move list.
template<>
ExtMove* generate<QUIET_CHECKS>(Position& pos, ExtMove* mlist) {

	//ASSERT(pos.pos_is_ok());
	ASSERT(!pos.in_check());

	if(pos.side_to_move() == WHITE){
		return QuietChecksWhite(pos,mlist);
	}
	return QuietChecksBlack(pos,mlist);  
}

/// generate<MV_EVASION> generates all pseudo-legal check evasions when the side
/// to move is in check. Returns a pointer to the end of the move list.
template<>
ExtMove* generate<EVASIONS>(Position& pos, ExtMove* mlist) {

	//ASSERT(pos.pos_is_ok());
	ASSERT(pos.in_check());

	if(pos.side_to_move() == WHITE){
		return WhiteEvasions(pos,mlist);
	}
	return BlackEvasions(pos,mlist); 
}

//////////////////////////////////////////////////////////////////////////
/// generate<MV_LEGAL> generates all legal moves in the current position
//////////////////////////////////////////////////////////////////////////

template<>
ExtMove* generate<LEGAL>(Position& pos, ExtMove* mlist) {	

	ExtMove *last, *cur = mlist;
	//Bitboard pinned = pos.pinned_pieces(pos.side_to_move());
	
	last = pos.in_check() ? generate<EVASIONS>(pos, mlist)
		: generate<NON_EVASIONS>(pos, mlist);

	// Remove illegal moves from the list
	while (cur != last){
		if (!pos.legal(cur->move)) 
			cur->move = (--last)->move;
		else
			cur++;
	}

	return last;
}

#include "movegen.cpp"
#include "s_white.h"
#else
#include "s_black.h"
#endif

//////////////////////////////////////////////////////////////////////////
// �ҷ����߲��ǲ��ǺϷ��߲���
bool myIsLegalEvasionMove(typePOS &POSITION,Square from, Square to){
//#undef NOT_VERIFEY_EVAMOVE
//#ifdef NOT_VERIFEY_EVAMOVE
//	return true;
//#else	
	Bitboard ncc = BitboardOCC;
	Square mk = my_king_pos;

	clear_bit(ncc,from);
	set_bit(ncc,to);
	// fen 2bak4/4a4/4b4/N3p1R1p/5N3/2p2c3/4P3P/9/2cCAK3/3A1r3 w
	if(from == mk){  //����ߵ��ǽ�����Ҫ������һ�¡� 
		mk = to;
	}	
	Bitboard KFR = ChePseudoMask_FR[mk];

	// 2.1.1. �ǲ��Ǹ��Է��� ��,�� ����, ** �����������˶Է�����.ͬʱȥ�˶Է�������
	if(have_bit(KFR,m_or(POSITION.pieces(your_king),POSITION.pieces(your_che)))){
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],
			m_or(POSITION.pieces(your_king),POSITION.pieces(your_che))),
			POSITION.Rook_attacks_bb(mk,ncc)))) {  		
				return false; 
		}
	}

	// 2.1.2. �ǲ��ǻ����Է����ڽ���
	if(have_bit(KFR,POSITION.pieces(your_pao))){
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION.pieces(your_pao)),
			POSITION.Pao_Eat_bb(mk,ncc)))) {   // pao_eat_attacks_bb(myk,occ)))){
				return false;
		}
	}

	// 2.1.3. �ǲ��ǻ����Է�������
	if(have_bit(Ma_Pseudo_Att[mk],POSITION.pieces(your_ma))){
		if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION.pieces(your_ma)),
			POSITION.king_to_ma_attacks_bb(mk,ncc)))){
				return false;
		}
	}

	// 2.1.4 �ǲ��ǻ����Է��ı�����
	if(m_have_bit(m_and(_mm_andnot_si128(SetMaskBB[to],POSITION.pieces(your_pawn)),
		your_attack_by_pawn(mk)))){
			return false;
	}
	return true;
//#endif
}


//////////////////////////////////////////////////////////////////////////
// ���Ӳ�
ExtMove* MyCapture(typePOS &POSITION, ExtMove* mlist) {

	// �Է������.
	Bitboard cel = OppOccupied;

	//***********************************************************
	//�������б��Ĳ������߲� 5����һ������߲�
	//***********************************************************
	Bitboard bbMyPawn = POSITION.pieces(my_pawn);
	//
	Bitboard btmp = bbMyPawn;
	btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),btmp);	
	my_m_Rsf(btmp,9); //���б���ǰһ��
	btmp = m_and(btmp,cel);          //��Ŀ�����AND
	Square to;
	while (pop_1st_bit_sq(btmp, to)) {
		SERIALIZE_MOVES(my_pawn_add_9(to),to);
	}	
	Bitboard ghp = my_guo_he_pawn(bbMyPawn); // �õ����ӱ�
	if(m_have_bit(ghp)){	   
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),ghp);  //ȥ��������ı�	
		m_Rsf(btmp,1);                                         //���к������һ��			
		btmp = m_and(btmp,cel);                                 //��Ŀ�����AND
		while (pop_1st_bit_sq(btmp, to)) {
			SERIALIZE_MOVES(to+1,to);
		}
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),ghp);  //ȥ��������ı�
		m_Lsf(btmp,1);           //���к������һ��	
		btmp = m_and(btmp,cel);          //��Ŀ�����AND
		while (pop_1st_bit_sq(btmp, to)) {
			SERIALIZE_MOVES(to-1,to);
		}
	}
	//***********************************************************
	// ����������ĳ����߲�
	//***********************************************************
	for(int i = 0; i < my_xiang_num; i++){
		Square from = S90_from_piecelist(POSITION,my_xiang,i);
		Bitboard att = m_and(cel,POSITION.xiang_attacks_bb(from));
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// �������к��˵ĳ����߲�
	//***********************************************************
	for(int i = 0; i < my_shi_num; i++){
		Square from = S90_from_piecelist(POSITION,my_shi,i);
		Bitboard att = m_and(cel,shi_attacks(from));
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// ���������ڵĳ����߲�
	//***********************************************************
	for(int i = 0; i < my_pao_num; i++){
		Square from = S90_from_piecelist(POSITION,my_pao,i);
		Bitboard att = m_and(cel,POSITION.Pao_Eat_bb(from));
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// ����������ĳ����߲�
	//***********************************************************
	for(int i = 0; i < my_ma_num; i++){
		Square from = S90_from_piecelist(POSITION,my_ma,i);
		Bitboard att = m_and(cel,POSITION.ma_to_king_attacks_bb(from));
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}

	//***********************************************************
	// �������г��ĳ����߲�
	//***********************************************************
	for(int i = 0; i < my_che_num; i++){
		Square from = S90_from_piecelist(POSITION,my_che,i);
		Bitboard att = m_and(cel,POSITION.Rook_attacks_bb(from));
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}

	//***********************************************************
	// ���е����ĳ��Ӳ�
	//***********************************************************
	Square from = my_king_pos; // 
	Bitboard att = m_and(cel,my_pawn_k_attacks(from)); // fen rnbakCbnr/4a4/1c5c1/p1p3p1p/3RN4/9/P1P1P1P1P/3C5/5K3/R1BA1ABN1 b - - 	
	while (pop_1st_bit_sq(att, to)) {
		SERIALIZE_MOVES(from,to);
	}

	return mlist;
}

//////////////////////////////////////////////////////////////////////////
//  �⽫��,�������ȫ�⽫��
ExtMove* MyEvasion  (typePOS &POSITION, ExtMove* mlist)
{
	Bitboard occ = BitboardOCC;
	Bitboard paoJia_BB        = _mm_setzero_si128 ();        // �ڼ��ϵ�����, ���ߵ������ĵط�ȥ�⽫. 
	Bitboard PaoJia_CannotEva = _mm_setzero_si128 ();        // ���ڼ��ϵģ������ߵ��ڼ���ȥ�⽫��
	Bitboard can_eva_BB       = _mm_set1_epi32(0xFFFFFFFF);      // ���ܽ⽫�����
	Bitboard checker          = POSITION.checkers(); // my_king_check;           // �õ����������.	
	Bitboard ghp;
	Bitboard mpawnBB;
	Bitboard btmp;
	Square myk = my_king_pos;

	// ȥ���Լ������ӡ������ߵ��Լ�����������⽫��
	//Bitboard c2 = _mm_andnot_si128(MyOccupied,_mm_set1_epi32(0xFFFFFFFF));  //

	ASSERT(m_have_bit(checker));

	// fen 2bak4/4a4/4b4/N3p1R1p/5N3/2p2c3/4P3P/9/2cCAK3/3A1r3 w
	//board_display(POSITION,"move_check!");
	Square check_sq;
	while (pop_1st_bit_sq(checker, check_sq)) { // ��������ж�,�϶��������ڽ���
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
	if(m_have_bit(m_or(can_eva_BB,paoJia_BB)) == 0){
		goto ONLY_MOVE_KING_EVASION;
	}

	// ===================================================================================
	// ���ܲ��ܽ⽫��. �ҷ������������ܲ����ߵ��Ƕ�.
	// �ҷ����ڵĽ⽫��
	for(int i = 0; i < my_pao_num; i++){
		Square from = S90_from_piecelist(POSITION,my_pao,i);

		Bitboard att = m_or(m_and(POSITION.Pao_Eat_bb(from),OppOccupied),  // ���Ӳ�,
			_mm_andnot_si128(occ,POSITION.Rook_attacks_bb(from)));         // �����Ӳ�.

		 if(bit_is_set(paoJia_BB,from)){                                 // ����������ڼ�, Ҫ������е����				
			 att = _mm_andnot_si128(PaoJia_CannotEva,att);	             // �����ڲ������ߵ���һ���ڵ�����ȥ��		
		 }
		 else{
			 att = m_and(att,can_eva_BB);
		 }	
		 Square to;
		 while (pop_1st_bit_sq(att, to)) {
			 if(myIsLegalEvasionMove(POSITION,from,to)){
				 SERIALIZE_MOVES(from,to);
			 }
		 }
	}
	// �ҷ��ĳ��Ľ⽫��
	for(int i = 0; i < my_che_num; i++){
		Square from = S90_from_piecelist(POSITION,my_che,i);
		Bitboard att = _mm_andnot_si128(MyOccupied,POSITION.Rook_attacks_bb(from));
		if(bit_is_set(paoJia_BB,from)){                          // ����������ڼ�, Ҫ������е����
			att = _mm_andnot_si128(PaoJia_CannotEva,att);	     // �����ڲ������ߵ���һ���ڵ�����ȥ��			
		}
		else{
			att = m_and(att,can_eva_BB);
		}		
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			if(myIsLegalEvasionMove(POSITION,from,to)){
			   SERIALIZE_MOVES(from,to);
			}
		}
	}
	// �ҷ�����Ľ⽫��
	for(int i = 0; i < my_ma_num; i++){
		Square from = S90_from_piecelist(POSITION,my_ma,i);
		Bitboard att = _mm_andnot_si128(MyOccupied,POSITION.ma_to_king_attacks_bb(from));
		if(bit_is_set(paoJia_BB,from)){           // ����������ڼ�, Ҫ������е����
		}
		else{
			att = m_and(att,can_eva_BB);
		}
		
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			if(myIsLegalEvasionMove(POSITION,from,to)){
			    SERIALIZE_MOVES(from,to);
			}
		}
	}
	// �ҷ�����Ľ⽫��
	for(int i = 0; i < my_xiang_num; i++){
		Square from = S90_from_piecelist(POSITION,my_xiang,i);
		Bitboard att = _mm_andnot_si128(MyOccupied,POSITION.xiang_attacks_bb(from));
		if(bit_is_set(paoJia_BB,from)){                         // ����������ڼ�, Ҫ������е����
		}
		else{
			att = m_and(att,can_eva_BB);
		}		
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			if(myIsLegalEvasionMove(POSITION,from,to)){
			    SERIALIZE_MOVES(from,to);
			}
		}
	}
	// �ҷ����˵Ľ⽫��
	for(int i = 0; i < my_shi_num; i++){
		Square from = S90_from_piecelist(POSITION,my_shi,i);
		Bitboard att = _mm_andnot_si128(MyOccupied,shi_attacks(from));
		if(bit_is_set(paoJia_BB,from)){                // ����������ڼ�, Ҫ������е����
		}
		else{
			att = m_and(att,can_eva_BB);
		}		
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			if(myIsLegalEvasionMove(POSITION,from,to)){
			    SERIALIZE_MOVES(from,to);
			}
		}
	}

	// ===================================================================================
	// ���еı��⽫��, ������Ľ⽫�Ƚϸ���
	// ����һ����. 
	//***********************************************************
	//�������б��Ĳ������߲� 5����һ������߲�
	//***********************************************************
	mpawnBB = POSITION.pieces(my_pawn); // POSITION.byChessBB[my_pawn];
	btmp    = mpawnBB;
	//���б���ǰ�Ĳ����Ӳ�
	//BB_and_BB2(tmp,rpawnBB,NotRank0BB); //ȥ�����һ�ŵı�
	btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),btmp);
	//���б���ǰһ��
	my_m_Rsf(btmp,9);
	btmp = _mm_andnot_si128(MyOccupied,btmp);
	Square to;
	while (pop_1st_bit_sq(btmp, to)) {
		Square from = my_pawn_add_9(to);
		if(bit_is_set(paoJia_BB,from)){           // ����������ڼ�, Ҫ������е����
			if(!bit_is_set(PaoJia_CannotEva,to)){
				if(myIsLegalEvasionMove(POSITION,from,to)){
				   SERIALIZE_MOVES(from,to); 
				}
			}			
		}
		else{
			if(bit_is_set(can_eva_BB,to)){
				if(myIsLegalEvasionMove(POSITION,from,to)){
				   SERIALIZE_MOVES(from,to);
				}
			}
		}
	}
	
	//�õ����ӱ� //���б����ҵĲ�
	ghp = my_guo_he_pawn(mpawnBB);
	if(m_have_bit(ghp)){			
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),ghp);	    // ȥ��������ı�		
		m_Rsf(btmp,1);                    // ���б�����һ��	
		btmp = _mm_andnot_si128(MyOccupied,btmp);
		while (pop_1st_bit_sq(btmp, to)) {
			Square from = to + 1;
			if(bit_is_set(paoJia_BB,from)){           // ����������ڼ�, Ҫ������е����
				if(myIsLegalEvasionMove(POSITION,from,to)){
				    SERIALIZE_MOVES(from,to);
				}
			}
			else{
				if(bit_is_set(can_eva_BB,to)){
					if(myIsLegalEvasionMove(POSITION,from,to)){
					      SERIALIZE_MOVES(from,to);
					}
				}
			}
		}			
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),ghp);	      // ȥ��������ı�
		m_Lsf(btmp,1);                   // ���б�����һ��
		btmp = _mm_andnot_si128(MyOccupied,btmp);
		while (pop_1st_bit_sq(btmp, to)) {
			Square from = to - 1;
			if(bit_is_set(paoJia_BB,from)){           // ����������ڼ�, Ҫ������е����
				if(myIsLegalEvasionMove(POSITION,from,to)){
				   SERIALIZE_MOVES(from,to);
				}
			}
			else{
				if(bit_is_set(can_eva_BB,to)){
					if(myIsLegalEvasionMove(POSITION,from,to)){
					   SERIALIZE_MOVES(from,to);
					}
				}
			}
		}
	} 

ONLY_MOVE_KING_EVASION:
	// ===================================================================================
	// ��󶯽����⽫�� 
	// ===================================================================================
	Bitboard att = _mm_andnot_si128(MyOccupied,my_pawn_k_attacks(myk));
	while (pop_1st_bit_sq(att, to)) {
		if(myIsLegalEvasionMove(POSITION,myk,to)){
		   SERIALIZE_MOVES(myk,to);
		}
	}	
	return mlist;
}

//////////////////////////////////////////////////////////////////////////
// �����Ӳ�.
ExtMove* MyOrdinary (typePOS &POSITION, ExtMove* mlist)
{	

	Bitboard occ = BitboardOCC;
	
	//***********************************************************
	// �������б��Ĳ������߲� 5����һ������߲� btmp = _mm_andnot_si128(occ,btmp);          // ��Ŀ�����xorAND
	//***********************************************************
	Bitboard bbMyPawn = POSITION.pieces(my_pawn);
	Bitboard btmp     = bbMyPawn;
	//���б���ǰһ��
	//���Ȱѵ�һ�ߵı�ȥ�ˡ� //MyLastRankPawnBB
	btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),btmp);
	my_m_Rsf(btmp,9);
	// fen 4k4/9/9/8p/4P4/9/9/6C2/9/4K4 b   
	btmp = _mm_andnot_si128(occ,btmp);          // ��Ŀ�����xorAND
	Square to;
	while (pop_1st_bit_sq(btmp, to)) {
		SERIALIZE_MOVES(my_pawn_add_9(to),to);
	}

	// �õ����ӱ�
	// Bitboard ghp = m_and(rpawnBB,RpawnOverBB);
	Bitboard ghp = my_guo_he_pawn(bbMyPawn);
	// BB_and_BB2(ghp,rpawnBB,RpawnOverBB);
	if(m_have_bit(ghp)){			
		// BB_and_BB2(tmp,ghp,NotFile0BB);           // ȥ��������ı�	
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),ghp);
		m_Rsf(btmp,1);                     // ���к������һ��			
		btmp = _mm_andnot_si128(occ,btmp);           // ��Ŀ�����xorAND

		//print_bb(btmp); // fen 2bak4/4a4/4b4/p1P6/2n6/2R4R1/3r2r2/3N4B/4A4/2B1KA3 w

		while (pop_1st_bit_sq(btmp, to)) {
			SERIALIZE_MOVES(to+1,to);
		}			
		// BB_and_BB2(tmp,ghp,NotFile8BB);         // ȥ��������ı�
		btmp = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),ghp);
		m_Lsf(btmp,1);                    // ���к������һ��	
		btmp = _mm_andnot_si128(occ,btmp);         // ��Ŀ�����xorAND
		while (pop_1st_bit_sq(btmp, to)) {
			SERIALIZE_MOVES(to-1,to);
		}
	}

	//***********************************************************
	// ����������Ĳ������߲�
	//***********************************************************
	for(int i = 0; i < my_xiang_num; i++){
		Square from = S90_from_piecelist(POSITION,my_xiang,i);
		Bitboard att = _mm_andnot_si128(occ,POSITION.xiang_attacks_bb(from));
		//Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}

	//***********************************************************
	// �������к��˵Ĳ������߲�
	//***********************************************************
	for(int i = 0; i < my_shi_num; i++){
		Square from = S90_from_piecelist(POSITION,my_shi,i);
		Bitboard att = _mm_andnot_si128(occ,shi_attacks(from));
		//Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	
	//***********************************************************
	// ���������ڵĲ������߲�
	//***********************************************************
	for(int i = 0; i < my_pao_num; i++){
		Square from = S90_from_piecelist(POSITION,my_pao,i);
		Bitboard att = _mm_andnot_si128(occ,POSITION.Rook_attacks_bb(from));
		//Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	
	//***********************************************************
	// ����������Ĳ������߲�
	//***********************************************************
	for(int i = 0; i < my_ma_num; i++){
		Square from = S90_from_piecelist(POSITION,my_ma,i);
		Bitboard att = _mm_andnot_si128(occ,POSITION.ma_to_king_attacks_bb(from));
		//Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}

	//***********************************************************
	// �������г��Ĳ������߲�
	//***********************************************************
	for(int i = 0; i < my_che_num; i++){
		Square from = S90_from_piecelist(POSITION,my_che,i);
		Bitboard att = _mm_andnot_si128(occ,POSITION.Rook_attacks_bb(from));
		//Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}

	//***********************************************************
	// ���е����Ĳ����Ӳ�
	//***********************************************************

	Square from = my_king_pos;
	Bitboard att = _mm_andnot_si128(occ,my_pawn_k_attacks(from));
	//att = _mm_andnot_si128(OppAttacked,att);  // �ҷ��Ľ������ߵ��Է�������������档
	//Square to;
	while (pop_1st_bit_sq(att, to)) {
		SERIALIZE_MOVES(from,to);
	}

	return mlist;
}
//////////////////////////////////////////////////////////////////////////
// �����ӵĽ�����
ExtMove* MyQuietChecks (typePOS &POSITION, ExtMove* mlist)
{	

	Bitboard chouJiangChessBB2    = _mm_setzero_si128 ();  // ���Գ齫�����ӣ�
	Bitboard dianJiangBB          = _mm_setzero_si128 ();  // ���Ե��������

	Bitboard occ = BitboardOCC;
	Square yk_pos = your_king_pos;          // �õ��ԵĽ���λ��

	Bitboard king_pao   = POSITION.Pao_Eat_bb(yk_pos);	
	Bitboard king_che   = POSITION.Rook_attacks_bb(yk_pos);
	
	// A. �ҵ��齫������.�����ֿ��ܣ��������ڣأؽ��������ǳ��ؽ�, 3, ��X��.
	
	// 1, Ҫ������XX��,
	if(have_bit(bb_my_pao,ChePseudoMask_FR[yk_pos])){
		for(int i = 0; i < my_pao_num; i++){
			Square s = S90_from_piecelist(POSITION,my_pao,i);
			Bitboard bet = m_and(BetweenBB[s][yk_pos],occ);
			switch(count_1s(bet)){
			case 0: // ����
				dianJiangBB = m_or(BetweenBB[s][yk_pos], dianJiangBB); 
				break;
			case 2: // ���ڣ�����
				chouJiangChessBB2 = m_or(BetweenBB[s][yk_pos], chouJiangChessBB2); 
				break;
			default:
				break;
			}
		}
	}

	// 2, ��X��
	Bitboard pao_eat_att = m_and(POSITION.pieces(my_che),	king_pao);
	Square sq;
	while (pop_1st_bit_sq(pao_eat_att, sq)) {
		chouJiangChessBB2 = m_or(BetweenBB[sq][yk_pos], chouJiangChessBB2);  // ����齫������.		  
	}

	// 3, ��X��,
	Bitboard ma_att = m_and(POSITION.pieces(my_ma), Ma_Pseudo_Att[yk_pos]);
	Square ma;
	while (pop_1st_bit_sq(ma_att, ma)) {
		Square leg = maleg(ma,yk_pos);
		set_bit(chouJiangChessBB2,leg);    // ����齫������.
	}


	//***********************************************************
	// �������г��Ĳ����ӽ����߲�
	//***********************************************************
	for(int i = 0; i < my_che_num; i++){
		Square from = S90_from_piecelist(POSITION,my_che,i);
		Bitboard att =  _mm_andnot_si128(occ,POSITION.Rook_attacks_bb(from)); 
		if(bit_is_set(chouJiangChessBB2,from)){   // ������ӿɳ齫,��ɲ������е��߲�.���������ߵ��齫�Ĳ���
			att = _mm_andnot_si128(chouJiangChessBB2,att);				
		}
		else {  // ������Ӳ��ɳ齫, ��ɲ���������, ��ֱ�ӽ�����.
			att = m_and(att,m_or(king_che,dianJiangBB));			
		}
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// ���������ڵĲ����ӽ����߲�
	//***********************************************************
	for(int i = 0; i < my_pao_num; i++){
		Square from = S90_from_piecelist(POSITION,my_pao,i);
		Bitboard att = _mm_andnot_si128(occ,POSITION.Rook_attacks_bb(from));      // �ڵĲ����� only use rook_attack
		if(bit_is_set(chouJiangChessBB2,from)){   // ������ӿɳ齫,��ɲ������е��߲�.���������ߵ��齫�Ĳ���
			att = _mm_andnot_si128(chouJiangChessBB2,att);	// fen 4k1b2/5C3/2nrbN2n/p1p6/4P3p/2P3P2/P7P/4C3B/4A4/2B1KA1rc w - - 0 0				
		}
		else{                                    // ������Ӳ��ɳ齫, ��ɲ���������, ��ֱ�ӽ�����.
			// fen rnbakabnr/9/7c1/p1p1p1p1p/9/9/P1P1c1P1P/1C4NC1/9/R1BAKABNR b - - 0 0
			// �����������ڽ��ĳ�ATT��,�򲻿������������Ľ�.
			if(bit_is_set(king_che,from)){
				continue;
			}
			att = m_and(att,m_or(king_pao,dianJiangBB));	
		}	
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}
	//***********************************************************
	// ����������Ĳ����ӽ����߲�
	//***********************************************************
	for(int i = 0; i < my_ma_num; i++){
		Square from = S90_from_piecelist(POSITION,my_ma,i);
		Bitboard att = _mm_andnot_si128(occ,POSITION.ma_to_king_attacks_bb(from));
		if(bit_is_set(chouJiangChessBB2,from)){   // ������ӿɳ齫,��ɲ������е��߲�.���������ߵ��齫�Ĳ���	
		}
		else{                                     // ������Ӳ��ɳ齫, ��ɲ���������, ��ֱ�ӽ�����.
			if(have_bit(att,Ma_Pseudo_Att[yk_pos])){
				att = m_and(att,m_or(POSITION.king_to_ma_attacks_bb(yk_pos),dianJiangBB));
			}
			else{
				att = m_and(att,dianJiangBB);
			}
		}
		Square to;
		while (pop_1st_bit_sq(att, to)) {
			SERIALIZE_MOVES(from,to);
		}
	}

	//***********************************************************
	// �������б��Ĳ����ӽ����߲�
	//***********************************************************
    // 1, ֻ�й��˺ӵı����ܲ��������ӵĽ�����
	Bitboard p = my_guo_he_pawn(bb_my_pawn);
	if(m_have_bit(p)){  // ��ǰ���˹��ӱ�
		// �õ��ɳ齫�ı� ----------------------------------------------------------------------
		p = m_and(chouJiangChessBB2,p);
		if(m_have_bit(p)){
			// ���б���ǰһ��		
			Bitboard att = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),p); //���Ȱѵ�һ�ߵı�ȥ�ˡ� //MyLastRankPawnBB
			my_m_Rsf(att,9);
			att = _mm_andnot_si128(occ,att);                // ��Ŀ�����xorAND
			att = _mm_andnot_si128(chouJiangChessBB2,att);	// ȥ����һ���ϵ��岽
			Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(my_pawn_add_9(to),to);
			}
			// ���б�����һ��
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);
			m_Rsf(att,1);                     // ���к������һ��
			att = _mm_andnot_si128(occ,att);          // ��Ŀ�����xorAND
			att = _mm_andnot_si128(chouJiangChessBB2,att);	// ȥ����һ���ϵ��岽
			//Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(to+1,to);				
			}
			// ���б�����һ��
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
			m_Lsf(att,1);                     // ���к������һ��
			att = _mm_andnot_si128(occ,att);          // ��Ŀ�����xorAND
			att = _mm_andnot_si128(chouJiangChessBB2,att);	// ȥ����һ���ϵ��岽
			//Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(to-1,to);	
			}
		}
		// �������ɳ齫�ı� ----------------------------------------------------------------------
		p = _mm_andnot_si128(chouJiangChessBB2,my_guo_he_pawn(bb_my_pawn));	
		if(m_have_bit(p)){
			// Attack_By_Rpawn_Rking my_attack_by_pawn
			Bitboard check_target = m_or(my_attack_by_pawn(your_king_pos),dianJiangBB);  // ���ϵ��������
			check_target = _mm_andnot_si128(occ,check_target);          // ��Ŀ�����xorAND
			// ���б���ǰһ��		
			Bitboard att = _mm_andnot_si128(_mm_load_si128((__m128i*)MyLastRankPawnBB),p); //���Ȱѵ�һ�ߵı�ȥ�ˡ� //MyLastRankPawnBB
			my_m_Rsf(att,9);
			att = m_and(att,check_target); // Ŀ�����			
			Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(my_pawn_add_9(to),to);
			}
			// ���б�����һ��
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File0BB),p);
			m_Rsf(att,1);                     // ���к������һ��
			att = m_and(att,check_target); // Ŀ�����
			//Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(to+1,to);
			}
			// ���б�����һ��
			att = _mm_andnot_si128(_mm_load_si128((__m128i*)File8BB),p);
			m_Lsf(att,1);                     // ���к������һ��
			att = m_and(att,check_target); // Ŀ�����
			//Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(to-1,to);
			}
		}
	}

	// ��, ��, ��, ����ֱ�ӽ�. 
	if(m_have_bit(chouJiangChessBB2) || m_have_bit(dianJiangBB)){
		//***********************************************************
		// �������к���Ĳ����ӽ����߲�
		//***********************************************************
		for(int i = 0; i < my_xiang_num; i++){
			Square from = S90_from_piecelist(POSITION,my_xiang,i);
			Bitboard att =  _mm_andnot_si128(occ,POSITION.xiang_attacks_bb(from));  // �õ�������λ�õ����п��߲�
			if(bit_is_set(chouJiangChessBB2,from)){   // ������ӿɳ齫,��ɲ������е��߲�.���������ߵ��齫�Ĳ���  
			}
			else{                                    // ������Ӳ��ɳ齫, ��ɲ���������, 
				att = m_and(att,dianJiangBB);
			}
			Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(from,to);
			}
		}

		//***********************************************************
		// �������к��˵Ĳ����ӽ����߲�
		//***********************************************************
		for(int i = 0; i < my_shi_num; i++){
			Square from = S90_from_piecelist(POSITION,my_shi,i);
			Bitboard att = _mm_andnot_si128(occ,shi_attacks(from));  // �õ�������λ�õ����п��߲�
			if(bit_is_set(chouJiangChessBB2,from)){   // ������ӿɳ齫,��ɲ������е��߲�.���������ߵ��齫�Ĳ���
			}
			else{                                    // ������Ӳ��ɳ齫, ��ɲ���������, 
				att = m_and(att,dianJiangBB);
			}
			Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(from,to);
			}
		}
		// ����ǳ��ټ���û�б�Ҫ����
		////***********************************************************
		//// �������к콫�Ĳ����ӽ����߲�
		////***********************************************************
		Square mk_pos = my_king_pos;
		if(bit_is_set(chouJiangChessBB2,mk_pos)){                   // ������ӿɳ齫,��ɲ������е��߲�.���������ߵ��齫�Ĳ���
			Bitboard att = my_pawn_k_attacks(mk_pos);               // �õ�������λ�õ����п��߲�  
			att = _mm_andnot_si128(chouJiangChessBB2,att);	
			att= _mm_andnot_si128(occ,att);                          // ��Ŀ�����xorAND
			Square to;
			while (pop_1st_bit_sq(att, to)) {
				SERIALIZE_MOVES(mk_pos,to);
			}
		}
	}

	return mlist;
}
