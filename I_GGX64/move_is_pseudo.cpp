#include "chess.h"

#ifdef USE_STOCK_FISH_FILE
#else
 
#include "preGen.h"

//���е��߲��ǲ��ǿ�����
bool move_is_pseudo(int move, typePOS *POSITION) {

	int from  = FROM(move);
	int to    = TO(move);
	int piece = PB90(from);
	int cap   = PB90(to);

	if(PIECE_SIDE(piece) != POS_SIDE){  // �����Ϊ�෴,����Ҫ����.
		return FALSE;
	}

	if(PIECE_SIDE(piece) == PIECE_SIDE(cap)){
		return FALSE;
	}

	//Bitboard att;

	switch(piece){
		case RMA:
		case BMA:{
			//�õ���������߲�			
			return (bit_is_set(king_to_ma_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
				 }
			break;
		case RXIANG:
		case BXIANG:{
			return (bit_is_set(xiang_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
					}
			break;
		case BSHI:
		case RSHI:			{
			return (bit_is_set(shi_attacks(to),from) !=0);
				  }
			break;
		case RCHE:
		case BCHE:{ //�����������
			return (bit_is_set(rook_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
				  }
			break;
		case RPAO:
		case BPAO:{//������
			if(cap == EMPTY){
				return (bit_is_set(rook_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
			}
			else{
				return (bit_is_set(pao_eat_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
			}
				  }
			break;
		case RPAWN:{
			return (bit_is_set(attacks_by_rpawn_rk(to),from) !=0);
				   }
			break;
		case BPAWN:{
			return (bit_is_set(attacks_by_bpawn_bk(to),from) !=0);
				   }
			break;
		case RKING:{
			return (bit_is_set(attacks_by_rpawn_rk(to),from) !=0);
				   }
			break;
		case BKING:{
			return (bit_is_set(attacks_by_bpawn_bk(to),from) !=0);
				   }
			break;
		default:
			return FALSE;
	}


	//return FALSE;
}

  //switch(piece){
  //case my_ma: //�õ���������߲�		  		
	 // return (bit_is_set(king_to_ma_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
  //case my_xiang:
	 // return (bit_is_set(xiang_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
  //case my_shi:
	 // return (bit_is_set(shi_attacks(to),from) !=0);
  //case my_che: //�����������
	 // return (bit_is_set(rook_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
  //case my_pao://������
	 // if(capture == EMPTY){
		//  return (bit_is_set(rook_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
	 // }
	 // else{
		//  return (bit_is_set(pao_eat_attacks_bb(to,POSITION->byWhiteBlack),from) !=0);
	 // }
  //case my_pawn:
  //case my_king:	
	 // return (bit_is_set(my_pawn_k_attacks(to),from) !=0);
  //default:
	 // return FALSE;
  //}

#endif