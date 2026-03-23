#include "PhoneBook.hpp"

int	main(void)
{
	std::string	prompt;
	PhoneBook	my_pbook;

    my_pbook.set_ix();
	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT):\n";
		std::cin >> prompt;
		if (std::cin.eof())
        	exit(0);
		if (!prompt.compare("ADD"))
		{
			std::cin.ignore(10000, '\n');
			my_pbook.add();
		}
		else if (!prompt.compare("SEARCH"))
			my_pbook.search();
		else if (!prompt.compare("EXIT"))
			break ;
	}
	return (0);
}
