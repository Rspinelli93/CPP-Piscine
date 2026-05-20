#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice"), _name("ice") { std::cout << "Ice: Constructor" << std::endl; }

Ice *Ice::clone( void ) const
{
	Ice *New = new Ice;
	*New = *this;
	return (New);
}

std::string Ice::getName( void ) const { return ( this->_name ); }

void Ice::setName( std::string const name ) { this->_name = name; }

