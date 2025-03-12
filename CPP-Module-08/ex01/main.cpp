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

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << "* Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "* Longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "/n/n* * * * * TEST 2: EXCEPTIONS * * * * *" << std::endl;
		Span	sp = Span(1);

		try
		{
			sp.addNumber(6);
			sp.addNumber(3);
		}
		catch(const std::exception& e)
		{
			std::cerr << "(!) ERROR: " << e.what() << '\n';
		}
		
		try
		{
			std::cout << "* Shortest Span: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "(!) ERROR: " << e.what() << '\n';
		}

		try
		{
			std::cout << "* Shortest Span: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "(!) ERROR: " << e.what() << '\n';
		}
	}

	return 0;
}
