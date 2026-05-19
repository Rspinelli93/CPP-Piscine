#include "Animal.hpp"

Animal::Animal() : _type("Animal") { std::cout << "Animal default constructor called" << std::endl; }

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal( std::string type ) : _type(type) { std::cout << "Animal param constructor called" << std::endl; }

Animal::Animal(const Animal &other) : _type(other._type) { std::cout << "Animal copy constructor called" << std::endl; }

Animal &Animal::operator=(const Animal &other) 
{
	if (this != &other)
		this->_type = other._type;
	return ( *this );
}

std::string Animal::getType( void ) const { return ( this->_type ); }

void Animal::makeSound( void ) const
{
	std::cout << "*Undefined animal sound*" << std::endl;
}
