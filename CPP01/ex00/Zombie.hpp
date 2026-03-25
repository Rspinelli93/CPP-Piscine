#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	std::string name;
	public:
		void announce( void );
		void set_name( std::string s_name );
		void print_name( void );
};

Zombie*	newZombie( std::string name );
void	destructor( Zombie *zombie );
void	randomChump( std::string name );

#endif