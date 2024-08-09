#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook   phonebook;
    std::string command;

    std::cout << "* Welcome to the crappy awesome phonebook!" << std::endl;
    phonebook.show_commands();
    while (42)
    {
        std::cout << "* Enter a command: ";
        if (!std::getline(std::cin, command))
            return (1);
        if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search_contact();
        else if (command == "EXIT")
            return (std::cout << "* Exiting..." << std::endl, 0);
        else
        {
            std::cout << "! Invalid command, please try again." << std::endl;
            phonebook.show_commands();
        }
    }
}