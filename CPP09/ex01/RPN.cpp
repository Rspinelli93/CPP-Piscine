#include "RPN.hpp"

//-------------------- ORTHODOX --------------------

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN( RPN const &other ) { this->_stack = other._stack; }

RPN &RPN::operator=( RPN const other ) 
{
	if ( this != &other )
		this->_stack = other._stack;
	return ( *this );
}

//-------------------- EXCEPTIONS --------------------

const char* RPN::zeroDivisionException::what() const throw() { return ( "\033[1;35mError:\033[0m Division by zero" ); }

const char* RPN::badCharException::what() const throw() { return ( "\033[1;35mError:\033[0m Bad char" ); }

const char* RPN::extraNumberException::what() const throw() { return ( "\033[1;35mError:\033[0m Too many numbers" ); }

const char* RPN::extraOperandException::what() const throw() { return ( "\033[1;35mError:\033[0m Too many operands" ); }

const char* RPN::notValidInputException::what() const throw() { return ( "\033[1;35mError:\033[0m Not valid input" ); }

//-------------------- OPERATIONS --------------------

static int	toInt( char c ) { return ( c - '0' ); }

static bool	isOperand( char c )
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return ( true );
	return ( false );
}

static int operate( int a, int b, char c)
{
	if (c == '+')
		return ( b + a );
	if (c == '-')
		return ( b - a );
	if (c == '*')
		return ( b * a );
	else
		return ( b / a );
}

int	RPN::calculate( std::string input )
{
	for (int i = 0; i < (int)input.length(); i++)
	{
		char	c = input.at(i);
		int		a;
		int		b;

		if (c == ' ')
			continue ;
		if (isdigit(c))
			this->_stack.push(toInt(c));
		else if (isOperand(c))
		{
			if (2 > this->_stack.size())
				throw extraOperandException();
			a = this->_stack.top();
			this->_stack.pop();
			b = this->_stack.top();
			this->_stack.pop();

			if (c == '/' && a == 0)
				throw zeroDivisionException();
			this->_stack.push(operate(a, b, c));
		}
		else
			throw badCharException();
	}
	if (this->_stack.size() != 1)
		throw extraNumberException();
	if (0 == this->_stack.size())
		throw notValidInputException();
	return (this->_stack.top());
}

//-------------------- UTILS --------------------

void RPN::emptyStack( void )
{
	this->_stack = std::stack<int>();
}
