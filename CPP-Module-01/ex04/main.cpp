/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:23:09 by ade-tole          #+#    #+#             */
/*   Updated: 2024/08/17 20:23:11 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
		return ((std::cout << "! Wrong parameters" << std::endl), 1);

	std::ifstream	ifs;
	ifs.open(argv[1], std::ifstream::in);
	if (ifs.fail())
		return ((std::cout << "! Unable to open specified file" << std::endl), 1);
	
	return (0);
}