#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->n_contact = 0;
	this->full = 0;
}

PhoneBook::~PhoneBook()
{
}

void    PhoneBook::show_commands()
{
    std::cout << "* Available commands: 'ADD', 'SEARCH', 'EXIT'" << std::endl;
}

void    PhoneBook::add_contact()
{
    if (this->n_contact > 7)
	{
        this->n_contact = 0;
		this->full = 1;
	}
    std::cout << "* Storing contact #" << this->n_contact+1 << std::endl;
	if (this->full)
		std::cout << "* Caution! Overwriting previously stored contact." << std::endl;
    this->contacts[this->n_contact].add_info();
    std::cout << "* Successfully stored contact #" << this->n_contact+1 << std::endl;
	this->n_contact++;
}

void    PhoneBook::search_contact()
{
	std::string	buff;

    if (this->n_contact == 0 && this->full == 0)
	{
		std::cout << "! PhoneBook empty. Search command unavailable." << std::endl;
		return;
	}
	std::cout << std::left << "|" << std::setw(10) << "Index";
	std::cout << std::left << "|" << std::setw(10) << "First Name";
	std::cout << std::left << "|" << std::setw(10) << "Last Name";
	std::cout << std::left << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < 8; i++)
		this->contacts[i].display_short(i);
	std::cout << "* Enter contact index to display full information, or 0 to exit." << std::endl;
	while (!buff.length())
	{
		std::cout << "* Index: ";
		if (!std::getline(std::cin, buff))
			return;
		if (buff.length() == 1 && buff[0] == '0')
			return;
		if (!(buff.length() == 1) || buff[0] < '0' || buff[0] > '8')
		{
			std::cout << "! Invalid index." << std::endl;
			buff.erase();
		}
	}
	this->contacts[buff[0] - '0' - 1].display_full();
}
