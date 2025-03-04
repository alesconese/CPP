/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:02:01 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/04 18:02:02 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _N(0)
{
	std::cout << "* Span default constructor called. Capacity: 0" << std::endl;
}

Span::Span(unsigned int N): _N(N)
{
	std::cout << "* Span constructor called. Capacity: " << _N << std::endl;
}

Span::~Span()
{
	std::cout << "* Span default destructor called" << std::endl;
}

Span::Span(Span const &src): _N(src._N)
{
	std::cout << "* Span copy constructor called" << std::endl;
	*this = src;
}

Span &Span::operator=(Span const &src)
{
	std::cout << "* Span copy assignment operator called" << std::endl;
	if (this != &src)
	{
		_N = src._N;
		_numbers = src._numbers;
	}
	return *this;
}

void	Span::addNumber(int num)
{
	if (_numbers.size() == _N)
		throw MaxCapacityException();
	_numbers.push_back(num);
	std::cout << "* Number added to container: " << num << std::endl;
}

int		Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	std::sort(_numbers.begin(), _numbers.end());
}

int		Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	std::sort(_numbers.begin(), _numbers.end());
}

const char *Span::MaxCapacityException::what() const throw()
{
	return ("Container max capacity reached.");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Not enough numbers in container.");
}
