#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	this->_name = "default";
	ClapTrap::_name = "default_clap_name";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_dmg = FragTrap::_attack_dmg;
	std::cout << this->_name << " - FragTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name )
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_dmg = FragTrap::_attack_dmg;
	std::cout << this->_name << " - FragTrap Parameterized constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) { std::cout << this->_name << " - DiamondTrap Destructor called" << std::endl; }

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void )
{
	std::cout << "My Diamond name is " << this->_name << std::endl;
	std::cout << "My Clap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::showStats( void )
{
	std::cout << "\nPRINTING STATS...\nSTATS: <" << this->_name << ">" << std::endl;
	std::cout << "Hit points: " << this->_hit_points << std::endl;
	std::cout << "Energy points: " << this->_energy_points << std::endl;
	std::cout << "Attack: " << this->_attack_dmg << std::endl;
}
