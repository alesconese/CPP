/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:58:30 by ade-tole          #+#    #+#             */
/*   Updated: 2024/12/05 18:58:32 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "* ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "* ScalarConverter destructor called: " << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	std::cout << "* ScalarConverter copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	std::cout << "* ScalarConverter copy assignment constructor called" << std::endl;
	(void)src;
	return *this;
}

void	convertSpecial(std::string input) //done
{
	(void)input;
	std::cout << "Input is special.\n";
}

void	convertChar(std::string input) //done
{
	(void)input;
	std::cout << "Input is char.\n";
}

void	convertInt(std::string input)
{
	(void)input;
	std::cout << "Input is int.\n";
}

void	convertFloat(std::string input)
{
	(void)input;
	std::cout << "Input is float.\n";
}

void	convertDouble(std::string input)
{
	(void)input;
	std::cout << "Input is double.\n";
}

void	checkNumbers(std::string input)
{
	bool	dot = false;
	bool	f = false;
	bool	error = false;

	for (std::string::iterator it = input.begin(); it != input.end(); it++)
	{
		if (!isdigit(*it))
		{
			if (it == input.begin() && *it == '-')
				continue;
			else if (it == input.end()-1 && *it == 'f')
			{
				f = true;
				//continue;
			}
			else if (it != input.begin() && it != input.end()-1 && *it == '.' && isdigit(*(it+1)))
			{
				if (!dot)
					dot = true;
				else
					error = true;
			}
			else
				error = true;
		}
	}

	if (error)
		std::cout << "(!) Wrong argument!\n";
	else if (f)
		convertFloat(input);
	else if (dot)
		convertDouble(input);
	else
		convertInt(input);
}

void	ScalarConverter::convert(std::string input)
{
	if (input == "-inff" || input == "+inff" || input == "-inf" || input == "+inf" || input == "nan")
		convertSpecial(input);
	else if (input.size() == 1 && !isdigit(input[0]))
		convertChar(input);
	else
		checkNumbers(input);
	
	/* char	char_v = 0;
	int 	int_v = 0;
	float	float_v = 0;
	double	double_v = 0;

	if (input == "")
	if (input.size() == 1 && !isdigit(input[0]))
	{
		if (!isprint(input[0]))
			std::cout << "(!) Non-displayable characters not supported." << std::endl;
		std::cout << "Input is char.\n";
		char_v = input[0];
		int_v = static_cast<int>(char_v);
		float_v = static_cast<float>(input[0]);
		double_v = static_cast<double>(char_v);
	}

	else if ()


	std::cout << "char: '" << char_v << "'" << std::endl;
	std::cout << "int: " << int_v << std::endl;
	std::cout << "float: " << float_v << "f" << std::endl;
	std::cout << "double: " << double_v << std::endl; */
}
