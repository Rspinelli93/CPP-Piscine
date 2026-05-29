#include "easyfind.hpp"

int main( void )
{
	std::vector<int> v1;

	v1.push_back(0);
	v1.push_back(42);
	v1.push_back(10);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(7);
	v1.push_back(5);


	try
	{
		std::cout << easyfind(v1, 42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << easyfind(v1, 5) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	try
	{
		std::cout << easyfind(v1, 3) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	try
	{
		std::cout << easyfind(v1, -42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	try
	{
		std::cout << easyfind(v1, 10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	try
	{
		std::cout << easyfind(v1, 100) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	try
	{
		std::cout << easyfind(v1, 0) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}