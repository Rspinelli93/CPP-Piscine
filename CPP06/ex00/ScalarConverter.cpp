#include "ScalarConverter.hpp"

//---------- Orthodox cannonical -------------

ScalarConverter::ScalarConverter() { std::cout << "ScalarConverter: Constructor" << std::endl; }

ScalarConverter::ScalarConverter( const ScalarConverter &other ) { (void)other; std::cout << "ScalarConverter: Copy constructor" << std::endl; }

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &other ) { (void)other; return ( *this ); }

ScalarConverter::~ScalarConverter() { std::cout << "ScalarConverter: Destructor" << std::endl; }

//------------ Conversion ---------------

void    ScalarConverter::convert( std::string val )
{
    nType   type = getType(val);
    char    *end;
    double  num = strtod(val.c_str(), &end);

    switch (type)
    {
        case (INVALID):
            putInvalid(val);
            break;
        case CHAR:
            putValidChar(val[0]);  // handle separately
            break;
        case FLOAT:
        case DOUBLE:
        case INT:
            putValid(num, val);
            break;
        case (SPECIAL):
            putSpecial(val);
            break;
        default:
            break;
    }
}

void	putChar( double num )
{
	char c = static_cast<char>(num);
	if (!std::isprint(c))
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: " << c << std::endl;
}

void	putInt( double num )
{
	int i = static_cast<int>(num);

	if (num > INT_MAX || num < INT_MIN)
		std::cout << "Int: impossible" << std::endl;
	else
		std::cout << "Int: " << i << std::endl;
}

void	putDouble( double num, int decimal )
{
	if (num == (int)num)
		std::cout << "Double: " << std::fixed << std::setprecision(1) << num << std::endl;
	else
		std::cout << "Double: " << std::setprecision(decimal) << num << std::endl;
}

void	putFloat( double num, int decimal )
{
	float f = static_cast<float>(num);

	if (num > FLT_MAX || num < -FLT_MAX)
		std::cout << "Float: impossible" << std::endl;
	if (f == (int)f)
		std::cout << "Float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
	else
		std::cout << "Float: " << std::setprecision(decimal) << f << "f" << std::endl;
}

void	putValid( double num, std::string val )
{
	int decimal = decimalLen(val);
	putChar(num);
	putInt(num);
	putFloat(num, decimal);
	putDouble(num, decimal);
}

void    putValidChar( char c )
{
    std::cout << "Char: " << c << std::endl;
    std::cout << "Int: " << static_cast<int>(c) << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void    putSpecial( std::string val )
{
	std::string floatS = val;
	std::string doubS = val;

	if (floatS == "nan" || floatS == "+inf" || floatS == "-inf")
		floatS += "f";
	if (doubS == "nanf" || doubS == "+inff" || doubS == "-inff")
		doubS.erase(doubS.length() - 1);

	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: " << floatS << std::endl;
	std::cout << "Double: " << doubS << std::endl;
}

void	putInvalid( std::string val )
{
	std::cout << val << ": Invalid!" << std::endl;
}

/// @param val String with the valid number
/// @return Returns the amount of decimal numbers needed to print
int		decimalLen( std::string val )
{
	size_t dot = val.find(".");
	if (dot != std::string::npos)
	{
		size_t decimals = val.length() - dot - 1;
		// remove 'f' from count case
		if (val[val.length() - 1] == 'f')
			decimals--;
		return ( (int)decimals );
	}
	return (1);
}