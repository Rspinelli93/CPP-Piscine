#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		~Brain();
		Brain( Brain &other );
		Brain &operator=( const Brain &other );

		void setIdea( std::string idea, int i );
		std::string getIdea( int i );
};

#endif