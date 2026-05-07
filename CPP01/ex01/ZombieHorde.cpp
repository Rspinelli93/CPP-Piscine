#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;
	int i = 0;

	try
	{
		horde = new Zombie[N];
	}
	catch (std::bad_alloc &err)
	{
		std::cout << "Err: " << err.what() << std::endl;
		return (NULL);
	}
	while (i < N)
		horde[i++].set_name(name);
	return (horde);
}
