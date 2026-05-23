#include "ScalarConverter.hpp"

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

// MAIN LOGIC::

// Take the string and check all cases (function returns a enum or type)
// Top function checks all cases
// Create all printing functions
// Print acordingly with a switch

int main()
{
	std::string val = "5f";
    char* end;
    double number;
	number = strtod(val.c_str(), &end);

	if (end && !strncmp("f", end, 2))
		std::cout << "is a float" << std::endl;

	if (!number && val != "0")
		std::cout << "is a char" << std::endl;

    std::cout << "number = " << val << std::endl;
    std::cout << "double = " << number << std::endl;
    std::cout << "end string = " << end << std::endl;

    return 0;
}