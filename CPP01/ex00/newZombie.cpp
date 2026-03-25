#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie	*newZom;

	newZom = new (std::nothrow) Zombie;
	if (!newZom)
	{
		std::cout << "Err: Alloc" << std::endl;
		return (NULL);
	}
	newZom->set_name(name);
	return ( newZom );
}

void	destructor( Zombie *zombie )
{
	zombie->print_name();
	std::cout << " destroyed";
	delete zombie;
}