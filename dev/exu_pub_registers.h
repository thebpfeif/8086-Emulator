#pragma once

/* TYPES */
typedef uint8_t EXU_reg_16_t8;
enum
{
	EXU_AX,				/* accumulator					*/
	EXU_BX,				/* base addressing				*/
	EXU_CX,				/* counter loop					*/
	EXU_DX,				/* data pointer					*/
	EXU_DI,				/* destination index			*/
	EXU_SI,				/* source index					*/
	EXU_SP,				/* stack pointer				*/
	EXU_BP,				/* base pointer					*/
	EXU_REG_16_COUNT	/* total exu 16-bit reg count	*/
};

typedef uint8_t EXU_reg_8_t8; 
enum
{
	EXU_AH,		/* high-byte accumulator			*/
	EXU_AL,		/* low-byte accumulator				*/
	EXU_BH,		/* high-byte base addresser			*/
	EXU_BL,		/* low-byte base addresser			*/
	EXU_CH,		/* high-byte looper counter			*/
	EXU_CL,		/* low-byte looper counter			*/
	EXU_DH,		/* high-byte data pointer			*/
	EXU_DL,		/* low-byte data pointer			*/
	EXU_REG_8_COUNT /* total exu 8-bit reg count	*/
};

/* PROCEDURES */

void EXU_16_bit_reg_set ( EXU_reg_16_t8 reg, uint16_t val );
void EXU_8_bit_reg_set( EXU_reg_8_t8 reg, uint8_t val );
