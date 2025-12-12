#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
	std::cout << "Constructor called" << std::endl;
}

Span::Span(const Span &span) : _n(span._n), _arr(span._arr)
{
	std::cout << "Copy constructor called" << std::endl;
}

Span::~Span()
{
	std::cout << "Destructor called" << std::endl;
}

Span &Span::operator=(const Span &span)
{
	if (this == &span)
		return *this;
	_n = span._n;
	_arr = span._arr;
	return *this;
}

void Span::addNumber(int n)
{
	if (_arr.size() >= _n)
		throw std::exception();
	_arr.push_back(n);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) + _arr.size() > _n)
		throw std::exception();
	_arr.insert(_arr.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_arr.size() <= 1)
		throw std::exception();
	std::sort(_arr.begin(), _arr.end());
	int min = _arr[1] - _arr[0];
	for (unsigned int i = 2; i < _arr.size(); i++)
	{
		int diff = _arr[i] - _arr[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan()
{
	if (_arr.size() <= 1)
		throw std::exception();
	return _arr.back() - _arr.front();
}