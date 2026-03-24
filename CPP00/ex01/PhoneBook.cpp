#include "PhoneBook.hpp"
#include <cstdio>
/*
* Helper to init the index of the PhoneBook.
* I use "max" to help in the iteration of the search.*/
void	PhoneBook::set_ix(void)
{
	max = false;
	ix = -1;
}

/*
* Helper to update the index of the PhoneBook.*/
void	PhoneBook::update_ix(void)
{
	if (ix == 7)
	{
		ix = 0;
		max = true;
	}
	else
		ix++;
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

	std::cout << std::endl;
	update_ix();
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
	std::cout << std::endl;
}

/*
* Helper to print the header in the board of Contacts.*/
void	PhoneBook::print_header(void)
{
	std::cout << std::setfill(' ');
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
}

/*
* Main Search logic.*/
void	PhoneBook::search(void)
{
	int 		i = 0;
	int 		ix_input = 0;
	std::string input;

	if (ix == -1)
		return ;
	std::cout << std::endl;
	print_header();
	while ((i < MAX_CONTACTS && max == true) || (i <= ix && max == false))
	{
		std::cout << std::setfill (' ');
		std::cout << std::setw (9) << i + 1 << "." << "|";
		contact[i].print_contact();
		std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << "Select an index: ";
	std::cin >> input;
	std::cout << std::endl;
	ix_input = std::atoi(input.c_str());
	if (ix_input < 1 || ix_input > 8)
	{
		std::cout << "Not a valid index!" << std::endl;
		return ;
	}
	i = 0;
	while ((i < MAX_CONTACTS && max == true) || (i <= ix && max == false))
	{
		if (i == ix_input - 1)
		{
			contact[i].print_contact_details();
			return ;
		}
		i++;
	}
	std::cout << "Not a valid index!" << std::endl;
	return ;
}
