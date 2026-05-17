#include "DiamondTrap.hpp"

int main( void )
{
	std::cout << "\nCREATING ROBOT...\n--------------" << std::endl;
	DiamondTrap Morty("Morty");

	Morty.showStats();

	std::cout << "\nSIMPLE TESTS\n--------------" << std::endl;
	Morty.attack("Summer");
	Morty.takeDamage(30);
	Morty.beRepaired(3);
	Morty.highFivesGuys();
	Morty.guardGate();
	Morty.whoAmI();

	std::cout << "\nDEAD MORTY CAN'T DO ANYTHING\n-----------------" << std::endl;
	Morty.takeDamage(1000);
	Morty.attack("Summer");
	Morty.beRepaired(3);

	std::cout << "\nDESTRUCTORS\n-----------" << std::endl;
}