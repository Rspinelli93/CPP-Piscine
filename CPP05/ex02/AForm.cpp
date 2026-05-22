#include "AForm.hpp"
#include "Bureaucrat.hpp"

//----------------- Orthodox declaration -------------

AForm::AForm() : _name("undef"), _signed(false), _sign_grade(1), _excecute_grade(1) { std::cout << "AForm: Default constructor" << std::endl; }

AForm::~AForm() { std::cout << "AForm: Destructor" << std::endl; }

/// @brief Constructor to a AForm
/// @param name Name of the AForm
/// @param sign_grade Min grade needed to be able to sign the AForm
/// @param excecute_grade Min grade needed to be able to excecute the AForm
/// @attention The AForm is alway initialized to not signed (_singed = false )
AForm::AForm(std::string const name, int sign_grade, int excecute_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _excecute_grade(excecute_grade)
{
    if (sign_grade < 1 || excecute_grade < 1)
        throw AForm::GradeTooHighException();
    if (sign_grade > 150 || excecute_grade > 150)
        throw AForm::GradeTooLowException();
    std::cout << "AForm: Param constructor" << std::endl;
}

AForm::AForm(AForm const &other): _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _excecute_grade(other._excecute_grade)
{ std::cout << "AForm: Copy constructor" << std::endl; }

AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

//-------------------- Getters + Overload << -------------

std::string	AForm::getName( void ) const { return ( this->_name); }

bool		AForm::getSigned( void ) const { return ( this->_signed); }

int			AForm::getSignGrade( void ) const { return ( this->_sign_grade); }

int			AForm::getExecGrade( void ) const { return ( this->_excecute_grade); }

/// @brief "<<" Overload to print all the inAFormation about the AForm
/// @param out Output stream
/// @param f AForm to print
/// @return Reference to the output stream
std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "AForm: " << f.getName() << "\nIs signed: " << f.getSigned() << "\nSign grade: " << f.getSignGrade() << "\nExecute grade: " << f.getExecGrade();
	return ( out );
}

//-------------------- Signing and Exceptions ---------------------

const char* AForm::GradeTooHighException::what() const throw() { return ( "Grade too high" );}

const char* AForm::GradeTooLowException::what() const throw() { return ( "Grade too low" );}

/// @brief Function to sign the AForm, it will check if Bureaucrat "b" has enough grade to sign.
/// @param b Bureaucrat to sing the AForm.
void AForm::beSigned( Bureaucrat &b )
{
	if (b.getGrade() > this->_sign_grade)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

//----------------- Added Execution and other exeption ------------

const char* AForm::FormNotSignedException::what() const throw() { return ( "Form not signed" );}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!this->_signed)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_excecute_grade)
        throw AForm::GradeTooLowException();
}