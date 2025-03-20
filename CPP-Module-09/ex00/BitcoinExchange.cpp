#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "* BitcoinExchange default constructor called." << std::endl;
	
	loadData();
}
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "* BitcoinExchange destructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	std::cout << "* BitcoinExchange copy constructor called." << std::endl;
	*this = src;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &src)
{
	std::cout << "* BitcoinExchange copy assignment operator called" << std::endl;
	if (this != &src)
		_historic = src._historic;
	
	return *this;
}

void	BitcoinExchange::loadData()
{
	std::ifstream	data_file;
	std::string		date;
	std::string		value;

	data_file.open("data.csv");
	if (data_file.fail())
		throw std::runtime_error("unable to open data file.");

	std::getline(data_file, date);
	if (date != "date,exchange_rate")
		throw std::runtime_error("invalid data file format.");
	
	while (std::getline(data_file, date))
	{
		value = date.substr(date.find(',') + 1);
		date = date.substr(0, date.find(','));
		//std::cout << "[read] date: " << date << " value: " << value << std::endl;

		//verify correct date and value format.
		_historic[date] = std::atof(value.c_str());
	}
	data_file.close();
}

bool	BitcoinExchange::checkValidDate(const tm &tm)
{
	switch (tm.tm_mon)
	{
		case 0:
		case 2:
		case 4:
		case 6:
		case 7:
		case 9:
		case 11:
			return (tm.tm_mday <= 31);
		case 3:
		case 5:
		case 8:
		case 10:
			return (tm.tm_mday <= 30);
		case 1:
			if (((tm.tm_year + 1900) % 4 == 0 && (tm.tm_year + 1900) % 100 != 0) \
				|| (tm.tm_year + 1900) % 400 == 0)
				return (tm.tm_mday <= 29);
			else
				return (tm.tm_mday <= 28);
		default:
			return (false);
	}
}

float	BitcoinExchange::getValue(std::string const &date)
{
	if (date < _historic.begin()->first)
		return (0);

	std::map<std::string, float>::iterator	it;

	it = _historic.find(date);
	if (it == _historic.end())
	{
		it = _historic.lower_bound(date);
		it--;
	}
	std::cout << it->first << std::endl;
	return (it->second);
}
