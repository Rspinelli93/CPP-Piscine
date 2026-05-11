#include "Harl.hpp"

int	main( void )
{
	Harl Harlcito;

	std::cout << "DEBUG:" << std::endl;
	Harlcito.complain("debug");
	std::cout << "\nINFO:" << std::endl;
	Harlcito.complain("info");
	std::cout << "\nWARNING:" << std::endl;
	Harlcito.complain("warning");
	std::cout << "\nERROR:" << std::endl;
	Harlcito.complain("error");
}