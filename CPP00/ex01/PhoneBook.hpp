#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
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
		std::string get_input(std::string msg);
		int get_input_num(std::string msg);
};

#endif
