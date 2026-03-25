#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie	*newZom;

	newZom = new (std::nothrow) Zombie;
	if (!newZom)
	{
		print_err_alloc();
		return ( NULL );
	}
	newZom->set_name(name);
	return ( newZom );
}

void	destructor( Zombie *zombie )
{
	zombie->print_name();
	std::cout << " Horde destroyed";
	delete[] zombie;
}

void	print_err_alloc(void)
{
	std::cout << "Err: Alloc" << std::endl;
}