#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap 
{ 
	private:
		std::string		_name;
	public:
		DiamondTrap( void );
		~DiamondTrap( void );
		DiamondTrap( std::string name );
		void attack(const std::string& target);
		void whoAmI( void );
		void showStats( void );
};

#endif