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
		virtual ~Animal();
		Animal( std::string type );
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);

		virtual void makeSound( void ) const;
		std::string getType( void ) const;
};

#endif