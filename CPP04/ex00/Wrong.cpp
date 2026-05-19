#include "Wrong.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") { std::cout << "WrongAnimal default constructor called" << std::endl; }

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

WrongAnimal::WrongAnimal( std::string type ) : _type(type) { std::cout << "WrongAnimal param constructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) { std::cout << "WrongAnimal copy constructor called" << std::endl; }

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) 
{
	if (this != &other)
		this->_type = other._type;
	return ( *this );
}

std::string WrongAnimal::getType( void ) { return ( this->_type ); }

void WrongAnimal::makeSound( void )
{
	std::cout << "*Undefined Wronganimal sound*" << std::endl;
}

//--------------------------------

WrongCat::WrongCat() : WrongAnimal("WrongCat") { std::cout << "WrongCat constructor called" << std::endl; }

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

void WrongCat::makeSound( void ) { std::cout << "Meow!" << std::endl; }
