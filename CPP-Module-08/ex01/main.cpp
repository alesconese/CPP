/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:23:55 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/04 18:23:56 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	{
		std::cout << "* * * * * TEST 1: ADDING NUMBERS MANUALLY * * * * *" << std::endl;
		Span	sp = Span(5);

		try
		{
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(42);
		}
		catch(const std::exception& e)
		{
			std::cerr << "(!) ERROR: " << e.what() << '\n';
		}
		
		
	}

	return 0;
}