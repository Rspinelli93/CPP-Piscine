#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream> 
#include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm( std::string target );
		void execute(Bureaucrat const & executor) const;
		std::string getTarget( void );
};

std::string getTree( void );
void 		createOuputFile( std::string target );

#endif