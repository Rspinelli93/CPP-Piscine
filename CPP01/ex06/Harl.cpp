#include "Harl.hpp"

Harl::~Harl() {}

Harl::Harl() {}

void Harl::debug( void ) 
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
};

void Harl::info( void )
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
};

void Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n" << std::endl;
};
void Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
};

void Harl::complain( std::string level ) 
{	
	//+ Array of names
	std::string arrayS[5];
	arrayS[0] = "DEBUG";
	arrayS[1] = "INFO";
	arrayS[2] = "WARNING";
	arrayS[3] = "ERROR";
	arrayS[4] = "";

	//+ Search
	int caseNum = 5;
	for (int i = 0; arrayS[i].compare("") != 0; i++)
	{
		if (arrayS[i].compare(level) == 0)
		{
			caseNum = i;
			break ;
		}
	}

	//+ Switch
	switch (caseNum)
	{
		case (0): 
			this->debug();
			//fall through
		case (1): 
			this->info();
			//fall through
		case (2): 
			this->warning();
			//fall through
		case (3):
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
			break;
	}
};