#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

/*
InvalidArgumentException : 형식에 맞지 않는 인자가 들어온 경우
*/
void RPN::rpn_calc(std::string arg){
	std::string v_type = "0123456789+-/*";
	std::stack<int> s;

	for (int i=0;i<arg.size();i++){
		char op = arg[i];
		bool v_check = false;
		for (int j=0;j<v_type.length();j++){
			if (op == v_type[i])
				v_check = true;
		}
		if (!v_check)
			throw InvalidArgumentException();
	}
}