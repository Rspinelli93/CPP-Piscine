#include "Contact.hpp"

void	Contact::set_first_name(std::string prompt)
{
	first_name = prompt;
}

void	Contact::set_last_name(std::string prompt)
{
	last_name = prompt;
}

void	Contact::set_nickname(std::string prompt)
{
	nickname = prompt;
}

void	Contact::set_phone_number(int number)
{
	phone_number = number;
}

void	Contact::set_secret(std::string prompt)
{
	darkest_secret = prompt;
}

void	Contact::print_info(int i)
{
	if (i == 0)
		std::cout << first_name;
	if (i == 1)
		std::cout << last_name;
	if (i == 2)
		std::cout << nickname;
	if (i == 3)
		std::cout << phone_number;
	if (i == 4)
		std::cout << darkest_secret;
}
