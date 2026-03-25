#include "HumanA.hpp"

HumanA::HumanA( std::string name_val, Weapon& weapon )
	: name(name_val), Weap(weapon)
{
}

void	HumanA::attack( void )
{
	std::cout << name << " attacks with their " << Weap.getType() << std::endl;
}
