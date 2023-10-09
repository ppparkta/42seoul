#pragma once
#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange{
	private:
		std::map<long, double> data;
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &bit);
		BitcoinExchange &operator=(const BitcoinExchange &bit);

	public:
		BitcoinExchange(const std::string data);
		~BitcoinExchange();

		void exchange(const std::string input);
		void printData();
		
		class NoOpenFileException : public std::exception{
			public:
				virtual const char *what() const throw ();
		};
		class InvalidFileException : public std::exception{
			public:
				virtual const char *what() const throw ();
		};
		
};

#endif