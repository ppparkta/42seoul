#pragma once
#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <deque>

class Span{
	private:
		std::vector<int> _v;
		unsigned int _n;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &span);
		Span& operator=(const Span &span);
		~Span();

		void addNumber(int n);
		void addNumbers(std::vector<long>::iterator begin, std::vector<long>::iterator end);
		long shortestSpan();
		long longestSpan();

		class FullSpanException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class NoMatchingException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

#endif