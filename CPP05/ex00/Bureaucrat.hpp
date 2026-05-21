#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>

class Bureaucrat
{
	private:
		std::string _name;
		int			_grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat( std::string const &name, int grade );
		Bureaucrat( Bureaucrat const &other );
		Bureaucrat &operator=( Bureaucrat const &other );
		
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