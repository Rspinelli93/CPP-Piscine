#include "Zombie.hpp"

int	main( void )
{
	Zombie	*Morty = newZombie("Morty");

	if (Morty)
	{
		Morty->announce();
		delete(Morty);
	}
	randomChump("Rick");
	return ( 0 );
}
