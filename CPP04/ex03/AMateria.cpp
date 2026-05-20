#include "AMateria.hpp"

AMateria::AMateria( void ) { std::cout << "AMateria: Default constructor" <<std::endl; }

AMateria::~AMateria( void ){ std::cout << "AMateria: Destructor" <<std::endl; }

AMateria::AMateria( AMateria const &other ) : _type(other._type) { std::cout << "AMateria: Copy constructor" <<std::endl; }

AMateria::AMateria(std::string const &type) : _type(type) { std::cout << "AMateria: Param constructor" <<std::endl; }

AMateria &AMateria::operator=( AMateria const &other )
{
	if (this != &other)
		this->_type = other._type;
	return ( *this );
}

std::string const &AMateria::getType( void ) const { return (this->_type); }