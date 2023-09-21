#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <exception>

enum
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	EX
};

class ScalarConverter
{
	private:
		static std::string _str;
		static int _type;

		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &scalar);
		ScalarConverter &operator=(const ScalarConverter &scalar);

		static bool checkChar();
		static bool checkInt();
		static bool checkFloat();
		static bool checkDouble();
		static bool checkEx();
		static void checkType();

		static void printChar(double value);
		static void printInt(double value);
		static void printFloat(double value);
		static void printDouble(double value);
		static void printAll();

	public:
		static void convert(std::string target);
		class NoMatchingException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif