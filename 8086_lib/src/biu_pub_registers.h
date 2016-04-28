#pragma once

/* TYPES */
typedef uint8_t BIU_reg_16_t8;
enum
{
	BIU_CS,				/* code segment					*/
	BIU_DS,				/* data segment					*/
	BIU_SS,				/* stack segment				*/
	BIU_ES,				/* extra segment				*/
	BIU_IP,				/* instruction pointer			*/
	BIU_REG_16_COUNT	/* total biu 16-bit reg count	*/
};