#include "PresidentialPardonForm.hpp"

/// @brief Constructor for PresidentialPardonForm class
/// @param target Target private attribute to be set
PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("Presidential Form", 25, 5) 
{
	this->_target = target;
	std::cout << "Presidential Form: Constructor" <<std::endl;
}

/// @brief Getter member function
/// @return Returns the _target atribute of this form
std::string PresidentialPardonForm::getTarget( void ) { return ( this->_target ); }

/// @brief On success gets pardon, if grade is not big enough, throw exception
/// @param executor Bureaucrat that tries to excecute.
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}