#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern( Intern const &other );
		Intern &operator=( Intern const &other );

		AForm *makeForm(const std::string &fname, const std::string &target) const;
};

#endif