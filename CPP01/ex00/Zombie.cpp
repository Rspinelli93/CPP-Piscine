#include "Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...";
}

void    Zombie::set_name( std::string s_name )
{
    name = s_name;
}

void    Zombie::print_name( void )
{
    std::cout << name;
}
