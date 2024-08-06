#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->n_contact = 0;
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
    if (this->n_contact == 7)
        this->n_contact = 0;
    std::cout << "* Storing contact #" << this->n_contact << std::endl;
    this->contacts[this->n_contact].add_info();
}

void    PhoneBook::search_contact()
{
    
}