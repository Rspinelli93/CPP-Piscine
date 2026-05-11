#include "HumanB.hpp"

HumanB::HumanB( std::string name_val ) : Weap(NULL), name(name_val) { }

HumanB::~HumanB() { }

void	HumanB::attack( void )
{
	if (this->Weap) 
		std::cout << this->name << " attacks with their " << this->Weap->getType() << std::endl;
	else 
		std::cout << this->name << " has no weapon!" << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->Weap = &weapon;
}