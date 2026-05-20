#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;
	public:
		Cat();
		~Cat();
		Cat( Cat &other );
		void makeSound( void ) const;
		Brain *getBrain( void );
};

#endif