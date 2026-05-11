#include "Harl.hpp"

int	main( int ac, char **av )
{
	if (ac == 2)
	{
		Harl Harlcito;
		std::string input = av[1];
		Harlcito.complain(input);
		return (0);
	}
	std::cout << "Usage ./harlFilter + [COMMAND]" << std::endl;
	return (1);
}