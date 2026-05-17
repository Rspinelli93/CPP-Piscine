#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_dmg = 20;
	std::cout << this->_name << " - ScavTrap Default constructor called" << std::endl;
}

ScavTrap::~ScavTrap( void ) { std::cout << this->_name << " - ScavTrap Destructor called" << std::endl;}

ScavTrap::ScavTrap ( std::string name ) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_dmg = 20;
	std::cout << this->_name << " - ScavTrap Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << this->_name << " - ScavTrap Copy constructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hit_points < 1)
		std::cout << this->_name << " ScavTraps don't attack without hit points" << std::endl;
	else if (this->_energy_points < 1)
		std::cout << this->_name << " ScavTraps don't attack without energy points" << std::endl;
	else
	{
		this->_energy_points -= 1;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " dealing " << this->_attack_dmg << " points of damage! " << std::endl;
	}
}

void ScavTrap::guardGate( void )
{
	std::cout << this->_name << " ScavTrap is now in Gatekeeper mode!" <<std::endl;
}

