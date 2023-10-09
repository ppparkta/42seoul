#include "BitcoinExchange.hpp"

const char *BitcoinExchange::NoOpenFileException::what() const throw()
{
	return "Error: could not open file.";
}

const char *BitcoinExchange::InvalidFileException::what() const throw()
{
	return "Error: Invalid file format.";
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const std::string data)
{
	std::fstream database(data);
	if (!database.is_open())
		throw BitcoinExchange::NoOpenFileException();
	std::string line;
	database >> line;
	if (line != "date,exchange_rate")
		throw BitcoinExchange::InvalidFileException();
	while (database >> line)
	{
		long date = 0L;
		int year, month, day;
		double rate = 0.;
		double div = 1.;
		bool before = true, afterBit = false;
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ',' && before)
				before = false;
			else if (line[i] == ',' && !before)
				throw BitcoinExchange::InvalidFileException();
			else if (before)
			{
				if (line[i] == '-')
					continue;
				date = (date << 1) + (date << 3) + (line[i] - '0');
			}
			else
			{
				if (line[i] == '.')
				{
					afterBit = true;
					continue;
				}
				if (!afterBit)
				{
					rate = 10 * rate + (line[i] - '0');
				}
				else
				{
					rate += (line[i] - '0') / (div *= 10);
				}
			}
		}
		if (before)
			throw BitcoinExchange::InvalidFileException();
		this->data[date] = rate;
	}
	database.close();
}

void BitcoinExchange::printData(){
	for (std::map<long, double>::iterator itr = this->data.begin(); itr != this->data.end(); ++itr) {
        std::cout << itr->first << " " << itr->second << std::endl;
    }
}