/*	File name: cmd_proc.c
Description: Processes console commands 
entered by the user
Version: 0.10
*/

/* INCLUDES */
#include "stdafx.h"
#include <string>

#include "stdio.h"
#include "stdbool.h"

#include "cmd_pub_list.h"
#include "cmd_pub_proc.h"

#ifdef __cplusplus
extern "C"
{
#endif 

#include "eu_pub_registers.h"

#ifdef __cplusplus
}
#endif 

/* PROCEDURES */
void help_output
(
	std::string * output
);

void dump_output
(
	std::string * output 
);

/* TYPES */
class command_list
{
public: 
	CMD_id id;								/* command ID				*/
	std::string text_input;					/* user input text			*/
	std::string text_output;				/* console output text		*/
	void( *fptr )( std::string* );			/* output function pointer  */
};

/* VARIBALES */
static const command_list s_cmd_list[] =
{
	{ CMD_HELP, "help", "", help_output },
	{ CMD_DUMP, "dump", "", dump_output }
};

/* PROCEDURES */
bool command::input_process( std::string &input, std::string &output )
{
	bool valid; 
	CMD_id id; 
	valid = false; 

	id = command::parse( input );
	//TODO: check to see if command is alpha or numeric 
	/* call function pointer associated with it */
	//( cmd_list[ i ].fptr( &output ) );
	return ( valid );
}

CMD_id command::parse( std::string & input )
{
	CMD_id id = CMD_INVALID; 

	for ( int i = 0; i < CMD_COUNT; i++ )
	{
		if ( !input.compare( s_cmd_list[ i ].text_input ) )
		{
			id = s_cmd_list[ i ].id;
			break;
		}
	}

	return id;
}

void command::output_get( CMD_id id, std::string &output )
{
	if ( s_cmd_list[ id ].text_output.empty( ) )
	{
		/* Call associated function */
	}

	output = s_cmd_list[ id ].text_output;
}

void help_output( std::string * output )
{
	output->append( "This is the help menu" );
}

void dump_output( std::string * output )
{
	uint16_t reg_val = 0; 
	/* retrieve register values and append to buffer */
	reg_val = EU_16_bit_reg_get( EU_AX );
	output->append( "AX: 0x" + std::to_string( reg_val ) );
}

