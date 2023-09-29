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
		int *_arr;
		unsigned int n;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &span);
		Span& operator=(const Span &span);
		~Span();
		void addNumber(unsigned int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void addManyNumber();
		class FullSpanException : public std::exception{
			public:
				virtual const char *what() const throw(){
					return "Span is full!";
				}
		};
		class NoMatchinException : public std::exception{
			public:
				virtual const char *what() const throw(){
					return "No matching elements!";
				}
		};
};

#endif