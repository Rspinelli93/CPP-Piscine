#include "Zombie.hpp"

int	main( void )
{
	int		N = 5;
	int		i = 0;
	Zombie	*Horde = zombieHorde(N, "Morty");

	if (Horde)
	{
		while (i < N)
		{
			std::cout << "Index " << i << ": ";
			Horde[i++].announce();
		}
		std::cout << "\nChanging names...\n" << std::endl;
		Horde[1].set_name("Summer");
		Horde[2].set_name("Rick");
		Horde[3].set_name("Jerry");
		Horde[4].set_name("Beth");
		i = 0;
		while (i < N)
		{
			std::cout << "Index " << i << ": ";
			Horde[i++].announce();
		}
		std::cout << "\n\n";
	}
	delete[] Horde;
	return ( 0 );
}
