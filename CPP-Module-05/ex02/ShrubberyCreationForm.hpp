/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:30:48 by ade-tole          #+#    #+#             */
/*   Updated: 2024/11/07 19:30:51 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
			std::string	_target;

	public:
			ShrubberyCreationForm();
			ShrubberyCreationForm(std::string target);
			~ShrubberyCreationForm();
			ShrubberyCreationForm(ShrubberyCreationForm const &src);

};

#endif
