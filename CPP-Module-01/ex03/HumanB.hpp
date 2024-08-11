#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class	HumanB
{
	private:
			std::string	_name;
			Weapon		*_weapon;

	public:
			HumanB(std::string name);
			HumanB(std::string name, Weapon &weapon);
			~HumanB();

			void	attack();
			void	setWeapon(Weapon &weapon);
};

#endif
