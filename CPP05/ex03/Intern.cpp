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

static AForm *makeShrubbery(const std::string &target) { return ( new ShrubberyCreationForm(target) ); }
static AForm *makeRobotomy(const std::string &target)  { return ( new RobotomyRequestForm(target) ); }
static AForm *makePresidential(const std::string &target) { return ( new PresidentialPardonForm(target) ); }

AForm *Intern::makeForm(const std::string &fname, const std::string &target) const 
{
	const std::string arrayS[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(*arrayF[3])(const std::string &) = {
		makeShrubbery,
		makeRobotomy,
		makePresidential
	};

	for (int i = 0; i < 3; i++) 
	{
		if (arrayS[i] == fname) {
			std::cout << "Intern creates " << fname << std::endl;
			return arrayF[i](target);
		}
	}
	std::cerr << "Error: form '" << fname << "' does not exist" << std::endl;
	return ( NULL );
}