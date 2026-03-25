#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie	*Horde;
	int		i = 0;
	
	Horde = new (std::nothrow) Zombie [N];
	if (!Horde)
	{
		print_err_alloc();
		return ( NULL );
	}
	while (i < N)
		Horde[i++].set_name(name);
	return ( Horde );
}
