#include <iostream>
#include <string>

int main(int ac, char *av[])
{
	if (ac == 3)
	{
		return (0);
	}
	std::cout << "Expected 2 agruments" << std::endl;
	std::cout << "Usage: ./sed_is_for_losers [word] [replacement]" << std::endl;
	return (1);
}
