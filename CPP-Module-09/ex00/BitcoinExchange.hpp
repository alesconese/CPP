#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <cstdlib>

class	BitcoinExchange
{
	private:
			std::map<std::string, float>	_historic;

			void	loadData();

	public:
			BitcoinExchange();
			~BitcoinExchange();
			BitcoinExchange(BitcoinExchange const &src);
			BitcoinExchange	&operator=(BitcoinExchange const &src);

			float	getValue(std::string const &date);
			bool	checkValidDate(const tm &tm);
			void	verifyData(std::string line, std::string &date, float &btc, std::string const &separator);
};

#endif
