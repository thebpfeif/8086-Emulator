#pragma once

typedef uint8_t CMD_id;
enum 
{
	CMD_HELP,
	CMD_DUMP, 
	CMD_COUNT
};

typedef struct
{
	CMD_id  cmd_id;							/* input command			*/
	std::string cmd_string;					/* command string			*/
	void (*fptr)( std::string* );			/* output function pointer  */
} CMD_list_type;
