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