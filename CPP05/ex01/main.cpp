#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "Test 1: (Incrementing max grade)\n----------------------" << std::endl;
		Bureaucrat Miguel("Miguel", 1);
		std::cout << Miguel << std::endl;

		std::cout << "Incrementing " << Miguel.getName() << " grade:" << std::endl;
		try 
		{ Miguel.incrementGrade(); }
		catch (std::exception &e)
		{ std::cerr << e.what() << std::endl; }

		std::cout << "Decrementing " << Miguel.getName() << " grade:" << std::endl;
		try 
		{ Miguel.decrementGrade(); }
		catch (std::exception &e) 
		{ std::cerr << e.what() << std::endl; }

		std::cout << Miguel << std::endl;
	}
	{
		std::cout << "\n\nTest 2: (Decrementing min grade)\n----------------------" << std::endl;
		Bureaucrat Miguel("Miguel", 150);
		std::cout << Miguel << std::endl;

		std::cout << "Decrementing " << Miguel.getName() << " grade:" << std::endl;
		try
		{ Miguel.decrementGrade(); }
		catch (std::exception &e)
		{ std::cerr << e.what() << std::endl; }

		std::cout << "Incrementing " << Miguel.getName() << " grade:" << std::endl;
		try
		{ Miguel.incrementGrade(); }
		catch
		(std::exception &e) { std::cerr << e.what() << std::endl; }
		
		std::cout << Miguel << std::endl;
	}
	{
		std::cout << "\n\nTest 3: (Creating out of range)\n----------------------" << std::endl;
		try
		{
			Bureaucrat Juan("Juan", 350);
			std::cout << Juan << std::endl;
		}
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }
		try
		{
			Bureaucrat Luis("Luis", 0);
			std::cout << Luis << std::endl;
		}
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }
	}
}