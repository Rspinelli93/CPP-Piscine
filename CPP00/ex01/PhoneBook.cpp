#include "PhoneBook.hpp"

void	PhoneBook::set_ix(void)
{
	eight = false;
	ix = -1;
}

void	PhoneBook::add(void)
{
	std::string	prompt;
	int			num = 0;

	if (ix == 7)
	{
		ix = 0;
		eight = true;
	}
	else
		ix++;
	
	std::cout << "First Name: ";
	std::cin >> prompt;
	contact[ix].set_first_name(prompt);

	std::cout << "Last Name: ";
	std::cin >> prompt;
	contact[ix].set_last_name(prompt);

	std::cout << "Nickname: ";
	std::cin >> prompt;
	contact[ix].set_nickname(prompt);

	std::cout << "Phone Number: ";
	std::cin >> num;
/* 	while (!std::cin >> num)
	{
		std::cout << "Set a numberic value\nPhone Number: ";
		std::cin.clear();
	} */
	contact[ix].set_phone_number(num);

	std::cout << "Darkest Secret: ";
	std::cin >> prompt;
	contact[ix].set_secret(prompt);
}

void	PhoneBook::search(void)
{
	int i = 0;

	if (ix == -1)
		return ;
	while ((i < 8 && eight == true) || (i <= ix && eight == false))
	{
		contact[i].print_info(0);
		std::cout << std::endl;
		contact[i].print_info(1);
		std::cout << std::endl;
		contact[i].print_info(2);
		std::cout << std::endl;
		contact[i].print_info(3);
		std::cout << std::endl;
		contact[i].print_info(4);
		std::cout << std::endl;
		i++;
	}
}
