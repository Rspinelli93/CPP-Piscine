#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "types.hpp"

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

void	putChar( double num );
void	putInt( double num );
void	putDouble( double num, int decimal );
void	putFloat( double num, int decimal );
void	putValid( double num, std::string val );
void	putSpecial( std::string val );
void	putInvalid( std::string val );
int		decimalLen( std::string val );
void    putValidChar( char c );

#endif