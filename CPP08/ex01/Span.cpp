#include "Span.hpp"

//---------------- Cannon -----------------

Span::Span() : _num(NULL), _N(0), _P(0) {}

Span::~Span()
{
	delete _num;
	this->_num = NULL;
}

Span::Span(unsigned int N) : _num(new int[N]), _N(N), _P(0) {}

Span::Span(Span const &other) : _num(new int[other._N]), _N(other._N), _P(other._P)
{
	for (int i = 0; i < (int)this->_N; i++)
	{
		this->_num[i] = other._num[i];
	}
}

//---------------- Operators -----------------

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		delete this->_num;
		this->_N = other._N;
		this->_P = other._P;
		this->_num = new int[this->_N];
		for (int i = 0; i < (int)this->_N; i++)
		{
			this->_num[i] = other._num[i];
		}
	}
	return (*this);
}

int &Span::operator[](unsigned int ix)
{
	if (ix >= this->_N)
		throw Span::outOfBoundsException();
	else
		return (this->_num[ix]);
}

const int &Span::operator[](unsigned int ix) const
{
	if (ix >= this->_N)
		throw Span::outOfBoundsException();
	else
		return (this->_num[ix]);
}

//---------------- Span member functions -----------------

void Span::addNumber(int n)
{
	if (_P >= _N)
		throw Span::overflowException();
	_num[_P++] = n;
}

int Span::shortestSpan(void)
{
    if (this->_P < 2)
        throw unpopulatedException();
	else
	{
		Span temp(*this);
		std::sort(temp._num, temp._num + temp._P);
		int span = __INT_MAX__;
		for (int i = 0; i + 1 < (int)_P; i++)
		{
			int diff = temp._num[i + 1] - temp._num[i];
			if (diff < span)
				span = diff;
		}
		return span;
	}
	return (-1);
}

int Span::longestSpan(void)
{
	if (_P < 2)
		throw unpopulatedException();
	else
	{
		Span temp(*this);
	
		std::sort(temp._num, temp._num + temp._P);
		return (temp._num[_P - 1] - temp._num[0]);
	}
	return (-1);
}

//---------------- Exceptions -----------------

const char *Span::unpopulatedException::what() const throw() { return ("Span: Not enough numbers"); }

const char *Span::outOfBoundsException::what() const throw() { return ("Span: Out of bounds"); }

const char *Span::overflowException::what() const throw() { return ("Span: Overflow"); }
