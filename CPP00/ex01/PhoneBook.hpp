#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACTS 8

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class	PhoneBook
{
	Contact	contact[MAX_CONTACTS];
	int		ix;
	bool	max;
	public:
		void set_ix(void);
		void update_ix(void);
		void add(void);
		void search(void);
		std::string get_input(std::string msg);
		int get_input_num(std::string msg);
		void print_header();
	};

#endif
