/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:09:26 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/19 20:09:27 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("(null)"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called: " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called: " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructor called: " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
	std::cout << "Copy constructor called: " << _name << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &src)
{
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	std::cout << "Copy assignment operator called: " << _name << std::endl;
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	(void)target;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	(void)amount;
}

void	ClapTrap::beRapaired(unsigned int amount)
{
	(void)amount;
}
