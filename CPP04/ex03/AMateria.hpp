#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria( void );
		virtual ~AMateria( void );
		AMateria( AMateria const &other );
		AMateria &operator=( AMateria const &other );
		AMateria(std::string const &type);
	
		std::string const &getType( void ) const; //Returns the materia type
		virtual AMateria *clone( void ) const = 0;
		virtual void use(ICharacter& target);
};

#endif