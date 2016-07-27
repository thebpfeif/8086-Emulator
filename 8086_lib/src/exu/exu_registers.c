/*	File name: exu_registers.c 
	Description: Handles the basic storage, input and output processing 
	for all 8086 registers 
	Abbreviation Notes: exu = Execution Unit
*/

#include "stdint.h"
#include "stdio.h"
#include "string.h"

#include "exu_pub_registers.h"


static uint16_t s_reg_array[ EXU_REG_16_COUNT ];

void EXU_16_bit_reg_init( void )
{
	memset( s_reg_array, 0x00, sizeof( s_reg_array[ EXU_REG_16_COUNT ] ) );
}

uint16_t EXU_16_bit_reg_get( EXU_reg_16_t8 reg )
{
	/* local variables */
	uint16_t reg_val; 
	
	if (reg < EXU_REG_16_COUNT)
	{
		/* retrieve register value */
		reg_val = s_reg_array[ reg ];
	}

	return( reg_val );
}

void EXU_16_bit_reg_set( EXU_reg_16_t8 reg, uint16_t val )
{
	if (reg < EXU_REG_16_COUNT)
	{
		/* set register to requested value */
		s_reg_array[ reg ] = val; 
	}
}

void EXU_8_bit_reg_set( EXU_reg_8_t8 reg, uint8_t val )
{
/* local variables */
uint16_t cur_data;
uint16_t new_data; 

/* copy val to 16-bit integer */
memset( &new_data, 0x00, sizeof( new_data ) );
new_data |= val; 

	if (reg < EXU_REG_8_COUNT)
	{
		cur_data = s_reg_array[ reg / 2 ];

		/* determine whether the register is a high or low byte */
		if ( ( reg % 2 ) == 0 ) /* low byte */
		{
			/* clear the lower byte and OR with val */
			cur_data = ( cur_data & 0xF0 ) | val; 
			s_reg_array[ reg / 2 ] = cur_data; 
		}
		else /* high byte */
		{
			cur_data = ( cur_data & 0x0F ) | ( val << 4 );
			s_reg_array[ reg / 2 ] = cur_data; 
		}
	}
}

