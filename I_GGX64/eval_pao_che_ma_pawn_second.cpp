#include "..\\chess.h"
#include <cassert>
#include <cstring>
#include "preGen.h"
#include "s_bitcount.h"
#include "s_evaluate.h"
#include "s_material.h"
#include "s_pawns.h"
#include "s_scale.h"
#include "s_thread.h"
#include "s_ucioption.h"
#include "s_eval_const.h"

//////////////////////////////////////////////////////////////////////////
/// �ڶ�����˫�����ڳ���.
template<Color Us>
void evaluate_pao_che_ma_pawn_second(const Position& pos, EvalInfo& ei){

	const Color Them = (Us == WHITE ? BLACK : WHITE);
	const Piece delt = COLOR_BY_SIDE_ADD[Us];
	Bitboard occ     = pos.occupied_squares();
	const Square mk  = pos.king_square(Us);
	const Square yk  = pos.king_square(Them);
	//////////////////////////////////////////////////////////////////////////
	/// ������һ����
	//////////////////////////////////////////////////////////////////////////
	//pos.board_display("eval pao se");
	for(int i = 0; i < pos.piece_count(RPAO + delt); i++){
		Square s =  pos.piece_list(RPAO + delt,i);
		Bitboard A = ei.PaoAtt[Us][i];  // �õ��ڵĹ���λ����
		//print_bb(A);
		// 1. �ڳ��ӽ���
		Bitboard ckatt = m_and(pos.pieces_of_color(Them),
			m_and(A,ei.attackKingPaoCan[Them]));
		if(m_have_bit(ckatt)){
			ei.attPoint[Us] += PaoCan_Eat_Check;  
			// ��ȫ�ĳ��ӽ�
			if(have_bit(ei.SafeBit[Us],ckatt)){
				ei.attPoint[Us] +=  PaoCan_Safe_Eat_Check;					
			}	
			//set_bit(ei.attackKingBoard[Us],s);
		}
		// 2. �ڲ����ӽ���
		Bitboard B = _mm_andnot_si128(occ, rook_attacks_bb(s,occ));
		ckatt = m_and(B,ei.attackKingPaoCan[Them]);
		if(m_have_bit(ckatt)){   // �ڲ�����ֱ�ӽ���
			ei.attPoint[Us] += PaoCan_Direct_Check;  
			// ��ȫ�Ĳ����ӽ���
			if(have_bit(ei.SafeBit[Us],ckatt)){
				ei.attPoint[Us] += PaoCan_Safe_Direct_Check;
			}
			//set_bit(ei.attackKingBoard[Us],s);
		}
		// 3. �����ݽ�
		if(m_have_bit(m_and(B,
			_mm_andnot_si128(BetweenBB[s][yk],ei.KongPaoNull[Us])))){
				ei.attPoint[Us] += PaoCan_TwoPao_Check; 
				set_bit(ei.attackKingBoard[Us],s);
		}

		// 4. ���ڼ����˽���.Ҫ���ڹ�����
		if(bit_is_set(PaoCanAttKing[yk],s)){ // fen 2b2anC1/3kaP3/2P1b4/p7p/8c/3rC4/P3R4/4B4/4AK3/2BA3c1 r
			set_bit(ei.attackKingBoard[Us],s);
			if(have_bit(A,KingAttackZone[yk])){			
				// ���ܿ��ƽ���
				ei.attPoint[Us] += 2;
			}
		}		
	} //void evaluate_pao_che_ma_pawn_second(const Position& pos, EvalInfo& ei){

	//////////////////////////////////////////////////////////////////////////
	/// ������һ�³�
	//////////////////////////////////////////////////////////////////////////
	for(int i = 0; i < pos.piece_count(RCHE + delt); i++){
		Square s =  pos.piece_list(RCHE + delt,i);
		Bitboard A = ei.CheAtt[Us][i];  // �õ����Ĺ���λ����
		// -------------------------------------------------------------------------------------------- 
		// 1. �ƶ����� Mobility
		// -------------------------------------------------------------------------------------------- 
		int mobr, mobf;                                     //pos.board_display("che mob");
		Bitboard B = m_and(A,ei.SafeBit[Us]);

		Bitboard ratt = m_and(B,RankBB_A[StoY(s)]); //print_bb(ratt);
		mobr = count_1s(ratt);

		Bitboard fatt = m_and(B,FileBB_A[StoX(s)]); //print_bb(fatt);
		mobf = count_1s(fatt);
		ei.valu += Sign[Us] * (f_CheMove[mobf] + r_CheMove[mobr]);

		// 2, �쳵�ܹ������Է�. 
		if(have_bit(A,KingAttackZone[yk])){
			set_bit(ei.attackKingBoard[Us],s);                  // ��һ����־, ���ڽ�����
		}	

		// 3. �����������,ҲҪ�ӷ�
		//fen 2bakc1R1/4a4/n1c1b4/N1prC3p/P8/2P3r2/4P1n1P/3C2N2/4A4/1RBAK4 b - - 0 1
	    if(Us == WHITE ? StoY(s) <= 0x4 : StoY(s) >= 0x5){
			set_bit(ei.attackKingBoard[Us],s);  
		}

		// 3. 
		if(bit_is_set(ei.xray_bit[Them],s)){
			//��Ҫ��һЩ,��Ϊ�������ǣ����.
			ei.attPoint[Us] -= Rook_CanNotMove_Att;
			continue;  // �������ǣ����
		}

		// 4. �������ɽ�??
		// ****************************************************************
		Bitboard ckatt = m_and(A,ei.attackKingCheCan[Them]);
		if(m_have_bit(ckatt)){  // �쳵�ܽ���

			set_bit(ei.attackKingBoard[Us],s);      
			ei.attPoint[Us]  += 4;  // �쳵��ֱ�ӽ�

			// ��һ���ǲ��ǰ�ȫ�Ľ�
			if(have_bit(ei.SafeBit[Us],ckatt)){
				ei.attPoint[Us] += RookSafeCheckBonus * count_1s(m_and(ei.SafeBit[Us],ckatt));
			}

			//��һ���ǲ��ǽ���һ����,
			if(bit_is_set(A,mk) && StoX(s) == StoX(mk)){ //fen 4ka3/4aR3/2n5b/4p1N1p/p5b2/4R4/1r2P3P/2r1B4/4A1C2/c1BA1K3 w
				ei.attPoint[Us] += 4;
			}

			// ��һ���ܲ����ݽ� if(m_have_bit(m_and(B,
			if(have_bit(A,ei.KongPaoNull[Us])){
				ei.attPoint[Us] += CheCanPaoNullCHeckPoint;
			}

			if(bit_is_set(A,yk)){ // ���ڽ�����, ���һ��Ҫ����, ��Ϊ�����
				continue;
			}

			//���������ԭλ����û�ж����� 
			//fen 5kb2/4a4/3ab4/9/5R3/2r6/5r3/9/4A4/2B1KA3 b - - 0 0</
			//�����Ϊ���ڽ�����	
			if((Us == WHITE ? 0x04 : 0x55) != yk || pos.piece_count((Us == WHITE ? BSHI : RSHI)) == 0){   // ������ԭλ����û�����ˣ�
				while(m_have_bit(ckatt)){   
					Square ckq = pop_1st_bit(&ckatt);						
					if(pos.see(s,ckq) >= 0){
						if(StoX(ckq) == StoX(yk)){  // �������½�,
							ei.cx[Us] += 2;
						}
						else{
							ei.cy[Us] += 2;
						}
					}
					else{
						if(StoX(ckq) == StoX(yk)){
							ei.cx[Us]++;
						}
						else{
							ei.cy[Us]++;
						}
					}
				}
			} // ������ɱ�����	

		}/// ������һ�³�
	}

	//////////////////////////////////////////////////////////////////////////
	/// ������һ����
	//////////////////////////////////////////////////////////////////////////
	for(int i = 0; i < pos.piece_count(RMA + delt); i++){
		Square s =  pos.piece_list(RMA + delt,i);
		Bitboard A = ei.MaAtt[Us][i];  // �õ���Ĺ���λ����

		// fen 2bakc1R1/4a4/n1c1b4/N1prC3p/P8/2P3r2/4P1n1P/3C2N2/4A4/1RBAK4 b - - 0 1
		// ����Է�ѹ��, 
		//if(Us == WHITE){

		//}
		//else{

		//}

		// fen 2bakabr1/9/n2c2n2/p1p1p3p/6p2/2P6/P1r1P1P1P/CRNCB1Nc1/4A4/2BAK2R1 w - - 0 1

		// 1. ��һ���ܲ����ݽ�
		if(have_bit(A,ei.KongPaoNull[Us])){
			ei.attPoint[Us] += 10;                    // �������ڽ�
			set_bit(ei.attackKingBoard[Us],s);        // ��һ����־, ��������ݽ�,�����Ҳ�������������
		}

		Bitboard ckatt = m_and(A,ei.attackKingMaCan[Them]);
		// 2. ��һ���ܲ���ֱ�ӽ�
		if(m_have_bit(ckatt)){
			ei.attPoint[Us] +=  3;   // MaCanCHeckPoint;
			set_bit(ei.attackKingBoard[Us],s);           // ��һ����־

			// ��һ���ǲ��ǰ�ȫ�Ľ�
			if(have_bit(ei.SafeBit[Us],ckatt)){
				ei.attPoint[Us] += 4; // MaSafeCheckBonus;
			}
		}			

		// 3. �������Է������߲�
		if(m_have_bit(m_and(A,KingAttackZone[yk]))){
			set_bit(ei.attackKingBoard[Us],s);  
			Bitboard bb = m_and(A,
				(Us == WHITE ? one_bpawn_bk_attacks(yk) : one_rpawn_rk_attacks(yk)) );				
			ei.attPoint[Us] += 3 * count_1s(bb);
			ei.attPoint[Us] += 4;
		}
		// (Us == WHITE ? LowBB[0x7] : UpBB[0x2]) 
		// ����Ϊ���������, 
		A = m_and(A,Ma_Pseudo_Good_Att[s]);		  // ������кò�
		A = _mm_andnot_si128((Us == WHITE ? LowBB[0x7] : UpBB[0x2]) ,A);             // ȥ���������
		A = _mm_andnot_si128(pos.pieces_of_color(Us),A);                             // ȥ�����ѵ����			
		Bitboard B = A;
		A = _mm_andnot_si128(ei.attacked_by(Them),A);  // ȥ�˶Է��Ĺ������

		int mob = count_1s(A);
		ei.valu += Sign[Us] * Point_MaMob(MaMoveAddNoProtect[mob]);

		if(mob == 0){ // ��û�кò���
			if(m_have_bit(B)){  // ԭ���кò�
				if(m_have_bit(_mm_andnot_si128(ei.attackedBy[BPAWN - delt],B)) == false){
					//print_bb(B); // fen 2bakabr1/9/c1n3n1c/p3p3p/2P3p2/3R5/P1rNP1P1P/1CN1BC3/8R/3AKAB2 b - - 0 12
					ei.valu -= Sign[Us] * point(48,80); // �����ڸ���������,û�кò���
				}
			}
		}
	} // ������һ���� end

	// �ڶ���ֻ���۹��ӱ�
	// ���
	Bitboard p = m_and(pos.pieces(RPAWN + delt),
		_mm_load_si128((__m128i*)(Us == WHITE ? RpawnOverBB : BpawnOverBB)));
	if(m_have_bit(p)){
		//------- ���ӱ������ļӷ�
		int gh_num     = count_1s(_mm_andnot_si128(
			_mm_load_si128((__m128i*)(Us == WHITE ? Rank0BB : Rank9BB)),p));	// ȥ�˵��߱�
		ei.valu       += Sign[Us] * PAWN_num_OVER_RIVER_point[gh_num];          // ���ӱ��������ӷ�
		Bitboard B = p;
		//------- ����Է�û������,Ҫ�ӷ���
		int yshi    = pos.piece_count(BSHI - delt);  // POSITION->pieceCount[BSHI];
		//int pnum    = 0;
		while(m_have_bit(B)){  // �б�������
			Square pawn = pop_1st_bit(&B);	

			ei.valu += Sign[Us] * (Us == WHITE ? point_B_01Shi_R_Pawn90[yshi][pawn]
			: point_R_01Shi_B_Pawn90[yshi][pawn]) ;             //���ӱ��żӷ�
			Score pawnSafe = PrePawnAttKingMul_Safe[yshi][pawn][yk];    //�����ƽ��ķ�
			if(pawnSafe){
				//if(Us == WHITE) print_bb(B);
				set_bit(ei.attackKingBoard[Us],pawn);                         // ��һ����־
				// 1.��һ�±��ܲ��ܽ���, ת��Ϊbcy,bcx, �����������
				Bitboard Bcheck = m_and( // ��������Խ�����
					Us == WHITE ? 
					one_rpawn_rk_attacks(pawn) : one_bpawn_bk_attacks(pawn),
					Us == WHITE ? 
					attacks_by_rpawn_rk(yk) : attacks_by_bpawn_bk(yk));
				if(m_have_bit(Bcheck)){
					// ��Ҫ�ж�һ��,1,Ҫ�����ڶԷ��Ľ�, ei.attPoint[WHITECOLOR] = MaCanCHeckPoint;
					//ei.kingAdjacentZoneAttacksCount[Us] ++;  // ���Խ�����?

					ei.attPoint[Us] += 6 * count_1s(Bcheck);

					if(bit_is_set(ei.attackKingCheCan[Us],pawn)){
						ei.attPoint[Us] += 3;   // ����һ����,Ҫ�ӷ�
					}
					//����Է��Ľ�����ԭλ,�緽ֻ��һ����û��
					if(Us == WHITE ? StoY(pawn) != 0x0 : StoY(pawn) != 0x9){						
						ei.cy[Us] ++;	
						if(ABS(StoX(pawn) - 0x4) <= 1){
							if(    (Us == WHITE ? pos.piece_on(pawn - 9) != BSHI : pos.piece_on(pawn + 9) != RSHI)
								|| yshi <= 1 
								|| (Us == WHITE ? yk != 0x4 : yk != 0x55)){
									ei.cy[Us]++;
							}
						}
					}
					ei.valu += Sign[Us] * pawnSafe;
				}
				else{ //2.��һ�±��ǲ��ǲ���ǰ����,
					if(Us == WHITE ? StoY(pawn) < StoY(yk) : StoY(pawn) > StoY(yk)){
					}
					else{ 
						if(have_bit(ei.SafeBit[Us],
							Us == WHITE ? RPawnGoodMove[pawn] : BPawnGoodMove[pawn])){
								ei.valu += Sign[Us] * pawnSafe;
						}	
					}
				}
			}
		}
	}
} // second eval