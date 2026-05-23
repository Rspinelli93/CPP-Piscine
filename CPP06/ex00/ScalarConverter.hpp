#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter( const ScalarConverter &other );
		ScalarConverter &operator=( const ScalarConverter &other );
	public:
		virtual ~ScalarConverter();
		static void convert( std::string val );
};

/*
nan, nanf
+inf, -inf
+inff, -inff

Invalid cases:

Empty string
Multiple dots → 3.1.4
Letters mixed in → 12abc
Multiple signs → --3
Sign with no digits → -
Float without digits before/after dot → .f, 3.... (debatable)
Overflow (too big for any type)

Edge cases that ARE valid:

0 → int
0.0 → double
0.0f → float
' ' → char (space, displayable)
'z' → char
*/
#endif