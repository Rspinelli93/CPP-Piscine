#include "Cat.hpp"

Cat::Cat() : Animal("Cat") { std::cout << "Cat constructor called" << std::endl; }

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat::Cat(const Cat &other) { this->_type = other._type; std::cout << "Cat copy constructor called" << std::endl; }

Cat &Cat::operator=(const Cat &other) 
{
	if (this != &other)
		this->_type = other._type;
	return ( *this );
}

void Cat::makeSound( void ) const { std::cout << "Meow!" << std::endl; }
