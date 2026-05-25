#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	const Fixed d(24);
	const Fixed c(42);
	std::cout << Fixed::min(d, c) << std::endl;
	std::cout << Fixed::max(d, c) << std::endl;
	Fixed x(24);
	Fixed y(42);
	std::cout << Fixed::min(x, y) << std::endl;
	std::cout << Fixed::max(x, y) << std::endl;
	return 0;
}