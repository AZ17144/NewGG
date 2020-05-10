#if !defined(DIRECTION_H_INCLUDED)
#define DIRECTION_H_INCLUDED


////
//// Includes
////

#include "s_square.h"
#include "s_types.h"

////
//// Types
////

enum Direction {
	DIR_���� = 0, DIR_���� = 1, DIR_�� = 2, DIR_�� = 3, DIR_�� = 4, DIR_NONE = 5,
};

////
//// Variables
////

extern uint8 DirectionTable[90][90];
//extern uint8 SignedDirectionTable[90][90];

//ENABLE_OPERATORS_ON(SignedDirection);


////
//// Inline functions
////

inline Direction direction_between_squares(Square s1, Square s2) {
	return Direction(DirectionTable[s1][s2]);
}



////
//// Prototypes
////

extern void init_direction_table();


#endif