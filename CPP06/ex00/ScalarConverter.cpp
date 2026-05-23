#include "ScalarConverter.hpp"

//---------- Orthodox cannonical -------------

ScalarConverter::ScalarConverter() { std::cout << "ScalarConverter: Constructor" << std::endl; }

ScalarConverter::ScalarConverter( const ScalarConverter &other ) { (void)other; std::cout << "ScalarConverter: Copy constructor" << std::endl; }

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &other ) { (void)other; return ( *this ); }

ScalarConverter::~ScalarConverter() { std::cout << "ScalarConverter: Destructor" << std::endl; }

//------------ Conversion ---------------

void ScalarConverter::convert( std::string val )
{
	int		n;
	char	c;
	float	f;
	double	d;

	std::stringstream convert(val);

	convert >> c;
	convert >> n;
	convert >> f;
	convert >> d;

	std::cout << "Char:" << c << std::endl;
	std::cout << "Int:" << n << std::endl;
	std::cout << "Float:" << f << std::endl;
	std::cout << "Double:" << d << std::endl;
}