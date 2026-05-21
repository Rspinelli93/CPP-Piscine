#include "Character.hpp"

Character::Character() { std::cout << "Character: Default Constructor" << std::endl; }

Character::~Character() { std::cout << "Character: Destructor" << std::endl; }

Character::Character(std::string const &name) : _name(name) { std::cout << "Character: Param Constructor" << std::endl; }

Character::Character(Character const &other) : _name(other._name) { std::cout << "Character: Copy Constructor" << std::endl; }

Character &Character::operator=(Character const &other)
{
	if (this != &other)
	{
		this->_name = other._name;
	}
	return (*this);
}

std::string const &Character::getName() const { return ( this->_name ); }

void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{
	
}
