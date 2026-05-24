#include "types.hpp"

/// @brief Function to get which kind of type the string represents
/// @param val The string to check
/// @return Enum myType value according to the type
nType 	getType( std::string val )
{
	if (isSpecial(val))
		return (SPECIAL);
	if (isInvalid(val))
		return (INVALID);

	//strtod splits the first part into a number and second into a c_string.
	char	*end;
    double	num;
	num = strtod(val.c_str(), &end);

	if (isFloat(val, end))
		return (FLOAT);
	if (isDouble(val, end))
		return (DOUBLE);
	if (isInt(val, num, end))
		return (INT);
	if (isChar(val, end))
		return (CHAR);
	return (INVALID);
}

/// @brief Checks if the string is a char, edgecase ('z', ' ')
/// @param val String to check
/// @return True if its a char, False if not
bool	isChar( std::string val, char *end )
{
	if (val.length() == 1 && std::isprint(end[0]))
		return ( true );
	return ( false );
}

/// @brief Checks if the string is a int, edgecase (0)
/// @param val String to check
/// @return True if its a int, False if not
bool	isInt( std::string val, double num, char *end )
{
	if (num > INT_MAX || num < INT_MIN)
		return ( false );
	if (!hasDot(val) && end[0] == '\0')
		return ( true );
	return ( false );
}

/// @brief Checks if the string is a float, edgecase (0.0f)
/// @param val String to check
/// @return True if its a float, False if not
bool	isFloat( std::string val, char *end )
{
	if (end && !strncmp("f", end, 2) && hasDot(val))
		return ( true );
	return ( false );
}

/// @brief Checks if the string is a double, edgecase (0.0)
/// @param val String to check
/// @return True if its a double, False if not
bool	isDouble( std::string val, char *end )
{
	if (hasDot(val) && end[0] == '\0')
		return ( true );
	return ( false );
}

/// @brief Check special cases (nan, nanf, +inf, -inf, +inff, -inff)
/// @param val String to check
/// @return True if any special case is valid, False if not special
bool	isSpecial( std::string val )
{
	if (val == "nan" || val == "nanf" || val == "+inf" 
		|| val == "-inf" || val == "+inff" || val == "-inff")
		return ( true );
	return ( false );
}

/*
- EDGE CASES
Empty string
Multiple dots → 3.1.4	
Letters mixed in → 12abc
Multiple signs → --3
Sign with no digits → -	
Float without digits before/after dot → .f, 3.... (debatable) 
Overflow (too big for any type) */
bool	isInvalid( std::string val )
{
	char	*end;
    double	num;
	errno = 0;

	// Empty string case
	if (val == "")
		return ( true );
	num = strtod(val.c_str(), &end);
	// Double overflow case
	if (errno == ERANGE)
		return ( true );
	// Floar overflow case
	if (num > FLT_MAX || num < -FLT_MAX)
		return ( true );
	// Other than f at the end or multiple dots case
	if (end[0] != '\0' && strncmp(end, "f", 2))
		return ( true );
	return ( false );
}

/// @brief Checks if the string contains a dot
/// @param str The string to check
/// @return If the string contains a dot and its not in the first position, it returns true. Multiple dots are handle by isInvalid()
bool	hasDot( std::string str )
{
	size_t found = str.find(".");
	if (found == 0 || found == std::string::npos)
		return ( false );
	return ( true );
}
