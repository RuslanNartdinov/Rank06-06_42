#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook   phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
        {
            std::cout << std::endl << "EOF reached or error. Exiting." << std::endl;
            break;
        }
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContacts();
        else if (command == "EXIT")
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else if (!command.empty())
        {
            std::cout << "Invalid command." << std::endl;
        }
    }
    return 0;
}