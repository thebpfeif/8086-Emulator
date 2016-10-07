// 8086e Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdbool.h"
#include <iostream>
#include <string>
#include <sstream>

#include "cmd_pub_proc.h"


int main()
{
	using namespace std; 

	command cmd;	/* command object declaration */
	bool new_line;
	bool valid; 
	string input; 
	string output;

	new_line = true; 
	valid = false; 
	cout << "8086e v0.01\nBy Brandon Pfeifer\n";
	cout << ">";

	while ( 1 )
	{
		while ( input.empty() )
		{
		getline( cin, input );
		}
		
		valid = cmd.input_process( input, output );

		if ( valid )
		{
			cout << output;
			cout << '\n';
		}

		input.clear(); 
		cout << ">";
	}
    return 0;
}



