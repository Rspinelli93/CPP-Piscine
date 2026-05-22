#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		std::cout << "Test 1: Good grade for signing.\n----------------------" << std::endl;
		try
		{
			Bureaucrat Juan("Juan", 2);
			std::cout << Juan << "\n" << std::endl;
			Form Form1("Selling a car", 2, 4);
			std::cout << Form1 << "\n" << std::endl;
			std::cout << "Signing..." << std::endl;
			Juan.signForm(Form1);
			std::cout << Form1 << "\n" << std::endl;
		}
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }
		std::cout << "\nTest 2: Bad grade for signing.\n----------------------" << std::endl;
		try
		{
			Bureaucrat Luis("Luis", 200);
			std::cout << Luis << std::endl;
			Form Form1("Selling a car", 2, 4);
			Luis.signForm(Form1);
		}
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }
	}
}