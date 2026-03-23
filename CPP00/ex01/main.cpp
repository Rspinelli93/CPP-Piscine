#include "PhoneBook.hpp"

int	main(void)
{
	std::string	prompt;
	PhoneBook	my_pbook;

    my_pbook.set_ix();
	while (1)
	{
		std::cin >> prompt;
		if (!prompt.compare("ADD"))
			my_pbook.add();
		else if (!prompt.compare("SEARCH"))
			my_pbook.search();
		else if (!prompt.compare("EXIT"))
			break ;
	}
	return (0);
}
