#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon		*Weap;
		std::string	name;
	public:
		HumanB( std::string nameval );
		~HumanB();
		void attack( void );
		void setWeapon( Weapon& weapon );
};

#endif