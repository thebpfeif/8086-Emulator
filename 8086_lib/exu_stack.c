/*	File name: exu_stack.c
Description: Handles the pushing and popping commands on the stack
and maintains the stack pointer 
Abbreviation Notes: exu = Execution Unit
*/

#include "stdint.h"

#include "exu_pub_registers.h"
#include "biu_pub_registers.h"

void EXU_stack_init( void )
{
/*local variables */
	uint16_t stack_seg; 

/* initialize the stack pointer 
   to the start of the stack segment */
	stack_seg = BIU_reg_get( BIU_SS );
	EXU_16_reg_set( EXU_SP, stack_seg );
}

void EXU_stack_push( uint16_t data )
{

}

uint16_t EXU_stack_pop( void )
{

}

