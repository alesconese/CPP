/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:35:26 by ade-tole          #+#    #+#             */
/*   Updated: 2025/02/26 17:35:28 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void	ft_add(int &x)
{
	x += 1;
}

void	ft_changeCase(char &c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	else if (c >= 97 && c <= 122)
		c -= 32;
}

int	main()
{
	{
		std::cout << "* * * * * TEST 1: INT ARRAY * * * * *" << std::endl;
		
		int	iarr[5] = {23, 42, 101, 9, 11};
		
		std::cout << "* Original: { ";
		for (int i = 0; i < 5; i++)
			std::cout << iarr[i] << " ";
		std::cout << "}" << std::endl;

		::iter<int>(iarr, 5, ft_add);
		
		std::cout << "* Modified: { ";
		for (int i = 0; i < 5; i++)
			std::cout << iarr[i] << " ";
		std::cout << "}" << std::endl;
	}
	{
		std::cout << std::endl << "* * * * * TEST 2: CHAR ARRAY * * * * *" << std::endl;
		
		std::string	str = "Hi my name is Slim Shady";
		char	*carr = (char *)str.c_str();

		std::cout << "* Original: " << carr << std::endl;

		::iter(carr, str.size(), ft_changeCase);

		std::cout << "* Modified: " << carr << std::endl;
	}
	return 0;
}
