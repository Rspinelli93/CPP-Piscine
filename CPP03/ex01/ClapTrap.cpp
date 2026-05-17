#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ): _hit_points(10), _energy_points(10), _attack_dmg(0) 
{
	std::cout << this->_name << " - Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void ) { std::cout << this->_name << " - Destructor called" << std::endl;}

ClapTrap::ClapTrap ( std::string name ): _name(name), _hit_points(10), _energy_points(10), _attack_dmg(0) 
{
	std::cout << this->_name << " - Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hit_points(other._hit_points), _energy_points(other._energy_points), _attack_dmg(other._attack_dmg)
{
	std::cout << this->_name << " - Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_attack_dmg = other._attack_dmg;
		this->_energy_points = other._energy_points;
		this->_hit_points = other._hit_points;
		this->_name = other._name;
	}
	std::cout << this->_name << " - Copy assingment operator called" << std::endl;
	return ( *this );
}

// --------------------

void ClapTrap::attack(const std::string& target)
{
	if (this->_hit_points < 1)
		std::cout << this->_name << " can't attack, he has no hit points" << std::endl;
	else if (this->_energy_points < 1)
		std::cout << this->_name << " can't attack, he has no energy points" << std::endl;
	else
	{
		this->_energy_points -= 1;
		std::cout << this->_name << " attacks " << target << " causing " << this->_attack_dmg << " points of damage! " << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_points -= amount;
	std::cout << this->_name << " took " << amount << " damage!" << std::endl;
	if (this->_hit_points < 0)
		this->_hit_points = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points < 1)
		std::cout << this->_name << " can't repair himself, he has no hit points" << std::endl;
	else if (this->_energy_points < 1)
		std::cout << this->_name << " can't repair himself, he has no energy points" << std::endl;
	else
	{
		this->_energy_points -= 1;
		this->_hit_points += amount;
		std::cout << this->_name << " healed " << amount << " hit points" << std::endl;
	}
}
