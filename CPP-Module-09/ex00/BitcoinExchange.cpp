#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "* BitcoinExchange default constructor called." << std::endl;
	

}
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "* BitcoinExchange destructor called." << std::endl;
}

			BitcoinExchange(BitcoinExchange const &src);
			BitcoinExchange	&operator=(BitcoinExchange const &src);