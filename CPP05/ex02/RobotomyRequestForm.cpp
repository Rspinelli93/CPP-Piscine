#include "RobotomyRequestForm.hpp"

/// @brief Constructor for RobotomyRequestForm class
/// @param target Target private attribute to be set
RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("Robotomy Form", 72, 45) 
{
	this->_target = target;
	std::cout << "Robotomy Form: Constructor" <<std::endl;
}

/// @brief Getter member function
/// @return Returns the _target atribute of this form
std::string RobotomyRequestForm::getTarget( void ) { return ( this->_target ); }

/// @brief On success tries to Robotomize, if grade is not big enough, throw exception
/// @param executor Bureaucrat that tries to excecute.
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "*Makes some robotic noise*" <<std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << this->_target << " robotomy failed" << std::endl;
}