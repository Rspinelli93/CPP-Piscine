#ifndef CLAPTRAP_CPP
# define CLAPTRAP_CPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string _name;
		int	_hit_points; //10
		int	_energy_points; //10
		int	_attack_dmg; //0
	public:
		ClapTrap( void ); // Default constructor
		~ClapTrap( void ); // Destructor
		ClapTrap ( std::string name ); // Parameterized constructor
		ClapTrap(const ClapTrap &other); // Copy constructor
		ClapTrap &operator=(const ClapTrap &other); //Copy assingment operator

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif