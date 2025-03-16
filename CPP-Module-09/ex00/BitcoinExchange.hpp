#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>

class	BitcoinExchange
{
	private:
			std::map<std::string, float>	_rate;

	public:
			BitcoinExchange();
			~BitcoinExchange();
			BitcoinExchange(BitcoinExchange const &src);
			BitcoinExchange	&operator=(BitcoinExchange const &src);
};

#endif
