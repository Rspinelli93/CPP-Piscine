#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <climits>
# include <iterator>

class Span
{
	private:
		std::vector<int>	_nums;
		unsigned int		_N;

	public:
		Span();
		Span(unsigned int N);
		Span(Span const &other);
		~Span();
		Span &operator=(Span const &other);

		/// @brief Adds a single number to the container, if the container it full, it will throw overflowException()
		/// @param n The number to add
		void addNumber(int n);

		/// @brief It finds the shortest span between all the numbers by generating a copy of the member _nums, sorting it and comparing the values in order. Throws and exception if the span contains less than 2 numbers.
		/// @return Returns an int representing the shortest distance between 2 numbers of the span
		int shortestSpan(void);

		/// @brief It finds the longest span between all using std::max_element and std::min_element. Throws and exception if the span contains less than 2 numbers.
		/// @return Returns an int representing the longest distance between 2 numbers of the span
		int longestSpan(void);

		/// @brief Adds numbers from begin till end. If the amount of numbers are overflowing the container, it will throw overflowException()
		/// @tparam Iterator The iterator passed as param
		/// @param begin The position pointed by the first iterator, hence the begning point of insetion
		/// @param end The position pointed by the second iterator, hence the end point of insetion
		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			if (_nums.size() + (unsigned int)std::distance(begin, end) > _N)
				throw overflowException();
			_nums.insert(_nums.end(), begin, end);
		}

		/// @brief Exception thrown when user wants to add numbers to a fully filled container
		class overflowException : public std::exception
		{
			virtual const char *what() const throw();
		};

		/// @brief Exception thrown in functions that need at least 2 numbers in the container
		class unpopulatedException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif