#pragma once

#include <string>

#include "cmd_pub_list.h"

class command
{
public:
	bool input_process( std::string &input, std::string &output );
private:
	CMD_id parse( std::string &input );
	void output_get( CMD_id id, std::string &output );
};