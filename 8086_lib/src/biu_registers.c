/*	File name: exu_registers.c
Description: Handles the basic storage, input and output processing
for all 8086 registers
Abbreviation Notes: exu = Execution Unit
*/

#include "stdint.h"

#include "biu_pub_registers.h"

static uint16_t s_reg_array[ BIU_REG_16_COUNT ];

void BIU_16_bit_reg_init( void )
{
	memset( s_reg_array, 0x00, sizeof( s_reg_array[ BIU_REG_16_COUNT ] ) );
}

void BIU_16_bit_reg_set( BIU_reg_16_t8 reg, uint16_t val )
{
	if (reg < BIU_REG_16_COUNT)
	{
		/* set register to requested value */
		s_reg_array[ reg ] = val;
	}
}