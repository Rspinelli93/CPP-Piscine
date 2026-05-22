#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("*undefined_name*"), _grade(150) { std::cout << "Bureaucrat: Default constructor" << std::endl; }

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat: Destructor" << std::endl; }

/// @brief Constructor function for Bureaucrat:
/// @param name Takes a string to be the name of the Bureaucrat
/// @param grade Takes a int for the grade, 1 max grade, 150 min grade
Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat: Param Constructor" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const &other ) : _name( other._name ), _grade( other._grade ) { std::cout << "Bureaucrat: Copy constructor" << std::endl; }

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &other )
{
	if ( this != &other )
	{
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return ( *this );
}

/// @brief Exception function for controlling the grade number to be in the range of 0 to 150
/// @return A string with the error message
const char* Bureaucrat::GradeTooHighException::what() const throw() { return ( "Grade too high" ); }

/// @brief Exception function for controlling the grade number to be in the range of 0 to 150
/// @return A string with the error message
const char* Bureaucrat::GradeTooLowException::what() const throw() { return ( "Grade too high" ); }

/// @return Grade of a Bureaucrat
int Bureaucrat::getGrade( void ) const { return ( this->_grade ); }

/// @return Name of a Bureaucrat
std::string const &Bureaucrat::getName( void ) const { return ( this->_name ); }


/// @brief Increase by one the grade of a Bureaucrat
void Bureaucrat::incrementGrade(void)
{
    if ((this->_grade - 1) < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

/// @brief Decrease by one the grade of a Bureaucrat
void Bureaucrat::decrementGrade(void)
{
    if ((this->_grade + 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &mr)
{
    out << mr.getName() << ", bureaucrat grade " << mr.getGrade();
    return out;
}