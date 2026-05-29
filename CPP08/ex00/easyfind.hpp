#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <string>

class notFoundExc : public std::exception
{
	public:
		const char* what() const throw() { return ("Not Found"); }
};

//* An iterator is an object that behaves like a pointer to traverse and access elements of a container.
template <typename T>
int easyfind(T container, int num)
{
    typename T::iterator it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
        throw notFoundExc();
    return *it;
}

#endif