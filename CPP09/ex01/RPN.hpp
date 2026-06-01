#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int> _stack;
	public:
		RPN();
		~RPN();
		RPN( RPN const &other );
		RPN &operator=( RPN const other );

		class zeroDivisionException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class badCharException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class extraNumberException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class extraOperandException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class notValidInputException : public std::exception
		{
			public:			
				const char* what() const throw();
		};

		int	calculate( std::string input );
		void emptyStack( void );
};

void	runTests( void );

#endif