#include "Form.hpp"
#include "Bureaucrat.hpp"

//----------------- Orthodox declaration -------------

Form::Form() : _name("undef"), _signed(false), _sign_grade(1), _excecute_grade(1) { std::cout << "Form: Default constructor" << std::endl; }

Form::~Form() { std::cout << "Form: Destructor" << std::endl; }

/// @brief Constructor to a Form
/// @param name Name of the form
/// @param sign_grade Min grade needed to be able to sign the form
/// @param excecute_grade Min grade needed to be able to excecute the form
/// @attention The form is alway initialized to not signed (_singed = false )
Form::Form(std::string const name, int sign_grade, int excecute_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _excecute_grade(excecute_grade)
{
    if (sign_grade < 1 || excecute_grade < 1)
        throw Form::GradeTooHighException();
    if (sign_grade > 150 || excecute_grade > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form: Param constructor" << std::endl;
}

Form::Form(Form const &other): _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _excecute_grade(other._excecute_grade)
{ std::cout << "Form: Copy constructor" << std::endl; }

Form &Form::operator=(Form const &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

//-------------------- Getters + Overload << -------------

std::string	Form::getName( void ) const { return ( this->_name); }

bool		Form::getSigned( void ) const { return ( this->_signed); }

int			Form::getSignGrade( void ) const { return ( this->_sign_grade); }

int			Form::getExecGrade( void ) const { return ( this->_excecute_grade); }

/// @brief "<<" Overload to print all the information about the form
/// @param out Output stream
/// @param f Form to print
/// @return Reference to the output stream
std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Form: " << f.getName() << "\nIs signed: " << f.getSigned() << "\nSign grade: " << f.getSignGrade() << "\nExecute grade: " << f.getExecGrade();
	return ( out );
}

//-------------------- Execution and Exceptions ---------------------

const char* Form::GradeTooHighException::what() const throw() { return ( "Grade too high" );}

const char* Form::GradeTooLowException::what() const throw() { return ( "Grade too low" );}

/// @brief Function to sign the form, it will check if Bureaucrat "b" has enough grade to sign.
/// @param b Bureaucrat to sing the form.
void Form::beSigned( Bureaucrat &b )
{
	if (b.getGrade() > this->_sign_grade)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}