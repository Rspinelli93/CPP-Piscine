#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("*undefined_name*"), _grade(150) { std::cout << "Bureaucrat: Default constructor" << std::endl; }

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat: Destructor" << std::endl; }

Bureaucrat::Bureaucrat( std::string const &name, int grade )
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
		{
			this->_name = name;
			this->_grade = grade;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

Bureaucrat::Bureaucrat( Bureaucrat const &other );

Bureaucrat::Bureaucrat &operator=( Bureaucrat const &other );

const char* Bureaucrat::GradeTooHighException::what() const throw() { return ( "Grade too high" ); }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return ( "Grade too high" ); }