#ifndef CLAPTRAP_CPP
# define CLAPTRAP_CPP

# include <iostream>

class ClapTrap
{
	private:
		std::string _name;
		int	_hit_points; //10
		int	_energy_points; //10
		int	_attack_dmg; //0
	public:
		ClapTrap( void );
		~ClapTrap( void );
		ClapTrap ( std::string name );
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif