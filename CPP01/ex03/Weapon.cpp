#include "Weapon.hpp"

void	Weapon::setType( std::string value )
{
    this->type = value;
}

const std::string&	Weapon::getType( void ) const
{
	return (this->type);
}

Weapon::Weapon( std::string name ) : type(name) {}


Weapon::~Weapon( void ) { }