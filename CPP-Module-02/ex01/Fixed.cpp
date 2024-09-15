/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:26:01 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/12 18:26:03 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const int_v): _value(int_v << _fractional)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const fp_v): _value(roundf(fp_v * (1 << _fractional)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = other.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << _fractional));
}

int		Fixed::toInt(void) const
{
	return (_value >> _fractional);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &src)
{
	os << src.toFloat();
	return os;
}
