#include "ShrubberyCreationForm.hpp"

/// @brief Constructor for ShrubberyCreationForm class
/// @param target Target private attribute to be set
ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("Shrubbery Form", 145, 137) 
{
	this->_target = target;
	std::cout << "Shrubbery Form: Constructor" <<std::endl;
}

/// @brief Getter member function
/// @return Returns the _target atribute of this form
std::string ShrubberyCreationForm::getTarget( void ) { return ( this->_target ); }


/// @brief Helper function to draw a tree
/// @return A tree-shaped string.
std::string getTree( void )
{
    return (
        "    *\n"
        "   ***\n"
        "  *****\n"
        " *******\n"
        "  *****\n"
        "    |\n"
    );
}

/// @brief Creates a new file with a tree inside
/// @param target Target directory
void createOuputFile( std::string target )
{
	std::string outputFileName = target + "_shrubbery";
	std::ofstream outputFile(outputFileName.c_str());
	outputFile << getTree();
	outputFile.close();
	std::cout << "File created: " << outputFileName << std::endl;
}

/// @brief On success runs createOutputFile(), if grade is not big enough, throw exception
/// @param executor Bureaucrat that tries to excecute.
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    createOuputFile(this->_target);
}