#include "ScalarConverter.hpp"

int ScalarConverter::_type = 0;

std::string ScalarConverter::_str = "";

const char *ScalarConverter::NoMatchingException::what() const throw()
{
	return "no matching type.";
}

bool ScalarConverter::checkChar()
{
	if (_str.size() == 1 && !std::isdigit(_str[0]) && std::isprint(_str[0]))
		return (true);
	return (false);
}

bool ScalarConverter::checkInt()
{
	int i = 0;
	if (_str.size() == 0)
		return (false);
	if (_str[i] == '+' || _str[i] == '-')
		i++;
	for (int j = i; j < _str.size(); j++)
	{
		if (!std::isdigit(_str[j]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::checkFloat()
{
	int i = 0;
	bool dot_flag = false;
	if (_str[_str.size() - 1] != 'f' || _str.find('.') == 0 || _str.find('.') == _str.size() - 2 || _str.find('.') == std::string::npos)
		return (false);
	if (_str[i] == '-' || _str[i] == '+')
		i++;
	for (int j = i; j < _str.size(); j++)
	{
		if (_str[j] == '.' && dot_flag)
			return (false);
		else if (_str[j] == '.' && !dot_flag)
			dot_flag = true;
		if (_str[j] != '.' && !std::isdigit(_str[j]) && (_str[j] == 'f' && j != _str.size() - 1))
			return (false);
	}
	return (true);
}

bool ScalarConverter::checkDouble()
{
	int i = 0;
	int dot_flag = 0;
	if (_str.find('.') == 0 || _str.find('.') == _str.size() - 1 || _str.find('.') == std::string::npos)
		return (false);
	if (_str[i] == '-' || _str[i] == '+')
		i++;
	for (int j = i; j < _str.size(); j++)
	{
		if (_str[j] == '.' && dot_flag)
			return (false);
		else if (_str[j] == '.' && !dot_flag)
			dot_flag++;
		if ((_str[j] != '.' && !std::isdigit(_str[j])) || dot_flag > 1)
			return (false);
	}
	return (true);
}

bool ScalarConverter::checkEx()
{
	if (_str == "nan" || _str == "nanf" || _str == "+inf" || _str == "-inf" || _str == "+inff" || _str == "-inff")
		return (true);
	return (false);
}

void ScalarConverter::checkType()
{
	if (checkChar())
		_type = CHAR;
	else if (checkInt())
		_type = INT;
	else if (checkFloat())
		_type = FLOAT;
	else if (checkDouble())
		_type = DOUBLE;
	else if (checkEx())
		_type = EX;
	else
		throw ScalarConverter::NoMatchingException();
}

void ScalarConverter::printChar(double value)
{
	std::cout << "char: ";
	char c_tmp = static_cast<char>(value);
	int range_check = static_cast<int>(c_tmp);
	if ((range_check > 255 || range_check < 0) || _type == EX)
		std::cout << "impossible";
	else if (std::isprint(range_check))
		std::cout << "'" << c_tmp << "' ";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}

void ScalarConverter::printInt(double value)
{
	std::cout << "int: ";
	try
	{
		double range_check = strtod(_str.c_str(), NULL);
		if (_type == EX || range_check < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < range_check)
			std::cout << "impossible";
		else if (_type == CHAR)
			std::cout << static_cast<int>(_str[0]);
		else
			std::cout << static_cast<int>(value);
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
}

void ScalarConverter::printFloat(double value)
{
	std::cout << "float: ";
	if (_str == "nan" || _str == "nanf" || std::isnan(value))
		std::cout << "nanf";
	else if (_str == "-inff" || _str == "-inf" || (std::isinf(value) && value < 0))
		std::cout << "-inff";
	else if (_str == "+inff" || _str == "+inf" || (std::isinf(value) && value > 0))
		std::cout << "+inff";
	else
		std::cout << std::setprecision(1) << std::fixed << static_cast<float>(value) << "f";
	std::cout << std::endl;
}

void ScalarConverter::printDouble(double value)
{
	std::cout << "double: ";
	if (_str == "nan" || _str == "nanf" || std::isnan(value))
		std::cout << "nan";
	else if (_str == "-inff" || _str == "-inf" || (std::isinf(value) && value < 0))
		std::cout << "-inf";
	else if (_str == "+inff" || _str == "+inf" || (std::isinf(value) && value > 0))
		std::cout << "+inf";
	else
		std::cout << std::setprecision(1) << std::fixed << static_cast<double>(value);
	std::cout << std::endl;
}

void ScalarConverter::printAll()
{
	double tmp = 0.0;

	try
	{
		if (_type == CHAR)
			tmp = static_cast<double>(_str[0]);
		else
			tmp = strtod(_str.c_str(), NULL);
		printChar(tmp);
		printInt(tmp);
		printFloat(tmp);
		printDouble(tmp);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
}

void ScalarConverter::convert(std::string str)
{
	_str = str;
	checkType();
	printAll();
}