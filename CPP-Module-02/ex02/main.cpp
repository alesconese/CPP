/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:25:12 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/12 18:25:14 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main()
{
	Fixed		a( 3.1301f );
	Fixed const	b( 3.1099f );

	if (a > b)
		std::cout << "a is bigger than b";
	else if (b > a)
		std::cout << "b is bigger than a";
	else
		std::cout << "a is equal to b";
	std::cout << std:: endl;

	return 0;
}
