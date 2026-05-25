#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
	std::cout << "\033[32m" << "Test 1: Robotmy\n------------" << "\033[0m" << std::endl;
	{
		Intern Intern;
		AForm *randomForm;
		randomForm = Intern.makeForm("robotomy request", "Bender");
		if (randomForm)
			delete(randomForm);
	}
	std::cout << "\033[32m" << "\n\nTest 2: Shruberry\n------------" << "\033[0m" << std::endl;
	{
		Intern Intern;
		AForm *randomForm;
		randomForm = Intern.makeForm("shrubbery creation", "Bender");
		if (randomForm)
			delete(randomForm);
	}
	std::cout << "\033[32m" << "\n\nTest 3: Presidential\n------------" << "\033[0m" << std::endl;
	{
		Intern Intern;
		AForm *randomForm;
		randomForm = Intern.makeForm("presidential pardon", "Bender");
		if (randomForm)
			delete(randomForm);
	}
	std::cout << "\033[32m" << "\n\nTest 4: Wrong Form\n------------" << "\033[0m" << std::endl;
	{
		Intern Intern;
		AForm *randomForm;
		randomForm = Intern.makeForm("wrong name", "Bender");
		if (randomForm)
			delete(randomForm);
	}
}
