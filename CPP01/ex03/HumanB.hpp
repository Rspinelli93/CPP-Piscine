#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanB
{
	Weapon		*Weap;
	std::string	name;
	public:
		HumanB( std::string nameval );
		void attack( void );
		void setWeapon( Weapon& weapon );
};

#endif