#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <sstream>

class ScalarConverter {
	private:
		static std::string _str;
		static int _type;

		ScalarConverter();
		ScalarConverter(const ScalarConverter &scalar);
		ScalarConverter &operator=(const ScalarConverter &scalar);
		~ScalarConverter();

	public:
		static void convert(std::string target);
};

#endif