#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class	Weapon
{
	std::string	type;
	public:
		const std::string &getType( void ) const;
		void setType( std::string value );
		Weapon( std::string name );
};

#endif