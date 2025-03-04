/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:53:27 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/04 17:53:29 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class	Span
{
	private:
			unsigned int		_N;
			std::vector<int>	_numbers;
			Span();
	
	public:
			Span(unsigned int N);
			~Span();
			Span(Span const &src);
			Span &operator=(Span const &src);

			void	addNumber(int num);
			int		shortestSpan();
			int		longestSpan();

			class MaxCapacityException : public std::exception
			{
				const char *what() const throw();
			};

			class NoSpanException : public std::exception
			{
				const char *what() const throw();
			};
};

#endif