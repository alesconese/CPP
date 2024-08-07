#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string	add_field(std::string field)
{
	std::string	buff;

	while (!buff.length())
	{
		std::cout << "* " << field << ": ";
		if (!std::getline(std::cin, buff))
			break;
		if (!buff.length())
			std::cout << "! Empty field." << std::endl;
	}
	return (buff);
}

std::string	add_number(std::string field)
{
	std::string	buff;

	while (!buff.length())
	{
		buff = add_field(field);
		if (!buff.length())
			break;
		for (unsigned int i = 0; i < buff.length(); i++)
			if (buff[i] < '0' || buff[i] > '9')
			{
				std::cout << "! Invalid number." << std::endl;
				buff.erase();
			}
	}
	return (buff);
}

void    Contact::add_info()
{
    first_name = add_field("First Name");
	last_name = add_field("Last Name");
	nickname = add_field("Nickame");
	phone_number = add_number("Phone Number");
	darkest_secret = add_field("Darkest Secret");
}

void	Contact::display_short(int index)
{
	if(!this->first_name.length())
		return;
	std::cout << std::left << "|" << std::setw(10) << index+1;
	if (this->first_name.length() > 10)
		std::cout << std::left << "|" << this->first_name.substr(0, 9) << ".";
	else
		std::cout << std::left << "|" << std::setw(10) << this->first_name;
	if (this->last_name.length() > 10)
		std::cout << std::left << "|" << this->last_name.substr(0, 9) << ".";
	else
		std::cout << std::left << "|" << std::setw(10) << this->last_name;
	if (this->nickname.length() > 10)
		std::cout << std::left << "|" << this->nickname.substr(0, 9) << ".|" << std::endl;
	else
		std::cout << std::left << "|" << std::setw(10) << this->nickname << "|" << std::endl;
}

void	Contact::display_full()
{
	if(!this->first_name.length())
	{
		std::cout << "! Contact is not stored." << std::endl;
		return;
	}
	std::cout << "* First Name: " << this->first_name << std::endl;
	std::cout << "* Last Name: " << this->last_name << std::endl;
	std::cout << "* Nickname: " << this->nickname << std::endl;
	std::cout << "* Phone Number: " << this->phone_number << std::endl;
	std::cout << "* Darkest Secret: " << this->darkest_secret << std::endl;
}
