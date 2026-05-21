#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "Character.hpp"

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria( void );								//Inherited
		virtual ~AMateria( void );						//Inherited
		AMateria( AMateria const &other );
		AMateria &operator=( AMateria const &other );
		AMateria(std::string const &type);
	
		std::string const &getType( void ) const;
		virtual AMateria *clone( void ) const = 0;
		virtual void use(ICharacter& target);
};

#endif