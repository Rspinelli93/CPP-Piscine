#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class	PhoneBook
{
	Contact	contact[8];
	int		ix;
	bool	eight;
	public:
		void set_ix(void);
		void add(void);
		void search(void);
};

#endif
