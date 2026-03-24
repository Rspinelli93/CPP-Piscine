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

void    Contact::print_arg(std::string arg)
{
	if (arg.length() > 10)
		arg = arg.substr(0, 9) + ".";
	std::cout << std::setfill(' ') << std::setw(10) << arg;
}

void	Contact::print_contact(void)
{
	print_arg(first_name);
	std::cout << "|";
	print_arg(last_name);
	std::cout << "|";
	print_arg(nickname);
}

void	Contact::print_contact_details(void)
{
	std::ostringstream s_num;
	s_num << phone_number;
	std::string num = s_num.str();

	std::cout << std::setw(10) << "First Name: " << first_name << std::endl;
	std::cout << std::setw(10) << "Last Name: " << last_name << std::endl;
	std::cout << std::setw(10) << "Nickname: " << nickname << std::endl;
	std::cout << std::setw(10) << "Phone Number: " << num << std::endl;
	std::cout << std::setw(10) << "Darkest Secret: " << darkest_secret << std::endl;
	std::cout << std::endl;
}