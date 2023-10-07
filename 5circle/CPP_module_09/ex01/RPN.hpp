#pragma once
#ifndef __RPN_CPP__
#define __RPN_CPP__

#include <iostream>
#include <exception>
#include <string>
#include <stack>

class RPN {
	private:
		RPN();
		RPN(const RPN &rpn);
		RPN& operator=(const RPN &rpn);
		~RPN();
	public:
		static void rpn_calc(std::string arg);
		class InvalidArgumentException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class NoEnoughOperendsException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class ZeroDivideException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class IncompleteCalcException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

#endif