#include "Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( void ) { };

Zombie::~Zombie( void )
{
	std::cout << _name << " destroyed" << std::endl;
}

void	Zombie::set_name( std::string new_name )
{
	_name = new_name;
}
