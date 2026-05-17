#include "Cat.hpp"

Cat::Cat( std::string type ) : { std::cout << "Cat constructor called" << std::endl; }

void Cat::makeSound( void ) { std::cout << "Meow!" << std::endl; }