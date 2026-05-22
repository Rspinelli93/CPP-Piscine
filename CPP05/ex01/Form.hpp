#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool			_signed;
		const int		_sign_grade;
		const int		_excecute_grade;
	public:
		Form();
		~Form();
		Form(std::string const name, int sign_grade, int excecute_grade);
		Form(Form const &other);
		Form &operator=(Form const &other);

		std::string getName( void ) const ;
		bool getSigned( void ) const ;
		int getSignGrade( void ) const ;
		int getExecGrade( void ) const ;

		void beSigned( Bureaucrat &b );

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

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif