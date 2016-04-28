
/* TYPES */

typedef uint8_t EXU_flag_reg_t8;
enum
{
	EXU_CF,					/* carry flag			*/
	EXU_U_1,				/* undefined			*/
	EXU_PF,					/* parity flag			*/
	EXU_U_2,				/* undefined			*/					
	EXU_AF,					/* auxiliary carry flag */
	EXU_U_3,				/* undefined			*/			 
	EXU_ZF,					/* zero flag			*/
	EXU_SF,					/* sign flag			*/
	EXU_TF,					/* trap flag			*/ 
	EXU_IF,					/* interrupt flag		*/	
	EXU_DF,					/* direction flag		*/
	EXU_OF,					/* overflow flag		*/
	EXU_RSRV_1,				/* reserved				*/
	EXU_RSRV_2,				/* reserved				*/
	EXU_RSRV_3,				/* reserved				*/
	EXU_RSRV_4,				/* reserved				*/
	EXU_FLAG_REG_COUNT, 
};