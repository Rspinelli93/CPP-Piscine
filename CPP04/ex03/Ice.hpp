#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		std::string _name;
	public:
		Ice( void );
		Ice *clone( void ) const;
		std::string getName( void ) const;
		void setName( std::string const name );
};

#endif