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

std::ostream &operator<<(std::ostream &out, const Fixed &num)
{
    out << num.toFloat();
    return out;
}

//-------------------------

bool Fixed::operator>(const Fixed &num) const { return this->_fixed > num._fixed; }

bool Fixed::operator<(const Fixed &num) const { return this->_fixed < num._fixed; }

bool Fixed::operator>=(const Fixed &num) const { return this->_fixed >= num._fixed; }

bool Fixed::operator<=(const Fixed &num) const { return this->_fixed <= num._fixed; }

bool Fixed::operator==(const Fixed &num) const { return this->_fixed == num._fixed; }

bool Fixed::operator!=(const Fixed &num) const { return this->_fixed != num._fixed; }

//Math (Cant use raw value, because thy are already shifted.)
Fixed Fixed::operator+(const Fixed &num) const
{
	Fixed result;
	result.setRawBits(_fixed + num._fixed);
	return result;
}
Fixed Fixed::operator-(const Fixed &num) const
{
	Fixed result;
	result.setRawBits(_fixed - num._fixed);
	return result;
}
Fixed Fixed::operator*(const Fixed &num) const
{
	Fixed result;
	result.setRawBits((_fixed * num._fixed) >> 8);
	return result;
}
Fixed Fixed::operator/(const Fixed &num) const
{
	Fixed result;
	result.setRawBits((_fixed << 8) / num._fixed);
	return result;
}
//

Fixed &Fixed::operator++( void ) 
{
	this->_fixed += 1;
	return ( *this );
}

Fixed Fixed::operator++( int ) 
{
	Fixed ret(*this);
	this->_fixed += 1;
	return ( ret );
}

Fixed &Fixed::operator--( void ) 
{
	this->_fixed -= 1;
	return ( *this );
}

Fixed Fixed::operator--( int ) 
{
	Fixed ret(*this);
	this->_fixed -= 1;
	return ( ret );
}

const Fixed &Fixed::min( const Fixed &a, const Fixed &b )
{
	if (a._fixed < b._fixed)
		return ( a );
	return ( b );
}

Fixed &Fixed::min( Fixed &a, Fixed &b )
{
	if (a._fixed < b._fixed)
		return ( a );
	return ( b );
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b )
{
	if (a._fixed > b._fixed)
		return ( a );
	return ( b );
}

Fixed &Fixed::max( Fixed &a, Fixed &b )
{
	if (a._fixed > b._fixed)
		return ( a );
	return ( b );
}