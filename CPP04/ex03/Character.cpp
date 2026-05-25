#include "Character.hpp"

Character::Character() { std::cout << "Character: Default Constructor" << std::endl; }

Character::~Character() { std::cout << "Character: Destructor" << std::endl; }

Character::Character(std::string const &name) : _name(name) { std::cout << "Character: Param Constructor" << std::endl; }

Character::Character(Character const &other) : _name(other._name)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
}

Character &Character::operator=(Character const &other)
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            _inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
        }
    }
    return (*this);
}

std::string const &Character::getName() const { return ( this->_name ); }

void Character::equip(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3 || !_inventory[idx])
        return ;
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3 || !_inventory[idx])
        return ;
    _inventory[idx]->use(target);
}