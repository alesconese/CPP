#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return ((std::cout << "(!) ERROR: Invalid input argument.\n"), 1);
	
	std::ifstream	ifs;

	ifs.open(argv[1]);
	if (ifs.fail())
		return ((std::cout << "(!) ERROR: Unable to open input file.\n"), 1);

	std::string	line;
	
	std::getline(ifs, line);
	if (line != "date | value")
		return ((std::cout << "(!) ERROR: Invalid input file format.\n"), 1);

	try
	{
		BitcoinExchange	exchange;

		while (std::getline(ifs, line))
		{
			//std::cout << "line: " << line << std::endl;
			try
			{
				//1: check format == date | value
				if (line.find(" | ") == std::string::npos)
					throw std::invalid_argument("bad input => " + line);

				std::string	date_str = line.substr(0, line.find(" | "));
				std::string	btc_str = line.substr(line.find(" | ") + 3);
				if (date_str.empty() || btc_str.empty())
					throw std::invalid_argument("bad input => " + line);

				//2: check date format == yyyy-mm-dd
				struct tm	tm;
				if (!strptime(date_str.c_str(), "%Y-%m-%d", &tm) || !exchange.checkValidDate(tm))
					throw std::invalid_argument("invalid date => " + date_str);

				//3: check value == number && 0 <= value <= 1000
				char	*endptr;
				float	btc = std::strtof(btc_str.c_str(), &endptr);
				if (*endptr != '\0')
					throw std::invalid_argument("bad input => " + line);
				if (btc < 0)
					throw std::invalid_argument("not a positive number");
				if (btc > 1000)
					throw std::invalid_argument("too large a number");
				
				//4: get total value
				float	value = btc * exchange.getValue(date_str);

				//5: print result
				std::cout << date_str << " => " << btc << " = " << value << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << "(!) ERROR: " << e.what() << '\n';
			}
		}
		ifs.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << "(!) ERROR: " << e.what() << '\n';
	}

	return 0;
}
