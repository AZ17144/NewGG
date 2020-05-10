#ifndef stockfish_MY_CONFIG_H_123
#define stockfish_MY_CONFIG_H_123


#define HAVE_NONE_PAWN_MATERAIL      (1 << 0)   // �췽���㹻������
#define CK_CAN_USE_FRUIT_PUN         (1 << 1)   // �ӽ��к���ʱ������ģ���ü�
#define CK_BR_1CHE_4MAPAO            (1 << 2)   // ˫��1������4�����ڵ�����
#define CK_Only_1Che1PaoxPawn        (1 << 3)   // һ��ֻ��1��1��X��������
#define CK_5000_Material             (1 << 4)


#define SMG(mg,eg)     Score(((mg)<< 16)+(eg)) 
static const  Piece COLOR_BY_SIDE_ADD[2] = { EMPTY, _X_X };

typedef struct {
	sint16 a[6][6][3][3][3][3][3][3];  // BY LGL 20131124
}MARR_t;   // PreMatInfo[6][6][3][3][3][3][3][3]; �Ƚ�С��


#ifdef REPEAT_DEBUG

enum REPEAT_INFO {
	REPEAT_NO = 0,					    // û���ظ�
	REPEAT_TRUE = 1,				    // �������
	REPEAT_BAN_ME_CHECK = 2,		    // ���ӷ����˽���
	REPEAT_BAN_OTHER_CHECK = 3,         // ���ӷ����˽���
	REPEAT_BAN_ME_CAP = 4,				// ���ӷ����˽���
	REPEAT_BAN_OTHER_CAP = 5,		    // ���ӷ����˽���
};

#define CheckRepetition(sply) \
	switch (pos.is_repeat()){\
	case REPEAT_TRUE: \
	return(Value(0));   \
	case REPEAT_BAN_ME_CHECK: \
	return  value_baned_check_in(sply);   \
	case REPEAT_BAN_OTHER_CHECK: \
	return -value_baned_check_in(sply);   \
	case REPEAT_BAN_ME_CAP: \
	return  value_baned_cap_in(sply);   \
	case REPEAT_BAN_OTHER_CAP: \
	return -value_baned_cap_in(sply);   \
	default: \
	break; \
	};
#else
enum REPEAT_INFO {
	REPEAT_NO = 0,                      // û���ظ�
	REPEAT_TRUE = 1,                    // �������
	REPEAT_BAN_ME_CHECK = 2,		    // ���ӷ����˽���
	REPEAT_BAN_OTHER_CHECK = 3,         // ���ӷ����˽���
	REPEAT_BAN_ME_CAP = 4,				// ���ӷ����˽���
	REPEAT_BAN_OTHER_CAP = 5,		    // ���ӷ����˽���
};

#endif

#define CheckRepetition(sply) \
	switch (pos.is_repeat()){\
	case REPEAT_TRUE: \
	return(Value(0));   \
	case REPEAT_BAN_ME_CHECK: \
	return  value_baned_check_in(sply);   \
	case REPEAT_BAN_OTHER_CHECK: \
	return -value_baned_check_in(sply);   \
	case REPEAT_BAN_ME_CAP: \
	return  value_baned_cap_in(sply);   \
	case REPEAT_BAN_OTHER_CAP: \
	return -value_baned_cap_in(sply);   \
	default: \
	break; \
	};


#ifndef NDEBUG
#define ASSERT(_Expression) (void)( (!!(_Expression)) || ((_CRT_WIDE(#_Expression), _CRT_WIDE(__FILE__), __LINE__), 0) )
#else
#define ASSERT(_Expression)
#endif

#define typePOS Position

struct premat_t {
	sint16  material;		      // 1  ������	
	uint8   searchInfo8;          // 2. ����ֵļ��״̬	
	uint8   phase;                // 4. �о�״̬	
};


#endif


