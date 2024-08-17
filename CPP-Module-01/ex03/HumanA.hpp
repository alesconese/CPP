/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:16:27 by ade-tole          #+#    #+#             */
/*   Updated: 2024/08/17 20:16:47 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class	HumanA
{
	private:
		Weapon		weapon;
		std::string	name;
	
	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA();
		
		void	attack();
};

#endif
