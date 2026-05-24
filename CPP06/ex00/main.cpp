#include "ScalarConverter.hpp"

int main(int ac, char **av )
{
	if (ac != 2)
	{
		std::cout << "Usage: ./Convert + [arg] --- or ./Convert + \"TEST ALL\" to run all tests." << std::endl;
		return (1);
	}
	std::string	val = av[1];
	if (val == "TEST ALL")
	{
		std::cout << "Simple valid tests:\n--------------" << std::endl;
		std::cout << "ARG: 0" << std::endl;
		ScalarConverter::convert("0");
		std::cout << "\n";
		std::cout << "ARG: 65" << std::endl;
		ScalarConverter::convert("65");
		std::cout << "\n";
		std::cout << "ARG: 70.8f" << std::endl;
		ScalarConverter::convert("70.8f");
		std::cout << "\n";
		std::cout << "ARG: 42.93278" << std::endl;
		ScalarConverter::convert("42.93278");
		std::cout << "\n";
		std::cout << "ARG: 1.7976931348623157 (Float presition change case)" << std::endl;
		ScalarConverter::convert("1.7976931348623157");
		std::cout << "\n";
		std::cout << "ARG: 0.0" << std::endl;
		ScalarConverter::convert("0.0");
		std::cout << "\n";
		std::cout << "ARG: -42" << std::endl;
		ScalarConverter::convert("-42");
		std::cout << "\n";
		std::cout << "ARG: 127" << std::endl;
		ScalarConverter::convert("127");
		std::cout << "\n";
		std::cout << "ARG: -3.14f" << std::endl;
		ScalarConverter::convert("-3.14f");
		std::cout << "\n";

		std::cout << "\n\nInvalid tests:\n--------------" << std::endl;
		ScalarConverter::convert("0.0.7");
		std::cout << "\n";
		ScalarConverter::convert("65asd");
		std::cout << "\n";
		ScalarConverter::convert("--3");
		std::cout << "\n";
		ScalarConverter::convert("++3");
		std::cout << "\n";
		ScalarConverter::convert("7.8.9f");
		std::cout << "\n";
		ScalarConverter::convert("f42.9%&");
		std::cout << "\n";
		ScalarConverter::convert("3249872398742983479203123921390123120381209831209380129837498237489327498274892379843272489");
		std::cout << "\n";
		std::cout << "ARG: *empty string*" << std::endl;
		ScalarConverter::convert("");
		std::cout << "\n";
		ScalarConverter::convert(".");
		std::cout << "\n";

		std::cout << "\n\nSpecial case tests:\n--------------" << std::endl;
		std::cout << "ARG: nan" << std::endl;
		ScalarConverter::convert("nan");
		std::cout << "\n";
		std::cout << "ARG: nanf" << std::endl;
		ScalarConverter::convert("nanf");
		std::cout << "\n";
		std::cout << "ARG: +inf" << std::endl;
		ScalarConverter::convert("+inf");
		std::cout << "\n";
		std::cout << "ARG: -inf" << std::endl;
		ScalarConverter::convert("-inf");
		std::cout << "\n";
		std::cout << "ARG: +inff" << std::endl;
		ScalarConverter::convert("+inff");
		std::cout << "\n";
		std::cout << "ARG: -inff" << std::endl;
		ScalarConverter::convert("-inff");
		std::cout << "\n";
	}
	else
		ScalarConverter::convert(val);
	return (0);
}

