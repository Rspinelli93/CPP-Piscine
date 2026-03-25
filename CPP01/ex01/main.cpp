#include "Zombie.hpp"

int	main( void )
{
	int		N = 5;
	int		i = 0;
	Zombie	*Morty = zombieHorde(N, "Morty");

	if (Morty)
	{
		while (i < N)
		{
			std::cout << "Index " << i << ": ";
			Morty[i++].announce();
			std::cout << std::endl;
		}
		std::cout << "\nChanging names...\n" << std::endl;
		Morty[1].set_name("Summer");
		Morty[2].set_name("Rick");
		Morty[3].set_name("Jerry");
		Morty[4].set_name("Beth");
		i = 0;
		while (i < N)
		{
			std::cout << "Index " << i << ": ";
			Morty[i++].announce();
			std::cout << std::endl;
		}
		destructor(Morty);
		std::cout << std::endl;
		std::cout << std::endl;
	}
	return ( 0 );
}
