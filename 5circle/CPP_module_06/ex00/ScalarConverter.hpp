#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>
#include <string>
#include <limits>
#include <climits>

class ScalarConverter {
	private:

	public:
		ScalarConverter();
		ScalarConverter(std::string lit);
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &assign);
		~ScalarConverter();
};

#endif