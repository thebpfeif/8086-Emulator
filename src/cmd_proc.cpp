/* Command Processing */

/* INCLUDES */
#include "stdafx.h"
#include <string>

#include "stdio.h"
#include "stdbool.h"

#include "cmd_pub_list.h"
#include "cmd_pub_proc.h"
#include "eu_pub_registers.h"

/* PROCEDURES */
void help_output
(
	std::string * output
);

void dump_output
(
	std::string * output 
);

/* VARIBALES */
static const CMD_list_type cmd_list[] =
{
	{ CMD_HELP, "help", help_output },
	{ CMD_DUMP, "dump", dump_output }
};

void CMD_init()
{

}

bool CMD_process_input( std::string * input, std::string * output )
{
	bool valid; 

	valid = false; 
	//TODO: check to see if command is alpha or numeric 
	for ( int i = 0; i < CMD_COUNT; i++ )
	{
		if ( !input->compare( cmd_list[ i ].cmd_string ) )
		{
			/* call function pointer associated with it */
			( cmd_list[ i ].fptr( output ) );
			valid = true; 
			break; 
		}
	}

	return ( valid );
}

void help_output( std::string * output )
{
	output->append( "This is the help menu" );
}

void dump_output( std::string * output )
{
	uint16_t reg_val = 0; 
	/* retrieve register values and append to buffer */
	//reg_val = EU_16_bit_reg_get( EU_AX );
	output->append( "AX: 0x" + std::to_string( reg_val ) );
}

