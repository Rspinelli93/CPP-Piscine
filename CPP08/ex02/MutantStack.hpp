#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <stack>

//*Container is not an object inside the template, it's a type parameter with a default value. 
//*In construction will inherit a deque of type T.

template <typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){}
		~MutantStack(){}
		MutantStack(const MutantStack &stack)
		{
			*this = stack;
		}
		typedef typename container::iterator iterator;
		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
};

/*
* std::stack inherits from std::deque, who it has member functions like begin() and end()
* The reason we cannot use them in std::stack is merely design choise, stacks are designed
* to be LIFO, so they block those fucntions on purpose.
* I chose deque to be able to declare the iterator with those functions.
*/

#endif