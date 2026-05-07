#include "Zombie.hpp"

//+ std::bad_alloc — from <new>, thrown when new fails
//+ .what() — from <exception>, returns error message as const char*

//+ try — block that might throw an error
//+ catch — block that handles the error if thrown
Zombie	*newZombie( std::string name )
{
	Zombie	*newZom;

	try
	{
		newZom = new Zombie(name);
	}
	catch (std::bad_alloc &err)
	{
		std::cout << "Err: " << err.what() << std::endl;
		return (NULL);
	}
	return (newZom);
}