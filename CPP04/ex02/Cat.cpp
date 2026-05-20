#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	delete(this->_brain);
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat( Cat &other ) : Animal(other)
{
	Brain *New = new Brain();
	*New = *other.getBrain();
	this->_brain = New;
	std::cout << "Cat copy constructor called" << std::endl;
}

void Cat::makeSound( void ) const { std::cout << "Meow!" << std::endl; }

Brain *Cat::getBrain( void ) { return (this->_brain); }