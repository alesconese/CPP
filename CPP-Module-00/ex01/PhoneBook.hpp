#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class   PhoneBook
{
    private:
            Contact contacts[8];
            int     n_contact;
    public:
            PhoneBook();
            ~PhoneBook();
            
            void    show_commands();
            void    add_contact();
            void    search_contact();
};

#endif