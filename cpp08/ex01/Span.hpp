#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
	unsigned int _n;
	std::vector<int> _arr;
public:
	Span(unsigned int n);
	Span(const Span &span);
	~Span();
	Span &operator=(const Span &span);
	void addNumber(int n);
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();
};

#endif