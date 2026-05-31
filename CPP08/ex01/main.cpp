#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main( void )
{
	std::cout << "Simple test: \n-------------" << std::endl;
	
	Span mySpan(5);
	try
	{
		mySpan.addNumber(2);
		mySpan.addNumber(4);
		mySpan.addNumber(8);
		mySpan.addNumber(16);
		mySpan.addNumber(32);
		std::cout << "Longest Span: " << mySpan.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << mySpan.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\nTest overlow exception: \n-------------"<< std::endl;
	{
		try
		{
			mySpan.addNumber(64);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\nTest unpopulated exception: \n-------------"<< std::endl;
	Span mySpan2(5);
	mySpan2.addNumber(64);
	{
		try
		{
			std::cout << "Longest Span: " << mySpan2.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "Shortest Span: " << mySpan2.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\nSubject Test: \n-------------"<< std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\nTest 10.000: \n-------------"<< std::endl;
	{
		int SPANSIZE = 10000;
		Span sp(SPANSIZE);

		std::srand(std::time(NULL));
		for (int i = 0; i < SPANSIZE; i++)
		{
			try
			{
				sp.addNumber(std::rand() % 1000000000);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
}