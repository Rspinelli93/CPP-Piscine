#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
	std::cout << "Test 1: Robotmy\n------------" << std::endl;
	{
		Intern Intern;
		AForm *randomForm;
		randomForm = Intern.makeForm("robotomy request", "Bender");
		if (randomForm)
			delete(randomForm);
	}
	std::cout << "\n\nTest 2: Shruberry\n------------" << std::endl;
	{
		Intern Intern;
		AForm *randomForm;
		randomForm = Intern.makeForm("shrubbery creation", "Bender");
		if (randomForm)
			delete(randomForm);
	}
	std::cout << "\n\nTest 3: Presidential\n------------" << std::endl;
	{
		Intern Intern;
		AForm *randomForm;
		randomForm = Intern.makeForm("presidential pardon", "Bender");
		if (randomForm)
			delete(randomForm);
	}
	std::cout << "\n\nTest 4: Wronf Form\n------------" << std::endl;
	{
		Intern Intern;
		AForm *randomForm;
		randomForm = Intern.makeForm("wrong name", "Bender");
		if (randomForm)
			delete(randomForm);
	}
}
