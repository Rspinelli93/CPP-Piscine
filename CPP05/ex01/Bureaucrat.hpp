#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Form.hpp"

class Form;

/// @brief Bureaucrat class, contains a name and a grade as private atributes
class Bureaucrat
{
	private:
		const std::string _name;
		int			_grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat( std::string const &name, int grade );
		Bureaucrat( Bureaucrat const &other );
		Bureaucrat &operator=( Bureaucrat const &other );
		
		int getGrade( void ) const;
		std::string const &getName( void ) const;
		void incrementGrade( void );
		void decrementGrade( void );

		/// @brief Bureaucrat exception class to throw an error if _grade number is > than 150
		class GradeTooHighException : public std::exception
		{
    		public:
        		const char* what() const throw();
   		};
		/// @brief Bureaucrat exception class to throw an error if _grade number is < than 1
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		void signForm( Form &f );
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &mr);

#endif