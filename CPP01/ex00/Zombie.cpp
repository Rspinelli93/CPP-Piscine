#include "Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( std::string s_name )
{
	_name = s_name;
}

Zombie::~Zombie( void )
{
	std::cout << _name << " destroyed" << std::endl;
}