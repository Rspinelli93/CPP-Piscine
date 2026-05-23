#ifndef TYPES_HPP
# define TYPES_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <limits.h>
#include <climits> 

enum nType
{
	INVALID =	1,
	CHAR =		2,
	INT =		3,
	FLOAT =		4,
	DOUBLE =	5,
	SPECIAL =	6
};

nType 	getType( std::string val );
bool	isInvalid( std::string val );
bool	isChar( std::string val );
bool	isInt( std::string val );
bool	isFloat( std::string val );
bool	isDouble( std::string val );
bool	isSpecial( std::string val );

#endif