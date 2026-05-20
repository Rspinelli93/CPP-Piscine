#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	delete(this->_brain);
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound( void ) const { std::cout << "Woof!" << std::endl; }

Dog::Dog(const Dog &other) : Animal(other) { std::cout << "Dog copy constructor called" << std::endl; }

Brain *Dog::getBrain( void ) { return (this->_brain); }
