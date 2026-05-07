#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	private:
		std::string _name;
	public:
		Zombie( std::string s_name );
		~Zombie();
		void announce( void );
};

Zombie*	newZombie( std::string s_name );
void	randomChump( std::string s_name );

#endif