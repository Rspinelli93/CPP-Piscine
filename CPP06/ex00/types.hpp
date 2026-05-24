#ifndef TYPES_HPP
# define TYPES_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <limits.h>
#include <climits> 
#include <cfloat>
#include <iomanip>
#include <cerrno>

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
bool    hasDot( std::string str );
bool    isChar( std::string val, char *end );
bool	isInt( std::string val, double num, char *end );
bool    isFloat( std::string val, char *end );
bool    isDouble( std::string val, char *end );
bool    isSpecial( std::string val );
bool    isInvalid( std::string val );

#endif