#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") { std::cout << "Ice: Constructor" << std::endl; }

Ice *Ice::clone( void ) const
{
	Ice *New = new Ice;
	*New = *this;
	return (New);
}

void Ice::use(ICharacter& target) { std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" << std::endl; }
