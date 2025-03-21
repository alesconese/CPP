/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:21:49 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/21 19:21:53 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
	private:
			std::stack<char>	_tokens;

			RPN();
			void	loadInput(std::string input);

	public:
			RPN(std::string input);
			~RPN();
			RPN(RPN const &src);
			RPN &operator=(RPN const &src);
};

#endif