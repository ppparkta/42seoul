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
	if (this->_v.size() >= this->_n)
		throw FullSpanException();
	this->_v.push_back(n);
}

void Span::addManyNumbers(unsigned int n)
{
	srand(time(NULL));
	int tmp;
	for (unsigned int i = 0; i < n; i++)
	{
		tmp = rand() % 999;
		this->addNumber(tmp);
	}
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator i = begin; i < end; i++)
	{
		this->addNumber(*i);
	}
}

static int minus(int a, int b)
{
	return (a - b);
}

int Span::shortestSpan()
{
	if (_v.empty() || _v.size() < 2)
		throw NoMatchingException();
	std::vector<int> temp(this->_v.size());
	std::copy(this->_v.begin(), this->_v.end(), temp.begin());
	std::sort(temp.begin(), temp.end());
	std::transform(temp.begin() + 1, temp.end(), temp.begin(), temp.begin(), minus);
	std::sort(temp.begin(), temp.end());
	return (*temp.begin());
}

int Span::longestSpan()
{
	if (_v.empty() || _v.size() < 2)
		throw NoMatchingException();
	std::vector<int>::iterator min = std::min_element(this->_v.begin(), this->_v.end());
	std::vector<int>::iterator max = std::max_element(this->_v.begin(), this->_v.end());
	return (*max - *min);
}
