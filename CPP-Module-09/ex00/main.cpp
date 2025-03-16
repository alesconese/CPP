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
	
	//EDGE CASE: 	correct header but not even 1 correct line -> return without
	//				constructing exchange object.

	BitcoinExchange	exchange;

	while (std::getline(ifs, line))
		std::cout << "line found: " << line << std::endl;

	return 0;
}
