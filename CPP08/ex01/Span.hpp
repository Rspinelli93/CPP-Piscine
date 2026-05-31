#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>

typedef struct twoInt
{
	int	i;
	int j;
} twoInt;

class Span
{
	private:
		int				*_num;
		unsigned int	_N;
		unsigned int	_P;
	public:
		Span();
		~Span();
		Span( unsigned int N );
		Span( Span const &other );
		Span &operator=( Span const &other );
		int	&operator[]( unsigned int ix );
		const int &operator[]( unsigned int ix ) const;
		class outOfBoundsException : public std::exception
		{
			virtual const char *what() const throw();
		};

		void addNumber( int n );
		class overflowException : public std::exception
		{
			virtual const char *what() const throw();
		};

		int shortestSpan( void );
		int longestSpan( void );
		class unpopulatedException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif