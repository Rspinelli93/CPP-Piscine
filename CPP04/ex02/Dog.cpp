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

Dog &Dog::operator=(const Dog &other) 
{
	if (this != &other)
	{
		this->_type = other._type;
		this->_brain = other._brain;
	}
	return ( *this );
}

Dog::Dog( Dog &other) : Animal(other)
{
	Brain *New = new Brain();
	*New = *other.getBrain();
	this->_brain = New;
	std::cout << "Dog copy constructor called" << std::endl;
}

Brain *Dog::getBrain( void ) { return (this->_brain); }
