#include "Weapon.hpp"

void	Weapon::setType( std::string value )
{
    type = value;
}

const std::string&	Weapon::getType( void ) const
{
	return (this->type);
}

Weapon::Weapon( std::string name )
{
	setType(name);
}
