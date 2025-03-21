/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:31:00 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/21 19:31:02 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(std::string input)
{
	std::cout << "* RPN constructor called." << std::endl;

	this->loadInput(input);
}

RPN::RPN(RPN const &src)
{
	std::cout << "* RPN copy constructor called" << std::endl;

	*this = src;
}

RPN::~RPN()
{
	std::cout << "* RPN destructor called." << std::endl;
}

RPN &RPN::operator=(RPN const &src)
{
	std::cout << "* RPN copy assignment operator called" << std::endl;

	if(this != &src)
		_tokens = src._tokens;

	return *this;
}

void	RPN::loadInput(std::string input)
{
	std::string	valid_tokens = "0123456789+-*/";

	for (std::string::iterator it = input.end() - 1; it > input.begin(); --it)
	{
		if (valid_tokens.find(*it) != std::string::npos && isspace(*(it - 1)))
			_tokens.push(*it);
		else if (isspace(*it))
			continue;
		else
			throw std::invalid_argument("invalid characters in input");
	}
}