#include "RPN.hpp"

void	runTests( void )
{
	RPN			polishCalculator;
	int			output;

	{
		try { output = polishCalculator.calculate("8 9 * 9 - 9 - 9 - 4 - 1 +"); std::cout << "Expected output: \033[0;33m42\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("7 7 * 7 -"); std::cout << "Expected output: \033[0;33m42\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("1 2 * 2 / 2 * 2 4 - +"); std::cout << "Expected output: \033[0;33m0\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("(1 + 1)"); std::cout << "Expected output: \033[0;33mError\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << "Expected output: \033[0;33mError\033[0m\n" << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("4 0 /"); std::cout << "Expected output: \033[0;33mError\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << "Expected output: \033[0;33mError\033[0m\n" << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("2 3 + *"); std::cout << "Expected output: \033[0;33mError\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << "Expected output: \033[0;33mError\033[0m\n" << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("5 5 5 +"); std::cout << "Expected output: \033[0;33mError\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << "Expected output: \033[0;33mError\033[0m\n" << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("     "); std::cout << "Expected output: \033[0;33mError\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << "Expected output: \033[0;33mError\033[0m\n" << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("0 5 * 9 +"); std::cout << "Expected output: \033[0;33m9\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("3 5 -"); std::cout << "Expected output: \033[0;33m-2\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("9 3 / 2 /"); std::cout << "Expected output: \033[0;33m1\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("5 9 8 + + 3 *"); std::cout << "Expected output: \033[0;33m66\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("+ 1 2"); std::cout << "Expected output: \033[0;33mError\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << "Expected output: \033[0;33mError\033[0m\n" << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("1 2 3 4 5 + + + +"); std::cout << "Expected output: \033[0;33m15\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("9 9 * 9 * 9 * 9 *"); std::cout << "Expected output: \033[0;33m59049\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }
	}
	polishCalculator.emptyStack();
	{
		try { output = polishCalculator.calculate("5 2 %"); std::cout << "Expected output: \033[0;33mError\033[0m\n Result: \033[1;32m" << output << "\033[0m\n" << std::endl; }
		catch(const std::exception& e) { std::cerr << "Expected output: \033[0;33mError\033[0m\n" << e.what() << "\n\n"; }
	}
}
