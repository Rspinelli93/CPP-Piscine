#include "types.hpp"

/// @brief Function to get which kind of type the string represents
/// @param val The string to check
/// @return Enum myType value according to the type
nType 	getType( std::string val );

/// @brief Checks if the string is a char, edgecase ('z', ' ')
/// @param val String to check
/// @return True if its a char, False if not
bool	isChar( std::string val );

/// @brief Checks if the string is a int, edgecase (0)
/// @param val String to check
/// @return True if its a int, False if not
bool	isInt( std::string val );

/// @brief Checks if the string is a float, edgecase (0.0f)
/// @param val String to check
/// @return True if its a float, False if not
bool	isFloat( std::string val );

/// @brief Checks if the string is a double, edgecase (0.0)
/// @param val String to check
/// @return True if its a double, False if not
bool	isDouble( std::string val );

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
	
bool	isInvalid( std::string val )
{
	/*
	Empty string
	Multiple dots → 3.1.4
	Letters mixed in → 12abc
	Multiple signs → --3
	Sign with no digits → -
	Float without digits before/after dot → .f, 3.... (debatable)
	Overflow (too big for any type)
	*/
}
