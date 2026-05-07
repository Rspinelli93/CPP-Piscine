#include "HumanB.hpp"

HumanB::HumanB( std::string name_val ) : Weap(NULL), name(name_val) { }

HumanB::~HumanB() { }

void	HumanB::attack( void )
{
	if (Weap) 
		std::cout << name << " attacks with their " << Weap->getType() << std::endl;
	else 
		std::cout << name << " has no weapon!" << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	Weap = &weapon;
}