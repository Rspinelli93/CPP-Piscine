#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

template <typename T>
void runTest(std::string target, int bad_grade);

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "\033[32m" << "Test the 3 classes one by one.\n" << "\033[0m" << "Usage: ./Bureaucrat + [num]" << "\033[32m" << "\nValid tests values: 1, 2 or 3." << "\033[0m" << std::endl;
		return (1);
	}
	std::string testNum = av[1];
	if (testNum == "1")
		runTest<ShrubberyCreationForm>("home", 138);
	else if(testNum == "2")
		runTest<RobotomyRequestForm>("Vincent", 46);
	else if (testNum == "3")
		runTest<PresidentialPardonForm>("President Morty", 6);
	else
	{
		std::cout << "\033[31m" << "Not a valid Test number, use 1, 2 or 3" << "\033[0m" << std::endl;
		return (1);
	}
	return (0);
}

/// @brief Runs 3 tests for a given Form class: OK, unsigned form, bad grade
/// @tparam T Form class to test (ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm)
/// @param target Target passed to the Form constructor
/// @param bad_grade Grade expected to fail in 3rd test (check min exec grade of each class)
template <typename T>
void runTest(std::string target, int bad_grade)
{
    {
        std::cout << "\033[32m" << "Test 1: All OK\n----------------------" << "\033[0m" << std::endl;
        Bureaucrat Juan("Juan", 2);
        T Form(target);
        std::cout << "\nSigning..." << std::endl;
        Juan.signAForm(Form);
        std::cout << "Executing..." << std::endl;
        try
        {
            Form.execute(Juan);
            std::cout << "\n";
        }
        catch (std::exception &e) { std::cerr << e.what() << "\n" << std::endl; }
    }
    {
        std::cout << "\033[32m" << "\n\nTest 2: Not signed\n----------------------" << "\033[0m"  << std::endl;
        Bureaucrat Juan("Juan", 2);
        T Form(target);
        std::cout << "\nExecuting...\n" << std::endl;
        try
        {
            Form.execute(Juan);
        }
        catch (std::exception &e) { std::cerr << e.what() << "\n" << std::endl; }
    }
    {
        std::cout << "\033[32m" << "\n\nTest 3: Bad grade\n----------------------" << "\033[0m" << std::endl;
        Bureaucrat Juan("Juan", bad_grade);
        T Form(target);
        std::cout << "\nSigning..." << std::endl;
        Juan.signAForm(Form);
        std::cout << "Form signed\nExecuting...\n" << std::endl;
        try
        {
            Form.execute(Juan);
        }
        catch (std::exception &e) { std::cerr << e.what() << "\n" << std::endl; }
    }
}





//--------------------------------------------
/* static void testShruberry( void )
{
	{
		std::cout << "Test Shruberry 1: All OK\n----------------------" << std::endl;
		Bureaucrat Juan("Juan", 2);
		ShrubberyCreationForm Form("/home/rick/Documents/CPP/CPP05/ex02/");
		std::cout << "\nSigning..." << std::endl;
		Juan.signAForm(Form);
		std::cout << "Executing..." << std::endl;
		try
		{
			Form.execute(Juan);
			std::cout << "\n";
		}
		catch (std::exception &e) { std::cerr << e.what() << "\n" << std::endl; }
	}
	{
		std::cout << "\n\nTest Shruberry 2: Not signed\n----------------------" << std::endl;
		Bureaucrat Juan("Juan", 2);
		ShrubberyCreationForm Form("/home/rick/Documents/CPP/CPP05/ex02/");
		std::cout << "\nExecuting...\n" << std::endl;
		try
		{
			Form.execute(Juan);
		}
		catch (std::exception &e) { std::cerr << e.what() << "\n" << std::endl; }
	}
	{
		std::cout << "\n\nTest Shruberry 3: Bad grade\n----------------------" << std::endl;
		Bureaucrat Juan("Juan", 138);
		ShrubberyCreationForm Form("/home/rick/Documents/CPP/CPP05/ex02/");
		std::cout << "\nSigning..." << std::endl;
		Juan.signAForm(Form);
		std::cout << "Form signed\nExecuting...\n" << std::endl;
		try
		{
			Form.execute(Juan);
		}
		catch (std::exception &e) { std::cerr << e.what() << "\n" << std::endl; }
	}
}

static void testRobotomy( void )
{
	{
		std::cout << "Test Robotomy 1: All OK\n----------------------" << std::endl;
		Bureaucrat Juan("Juan", 2);
		RobotomyRequestForm Form("Vincent");
		std::cout << "\nSigning..." << std::endl;
		Juan.signAForm(Form);
		std::cout << "Executing..." << std::endl;
		try
		{
			Form.execute(Juan);
			std::cout << "\n";
		}
		catch (std::exception &e) { std::cerr << e.what() << "\n" << std::endl; }
	}
	{
		std::cout << "\n\nTest Robotomy 2: Not signed\n----------------------" << std::endl;
		Bureaucrat Juan("Juan", 2);
		RobotomyRequestForm Form("Vincent");
		std::cout << "\nExecuting...\n" << std::endl;
		try
		{
			Form.execute(Juan);
		}
		catch (std::exception &e) { std::cerr << e.what() << "\n" << std::endl; }
	}
	{
		std::cout << "\n\nTest Robotomy 3: Bad grade\n----------------------" << std::endl;
		Bureaucrat Juan("Juan", 46);
		RobotomyRequestForm Form("Vincent");
		std::cout << "\nSigning..." << std::endl;
		Juan.signAForm(Form);
		std::cout << "Form signed\nExecuting...\n" << std::endl;
		try
		{
			Form.execute(Juan);
		}
		catch (std::exception &e) { std::cerr << e.what() << "\n" << std::endl; }
	}
}

static void testPresidential( void )
{
	{
		std::cout << "Test Robotomy 1: All OK\n----------------------" << std::endl;
		Bureaucrat Juan("Juan", 2);
		RobotomyRequestForm Form("President Morty");
		std::cout << "\nSigning..." << std::endl;
		Juan.signAForm(Form);
		std::cout << "Executing..." << std::endl;
		try
		{
			Form.execute(Juan);
			std::cout << "\n";
		}
		catch (std::exception &e) { std::cerr << e.what() << "\n" << std::endl; }
	}
	{
		std::cout << "\n\nTest Robotomy 2: Not signed\n----------------------" << std::endl;
		Bureaucrat Juan("Juan", 2);
		RobotomyRequestForm Form("President Morty");
		std::cout << "\nExecuting...\n" << std::endl;
		try
		{
			Form.execute(Juan);
		}
		catch (std::exception &e) { std::cerr << e.what() << "\n" << std::endl; }
	}
	{
		std::cout << "\n\nTest Robotomy 3: Bad grade\n----------------------" << std::endl;
		Bureaucrat Juan("Juan", 6);
		RobotomyRequestForm Form("President Morty");
		std::cout << "\nSigning..." << std::endl;
		Juan.signAForm(Form);
		std::cout << "Form signed\nExecuting...\n" << std::endl;
		try
		{
			Form.execute(Juan);
		}
		catch (std::exception &e) { std::cerr << e.what() << "\n" << std::endl; }
	}
}*/
