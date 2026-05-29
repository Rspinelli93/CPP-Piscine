#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename Type> void print(Type t)
{
	std::cout << t << std::endl;
}

template <typename Type> void printconst(const Type t)
{
	std::cout << t << std::endl;
}

template <typename Type, typename f> void iter(Type Array[], const int len, f funct)
{
	for (int i = 0; i < len; i++)
		funct(Array[i]);
}

#endif