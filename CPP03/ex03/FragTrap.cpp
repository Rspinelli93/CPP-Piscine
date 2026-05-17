#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_dmg = 30;
	std::cout << this->_name << " - FragTrap Default constructor called" << std::endl;
}

FragTrap::~FragTrap( void ) { std::cout << this->_name << " - FragTrap Destructor called" << std::endl;}

FragTrap::FragTrap ( std::string name ) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_dmg = 30;
	std::cout << this->_name << " - FragTrap Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << this->_name << " - FragTrap Copy constructor called" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << this->_name << ": HEY!! HIGH FIVE!!" <<std::endl;
}

