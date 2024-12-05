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

void	ScalarConverter::convert(std::string input)
{
	char	char_v = 0;
	int 	int_v = 0;
	float	float_v = 0;
	double	double_v = 0;

	if (input.size() == 1 && !isdigit(input[0]))
	{
		if (!isprint(input[0]))
			std::cout << "(!) Non-displayable characters not supported." << std::cout;
		std::cout << "Input is char.\n";
		char_v = input[0];
		int_v = static_cast<int>(char_v);
		float_v = static_cast<float>(input[0]);
		double_v = static_cast<double>(char_v);
	}

	std::cout << "char: '" << char_v << "'" << std::endl;
	std::cout << "int: " << int_v << std::endl;
	std::cout << "float: " << float_v << "f" << std::endl;
	std::cout << "double: " << double_v << std::endl;
}
