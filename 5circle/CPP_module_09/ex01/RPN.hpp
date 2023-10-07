#pragma once
#ifndef __RPN_CPP__
#define __RPN_CPP__

#include <iostream>
#include <exception>
#include <string>
#include <stack>

class RPN {
	private:
		RPN(const RPN &rpn);
		RPN& operator=(const RPN &rpn);
	public:
		RPN();
		~RPN();
		static void rpn_calc(std::string arg);
};

#endif