#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <iomanip>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &scalar);
		ScalarConverter &operator=(const ScalarConverter &scalar);
		~ScalarConverter();
	public:
		static void convert(std::string target);
		
};

#endif