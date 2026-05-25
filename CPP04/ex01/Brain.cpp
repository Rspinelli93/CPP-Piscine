#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain default constructor called" <<std::endl; }

Brain::~Brain() { std::cout << "Brain destructor called" <<std::endl; }

Brain::Brain( Brain &other ) { *this = other; std::cout << "Brain copy constructor called" <<std::endl; }

Brain &Brain::operator=( const Brain &other )
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

void Brain::setIdea( std::string idea, int i )
{
	if (i < 100 && i >= 0)
		this->_ideas[i] = idea;
	else
		std::cout << "Animals can hold only 100 ideas" << std::endl;
}

std::string Brain::getIdea( int i )
{
	if (i < 100 && i >= 0)
		return (this->_ideas[i]);
	else
		std::cout << "Animals have only 100 ideas" << std::endl;
	return ("");
}
