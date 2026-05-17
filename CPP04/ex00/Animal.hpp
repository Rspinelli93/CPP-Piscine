#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		~Animal();
		Animal( std::string type );
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		void virtual makeSound( void );
		std::string getType( void );
};

#endif