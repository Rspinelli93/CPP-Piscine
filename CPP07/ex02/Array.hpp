#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
	private:
		T				*_arr;
		unsigned int	_size;
	public:
	Array();
	Array( unsigned int n );
	~Array();
	Array( Array const &other );
	Array &operator=( Array const &other );
	
	T &operator[]( unsigned int index );
	const T &operator[]( unsigned int index ) const;

	int	size( void ) const;

	class OutOfBounds : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

#include "Array.tpp"

#endif