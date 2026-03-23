#include "PhoneBook.hpp"

void	PhoneBook::set_ix(void)
{
	eight = false;
	ix = -1;
}

/*
* Function to handle all string cases for user input.
* In case of CTL-D the program ends*/
std::string PhoneBook::get_input(std::string msg)
{
    std::string input;

    while (true)
    {
        std::cout << msg;
		std::getline(std::cin, input);
		if (std::cin.eof())
        	exit(0);
        if (!input.empty())
        	break ;
    }
    return (input);
}

/*
* Function to handle all number cases for user input.
* In case of CTL-D the program ends*/
int PhoneBook::get_input_num(std::string msg)
{
    int num;
	std::string input;

    while (true)
    {
        std::cout << msg;
		std::getline(std::cin, input);
		if (!std::atoi(input.c_str()))
		{
			std::cout << "Enter a valid number\n";
			continue ;
		}
		if (std::cin.eof())
        	exit(0);
        if (!input.empty())
        	break ;
    }
	num = std::atoi(input.c_str());
    return (num);
}

/*
* Main adding logic.*/
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
	
	prompt = get_input("First Name: ");
	contact[ix].set_first_name(prompt);

	prompt = get_input("Last Name: ");
	contact[ix].set_last_name(prompt);

	prompt = get_input("Nickname: ");
	contact[ix].set_nickname(prompt);

	num = get_input_num("Phone Number: ");
	contact[ix].set_phone_number(num);
	
	prompt = get_input("Darkest Secret: ");
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
