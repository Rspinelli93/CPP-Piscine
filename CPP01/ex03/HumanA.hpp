#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanA
{
	std::string	name;
	Weapon		&Weap;
	public:
		HumanA( std::string nameval, Weapon& weapon );
		void attack( void );
};

#endif