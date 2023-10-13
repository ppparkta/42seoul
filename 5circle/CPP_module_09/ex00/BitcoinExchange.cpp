#include "BitcoinExchange.hpp"

const char *BitcoinExchange::NoOpenFileException::what() const throw()
{
	return "Error: could not open file.";
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string data)
{
	std::fstream database(data);
	if (!database.is_open())
		throw BitcoinExchange::NoOpenFileException();
	std::string line;
	database >> line;
	if (line != "date,exchange_rate")
		throw BitcoinExchange::NoOpenFileException();
	while (database >> line)
	{
		long date = 0;
		double rate = 0, div = 1;
		bool before = true, afterBit = false;
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ',' && before)
				before = false;
			else if (line[i] == ',' && !before)
				throw BitcoinExchange::NoOpenFileException();
			else if (before)
			{
				if (line[i] == '-')
					continue;
				date = date * 10 + (line[i] - '0');
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
					rate = rate * 10 + (line[i] - '0');
				}
				else
				{
					div = div * 10;
					rate += (line[i] - '0') / div;
				}
			}
		}
		if (before)
			throw BitcoinExchange::NoOpenFileException();
		this->data[date] = rate;
	}
	database.close();
}

static bool check_valid_date(long year, long month, long day)
{
	const long days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year < 2009 || year > 2023) || (month > 12 || month < 1) ||
		(day < 1 || day > days[month] + (year % 4 == 0 && month == 2 ? 1 : 0)))
	{
		return false;
	}
	return true;
}

static int check_valid_value(double value)
{
	if (value < 0)
		return 1;
	if (value > 1000)
		return 2;
	return 0;
}

void BitcoinExchange::exchange(const std::string input)
{
	std::fstream data(input);
	if (!data.is_open())
		throw BitcoinExchange::NoOpenFileException();
	std::string line;
	std::getline(data, line);
	if (line != "date | value")
		throw std::invalid_argument("Error: bad input => " + line);
	while (std::getline(data, line))
	{
		long year = 0, month = 0, day = 0;
		long before = 0, after = 0, afterDot = 0, inv_d = 0, inv_v = 0, positive = 0;
		double value = 0., div = 1.;
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ' ')
				continue;
			else if (line[i] == '|' && ++after)
			{
				continue;
			}
			else if (!after)
			{
				if (std::isdigit(line[i]))
				{
					if (before == 0)
						year = year * 10 + (line[i] - '0');
					else if (before == 1)
						month = month * 10 + (line[i] - '0');
					else if (before == 2)
						day = day * 10 + (line[i] - '0');
					else
						break;
				}
				else if (line[i] == '-')
					before++;
				else
				{
					inv_d++;
					break;
				}
			}
			else
			{
				if (!afterDot && !value && line[i] == '-')
				{
					positive++;
					continue;
				}
				if (std::isdigit(line[i]))
				{
					if (!afterDot)
						value = value * 10 + (line[i] - '0');
					else
					{
						div *= 10;
						value += (line[i] - '0') / (div);
					}
				}
				else if (line[i] == '.')
					afterDot++;
				else
				{
					inv_v++;
					break;
				}
			}
		}
		if (positive % 2 != 0)
			value *= -1;
		if (!check_valid_date(year, month, day))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (check_valid_value(value))
		{
			if (check_valid_value(value) == 1)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (check_valid_value(value) == 2)
				std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		long date = year * 10000 + month * 100 + day;
		if (this->data.begin()->first > date)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::map<long, double>::iterator cursor = --this->data.upper_bound(date);
		std::cout << year << '-' << (month < 10 ? "0" : "") << month << '-' << (day < 10 ? "0" : "") << day << " => " << value << " = " << (cursor->second * value) << std::endl;
	}
}
