#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain default constructor called" <<std::endl; }

Brain::~Brain() { std::cout << "Brain destructor called" <<std::endl; }

Brain::Brain( Brain &other ) : _ideas(other._ideas) {	std::cout << "Brain copy constructor called" <<std::endl; }

Brain &Brain::operator=( const Brain &other )
{
	if (this != &other)
		*this = other;
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
