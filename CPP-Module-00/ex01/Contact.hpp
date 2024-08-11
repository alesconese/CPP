#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
    private:
            std::string _first_name;
            std::string _last_name;
            std::string _nickname;
            std::string _phone_number;
            std::string _darkest_secret;

    public:
            Contact();
            ~Contact();

            void    add_info();
			void	display_short(int index);
			void	display_full();
};

#endif
