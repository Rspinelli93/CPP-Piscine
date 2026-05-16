#include "Fixed.hpp"

// Use initializer list instead of inside { } (curly braces calles fist default consructor).
Fixed::Fixed( void ) : _fixed(0) { std::cout << "Default constructor called" << std::endl; } ;

Fixed::~Fixed( void ) { std::cout << "Destructor called" << std::endl; } ;

Fixed::Fixed( const Fixed &num ) 
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed = num._fixed;
};

Fixed &Fixed::operator=(const Fixed &num)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &num)
    	_fixed = num.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
}

//-------------------------
// Multiply or divide by 256 or bit shift 8 << to fixed or >> to go back to int or float.

Fixed::Fixed( const int num ) : _fixed(num * 256) { }

Fixed::Fixed( const float num ) : _fixed(roundf(num * 256)) { }

float Fixed::toFloat( void ) const
{
	float f = _fixed / 256.0f;
	return ( f );
}

int Fixed::toInt( void ) const
{
	int	i = _fixed >> 8;
	return ( i );
}

//Basically teaching the compiler what to do when it sees << with fixed num.
std::ostream &operator<<(std::ostream &out, const Fixed &num)
{
    out << num.toFloat();
    return out;
}
