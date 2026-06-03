
#include "Span.hpp"

//---------------- ORTHODOX ----------------
Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(Span const &other) : _nums(other._nums), _N(other._N) {}

Span::~Span() {}

Span &Span::operator=(Span const &other)
{
    if (this != &other)
    {
        _nums = other._nums;
        _N = other._N;
    }
    return *this;
}

//---------------- OPERATIONS ----------------

void Span::addNumber(int n)
{
    if (_nums.size() >= _N)
        throw overflowException();
    _nums.push_back(n);
}

int Span::shortestSpan(void)
{
    if (_nums.size() < 2)
        throw unpopulatedException();

    std::vector<int> temp(_nums);
    std::sort(temp.begin(), temp.end());

    int span = INT_MAX;
    for (size_t i = 0; i + 1 < temp.size(); i++)
        span = std::min(span, temp[i + 1] - temp[i]);
    return span;
}

int Span::longestSpan(void)
{
    if (_nums.size() < 2)
        throw unpopulatedException();
    return *std::max_element(_nums.begin(), _nums.end())
         - *std::min_element(_nums.begin(), _nums.end());
}

//---------------- EXCEPTIONS ----------------

const char *Span::overflowException::what() const throw() { return "Span: container full"; }

const char *Span::unpopulatedException::what() const throw() { return "Span: not enough numbers"; }