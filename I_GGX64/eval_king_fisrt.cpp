#include "eval_total.h"


////////////////////////////////////////////////////////////////////////////
///// ��һ������˫���Ľ�. ������������,��,����. 
//template<Color Us>
//void evaluate_king_first(Position& pos, EvalInfo& ei){
//
//	//const Color Them = (Us == WHITE ? BLACK : WHITE);
//	const Piece delt = COLOR_BY_SIDE_ADD[Us];
//	Bitboard     occ = pos.occupied_squares();
//	const Square mk  = pos.king_square(Us);
//	//const Square yk  = pos.king_square(Them);
//	//Score bonus = SCORE_ZERO;
//	//////////////////////////////////////////////////////////////////////////
//	/// �Է����ܽ�����λ����
//	///
//	ei.attackedBy[RKING + delt] 
//	= (Us == WHITE ? one_rpawn_rk_attacks(mk) : one_bpawn_bk_attacks(mk));
//
//	//// ���ü������Ĺ�������
//	// ei.attackedBy[delt] = ei.attackedBy[RKING + delt];  // Us 
//	ei.attackedBy[delt] = m_or(ei.attackedBy[delt],ei.attackedBy[RKING + delt]);  // Us 
//
//	ei.attackKingCheCan[Us] = pos.Rook_attacks_bb(mk);
//	ei.attackKingMaCan[Us]  = king_to_ma_attacks_bb(mk,occ);
//	ei.attackKingPaoCan[Us] = pos.Pao_Eat_bb(mk);
//
//	//return bonus;
//}



