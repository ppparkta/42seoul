#pragma once
#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
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
		BitcoinExchange(const std::string &bit);
		~BitcoinExchange();

		void exchange(const std::string &input);
};

#endif