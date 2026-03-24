#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class	Contact
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string darkest_secret;
	int			phone_number;
	public:
		void set_first_name(std::string prompt);
		void set_last_name(std::string prompt);
		void set_nickname(std::string prompt);
		void set_phone_number(int number);
		void set_secret(std::string prompt);
		void print_arg(std::string arg);
		void print_contact(void);
		void print_contact_details(void);
};

#endif