#include "ScavTrap.hpp"

int main( void )
{
	std::cout << "\nTEST OTRHODOX CANNONICAL FORM\n--------------" << std::endl;
	ScavTrap Morty("Morty");	// parameterized
	ScavTrap Morty2(Morty);		// copy constructor
	ScavTrap Morty3;			// default constructor

	std::cout << "\nSIMPLE TESTS\n--------------" << std::endl;
	Morty.attack("Summer");
	Morty.takeDamage(5);
	Morty.beRepaired(3);
	Morty.guardGate();

	std::cout << "\nDEAD MORTY CAN'T DO ANYTHING\n-----------------" << std::endl;
	Morty.takeDamage(1000);
	Morty.attack("Summer");
	Morty.beRepaired(3);

	std::cout << "\nDESTRUCTORS\n-----------" << std::endl;
}