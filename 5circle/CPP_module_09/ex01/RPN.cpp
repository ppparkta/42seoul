#include "RPN.hpp"

const char *RPN::InvalidArgumentException::what() const throw()
{
	return "error: Invaild arguments.";
}

const char *RPN::NoEnoughOperendsException::what() const throw(){
	return "error: No enough operends.";
}

const char *RPN::ZeroDivideException::what() const throw(){
	return "error: Zero divied.";
}

const char *RPN::IncompleteCalcException::what() const throw(){
	return "error: Incomplete calculation.";
}

RPN::RPN() {}

RPN::~RPN() {}

static bool check_opd(char arg)
{
	std::string opd = "0123456789";

	for (int j = 0; j < opd.length(); j++)
	{
		if (arg == opd[j])
			return true;
	}
	return false;
}

static bool check_opr(char arg, bool opd_check)
{
	std::string opr = "+-/*";

	for (int j = 0; j < opr.length(); j++)
	{
		if (opd_check)
			return false;
		if (arg == opr[j])
			return true;
	}
	return false;
}

void RPN::rpn_calc(std::string arg)
{

	std::stack<int> s;
	int opd1, opd2;

	for (int i = 0; i < arg.size(); i++)
	{
		char op = arg[i];
		if (op == ' ')
			continue;
		bool opd_check = check_opd(op);
		bool opr_check = check_opr(op, opd_check);

		if (!opd_check && !opr_check)
			throw InvalidArgumentException();

		if (opd_check)
			s.push(op - 48);
		else
		{
			if (s.size() < 2)
				throw NoEnoughOperendsException();
			if (op == '+'){
				opd2 = s.top();
				s.pop();
				opd1 = s.top();
				s.pop();
				s.push(opd1 + opd2);
			}
			else if (op == '-'){
				opd2 = s.top();
				s.pop();
				opd1 = s.top();
				s.pop();
				s.push(opd1 - opd2);
			}
			else if (op == '*'){
				opd2 = s.top();
				s.pop();
				opd1 = s.top();
				s.pop();
				s.push(opd1 * opd2);
			}
			else if (op == '/'){
				opd2 = s.top();
				s.pop();
				opd1 = s.top();
				s.pop();
				if (opd2 == 0)
					throw ZeroDivideException();
				s.push(opd1 / opd2);
			}
		}
	}
	if (s.size() != 1){
		throw IncompleteCalcException();
	}
	else {
		std::cout<< s.top() << std::endl;
		s.pop();
	}
}