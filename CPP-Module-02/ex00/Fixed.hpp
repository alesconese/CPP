/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:21:05 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/06 19:21:07 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed
{
	private:
			int					value;
			static const int	fractional = 8;
	
	public:
    		Fixed();
    		~Fixed();
			Fixed(const Fixed &other);
			Fixed &operator=(const Fixed &other);
};

Fixed::Fixed(): value(0)
{
}

Fixed::~Fixed()
{
}
