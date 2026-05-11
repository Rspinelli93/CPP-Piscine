#include "HumanA.hpp"

HumanA::HumanA( std::string name_val, Weapon& weapon ) : name(name_val), Weap(weapon) { }

HumanA::~HumanA() { }

void	HumanA::attack( void )
{
	std::cout << this->name << " attacks with their " << this->Weap.getType() << std::endl;
}
