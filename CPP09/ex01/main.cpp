#include "RPN.hpp"

int	main( int ac, char **av )
{
	if ( ac != 2 )
	{
		std::cout << "Error: need an input." << std::endl;
		return (1);
	}
	std::string	input = av[1];
	
	if (input.compare("test"))
	{
		RPN			polishCalculator;
		int			output;
	
		try
		{
			output = polishCalculator.calculate(input);
			std::cout << "Result: \033[1;32m" << output << "\033[0m" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		runTests();
	return (0);
}

/*
- Errors to check:

+ 1. Multiple values in the stack:
	7 7 7 -
	that means - i push the 3 7s
	the stack: [7, 7, 7]
	i do the minus
	the stack [7, 0] => If no more operators then throw error
	Stack needs to finish with only one number

+ 2. Divide by zero:
	2 0 / --> crash so here ii throw an error

+ 3. Bad char
	3 4 * 5 9 & --> throw error bad char

+ 4. Not enough numbers (or too much operands)
	1 2 + *
	that means -- push push [1, 2]
	do sum push result [3]
	cant do 3 * --> throw error
*/

/*
FOR each character in the string:

    IF character is a space:
        Continue to the next character (skip it).

    ELSE IF character is between '0' and '9':
        Convert character to integer.
        Push integer onto the stack.

    ELSE IF character is one of ('+', '-', '*', '/'):
        1. CHECK: Does the stack have at least 2 elements?
           NO -> Print "Error" and exit program.
           
        2. Pop the top element (this is Operand B / the second number).
        3. Pop the next element (this is Operand A / the first number).
        
        4. IF operator is '/' AND Operand B is 0:
           Print "Error" and exit program (Prevents crash).
           
        5. Calculate: Result = Operand A [operator] Operand B.
        6. Push Result onto the stack.

    ELSE (It is any other character like '(', ')', 'a', etc.):
        Print "Error" and exit program immediately.
*/