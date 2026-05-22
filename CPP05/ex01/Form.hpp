#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &out, const Form &f);

class Form
{
	private:
		std::string _name;
		bool		_signed;
		int			_sign_grade;
		int			_excecute_grade;
	public:
		Form();
		~Form();
		Form(std::string name, int sign_grade, int excecute_grade);
		Form(Form const &other);
		Form &operator=(Form const &other);

		std::string getName( void ) const ;
		bool getSigned( void ) const ;
		int getSignGrade( void ) const ;
		int getExecGrade( void ) const ;

		class GradeTooHighException : public std::exception
		{
			public: 
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif