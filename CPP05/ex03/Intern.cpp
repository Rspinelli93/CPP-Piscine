#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//------------- Orthodox -------------

Intern::Intern() { std::cout << "Intern: Constructor" << std::endl; }

Intern::~Intern() { std::cout << "Intern: Destructor" << std::endl; }

Intern::Intern( Intern const &other ) { (void)other; std::cout << "Intern: Copy Cosntructor" << std::endl; }

Intern &Intern::operator=( Intern const &other )
{
	if (this != &other)
		(void)other;
	return ( *this );
}

//----------- Form creation -------------

AForm *makeForm( std::string fname, std::string target )
{
	
}