




//#define  USE_VP_PROTECT                          // ʹ��VMP ����


#ifdef NDEBUG    
#define  VIP_USE_INFO                               // 
#endif

#ifdef USE_VP_PROTECT  

#else
#define CAN_OUT_EVAL_INFO
#endif



#ifdef USE_VP_PROTECT                                 // ʹ��VMP����
#define CYCLONE_SUB_DEPTH  0
#define CYCLONE_MUL_NPS    2
#else
#define CYCLONE_SUB_DEPTH  0
#define CYCLONE_MUL_NPS    1 



#endif