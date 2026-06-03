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

	void addNumber(int n);
	int shortestSpan(void);
	int longestSpan(void);

	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		if (_nums.size() + (unsigned int)std::distance(begin, end) > _N)
			throw overflowException();
		_nums.insert(_nums.end(), begin, end);
	}

	class overflowException : public std::exception {
		virtual const char *what() const throw();
	};
	class unpopulatedException : public std::exception {
		virtual const char *what() const throw();
	};
};

#endif