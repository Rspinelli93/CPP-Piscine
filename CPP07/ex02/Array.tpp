#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(new T[0]), _size(0) { };

template <typename T>
Array<T>::Array( unsigned int n ) : _arr(new T[n]), _size(n) { }

template <typename T>
Array<T>::~Array() { delete[] this->_arr; }

template <typename T>
Array<T>::Array( Array const &other )
{
	unsigned int n = other.size();
	this->_arr = new T[n];

	for (unsigned int i = 0; i < n; i++)
		this->_arr[i] = other._arr[i];
	this->_size = n;
}

template <typename T>
Array<T> &Array<T>::operator=( Array const &other )
{
	if (this != &other)
	{
		delete[] this->_arr;
		unsigned int n = other.size();
		this->_arr = new T[n];

		for (int i = 0; i < n; i++)
			this->_arr[i] = other._arr[i];
		this->_size = n;
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[]( int index ) const 
{
	int s = this->_size;

	if ( index < 0 || index >= s )
		throw Array<T>::OutOfBounds();
	return (this->_arr[index]);
}

template <typename T>
int	Array<T>::size( void ) const { return ( this->_size ); }

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw() { return ("Out of bounds"); }