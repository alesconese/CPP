#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class   PhoneBook
{
    private:
            Contact contacts[8];
            int     n_contact;
			int		full;

    public:
            PhoneBook();
            ~PhoneBook();
            
            void    show_commands();
            void    add_contact();
            void    search_contact();
};

#endif
