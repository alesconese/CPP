#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "* BitcoinExchange default constructor called." << std::endl;
	
	std::ifstream	data_file;

	data_file.open("data.csv");
	if (data_file.fail())
	{
		std::cout << "(!) ERROR: Unable to open data file.\n";
		return;
	}

	std::string	line;

	std::getline(data_file, line);
	if (line != "date,exchange_rate")
	{
		std::cout << "(!) ERROR: Invalid data file format.\n";
		return ;
	}
	
	while (!data_file.eof())
	{
		std::getline(data_file, line, ',');
	}
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
		_rate = src._rate;
	
	return *this;
}