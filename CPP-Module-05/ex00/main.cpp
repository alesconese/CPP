/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:19:09 by ade-tole          #+#    #+#             */
/*   Updated: 2024/11/07 19:19:11 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout << "* * * * * TEST 1: Grade too high * * * * *" << std::endl;
		try
		{
			Bureaucrat b1("Mike", 0);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n* * * * * TEST 2: Grade too low * * * * *" << std::endl;
		try
		{
			Bureaucrat b1("Bob", 999);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n* * * * * TEST 3: Increment too high * * * * *" << std::endl;
		try
		{
			Bureaucrat b1("Jim", 5);
			for (int i = 0; i < 5; i++)
			{
				b1.incrementGrade();
				std::cout << b1 << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n* * * * * TEST 4: Decrement too low * * * * *" << std::endl;
		try
		{
			Bureaucrat b1("Bill", 146);
			for (int i = 0; i < 5; i++)
			{
				b1.decrementGrade();
				std::cout << b1 << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n* * * * * TEST 5: grades OK * * * * *" << std::endl;
		try
		{
			Bureaucrat b1("Joe", 99);
			for (int i = 0; i < 5; i++)
			{
				b1.incrementGrade();
				std::cout << b1 << std::endl;
				b1.decrementGrade();
				std::cout << b1 << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
