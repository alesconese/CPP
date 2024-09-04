/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:07:07 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/02 21:07:09 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class	Harl
{
	private:
			void	debug();
			void	info();
			void	warning();
			void	error();
	
	public:
			Harl();
			~Harl();

			void	complain(std::string level);
};

#endif
