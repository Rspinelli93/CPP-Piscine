#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool			_signed;
		const int		_sign_grade;
		const int		_excecute_grade;
	public:
		AForm();
		virtual ~AForm();
		AForm(std::string const name, int sign_grade, int excecute_grade);
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);

		std::string getName( void ) const ;
		bool getSigned( void ) const ;
		int getSignGrade( void ) const ;
		int getExecGrade( void ) const ;

		void beSigned( Bureaucrat &b );
		virtual void execute(Bureaucrat const & executor) const = 0;

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
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif