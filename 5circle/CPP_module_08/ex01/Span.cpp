#include "Span.hpp"

const char *Span::FullSpanException::what() const throw()
{
	return "Span is full!";
}

const char *Span::NoMatchingException::what() const throw()
{
	return "No matching elements!";
}

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &span)
{
	this->_n = span._n;
	this->_v = span._v;
	*this = span;
}

Span &Span::operator=(const Span &span)
{
	if (&span != this)
	{
		this->_n = span._n;
		this->_v = span._v;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
}

int Span::shortestSpan()
{
	return ();
}

int Span::longestSpan()
{
	return ();
}
