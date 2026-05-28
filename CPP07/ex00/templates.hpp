#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

#include <iostream>

template <typename Type> void swap( Type &a, Type &b)
{
	Type temp = a;
	a = b;
	b = temp;
}

template <typename Type> Type min( Type a, Type b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename Type> Type max( Type a, Type b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif