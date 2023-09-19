#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &scalar) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalar) {}

static bool checkString(std::string target)
{
	if (target[0] == '-' || target[0] == '+')
		target.erase(0, 1);
	std::string check[4] = {"nan", "nanf", "inf", "inff"};
	for (int i = 0; i < 4; i++)
	{
		if (target == check[i])
			return (true);
	}
	if (target[target.size() - 1] == 'f' || target[target.size() - 1] == 'F')
		target.erase(target.size() - 1, 1);
	bool dot = false;
	for (std::string::iterator cur = target.begin(); cur != target.end(); cur++)
	{
		if (!std::isdigit(*cur))
		{
			if (cur == target.begin() && (*cur == '-' || *cur == '+'))
				continue;
			if ((cur == target.begin() || cur == target.end() - 1) && *cur == '.')
				return (false);
			else if ((std::isdigit(*(cur - 1)) == false || std::isdigit(*(cur + 1)) == false) && *cur == '.')
				return (false);
			else if (*cur == '.' && dot == false)
				dot = true;
			else
				return (false);
		}
	}
	return (true);
}

static void StringToChar(std::string target){

}

static void StringToInt(std::string target){

}

static void StringToFloat(std::string target){
	
}

static void StringToDouble(std::string target){
	
}

static void convertChar(char target)
{
	if (std::isprint(target))
		std::cout<<"char: "<<target<<std::endl;
	else
		std::cout<<"char: Non displayable"<<std::endl;
	std::cout << "int: " << static_cast<int>(target) << std::endl;
	std::cout << std::fixed << "float: " << std::setprecision(1) << static_cast<float>(target) << 'f' << std::endl;
	std::cout << std::fixed << "double: " << std::setprecision(1) << static_cast<double>(target) << std::endl;
}

static void convertString(std::string target)
{

}

void ScalarConverter::convert(std::string target)
{
	if (target.size() == 0)
		std::cerr << "" << std::endl;
	else if (target.size() == 1 && !std::isdigit(target[0]))
		convertChar(target[0]);
	else
	{
		if (checkString(target) == false)
			std::cerr << "exception: invalid string" << std::endl;
		else
			convertString(target);
	}
}