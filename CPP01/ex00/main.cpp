#include "Zombie.hpp"

int	main( void )
{
	Zombie	*Morty = newZombie("Morty");

	if (Morty)
	{
		Morty->announce();
		std::cout << std::endl;
		destructor(Morty);
		std::cout << std::endl;
	}
	randomChump("Rick");
	std::cout << std::endl;

	return ( 0 );
}
