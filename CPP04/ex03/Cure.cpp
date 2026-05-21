#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") { std::cout << "Cure: Constructor" << std::endl; }

Cure *Cure::clone( void ) const
{
	Cure *New = new Cure;
	*New = *this;
	return (New);
}

void Cure::use(ICharacter& target) { std::cout <<  "* heals " << target.getName() << "'s wounds *" << std::endl; }
