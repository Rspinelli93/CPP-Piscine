#include "Harl.hpp"

Harl::~Harl() {}

Harl::Harl() {}

void Harl::debug( void ) 
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
};

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
};

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
};
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
};

void Harl::complain( std::string level ) 
{	
	//+ Array of names
	std::string arrayS[5];
	arrayS[0] = "debug";
	arrayS[1] = "info";
	arrayS[2] = "warning";
	arrayS[3] = "error";
	arrayS[4] = "";

	//+ Array of functions
	void (Harl::* arrayF [5])();
	arrayF[0] = &Harl::debug;
	arrayF[1] = &Harl::info;
	arrayF[2] = &Harl::warning;
	arrayF[3] = &Harl::error;
	arrayF[4] = NULL;

	//+ Search
	for (int i = 0; arrayS[i].compare("") != 0; i++)
	{
		if (arrayS[i].compare(level) == 0)
			(this->*arrayF[i])();
	}
};