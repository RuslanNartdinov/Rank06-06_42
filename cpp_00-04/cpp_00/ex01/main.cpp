#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl
					  << "Exiting..." << std::endl;
			break;
		}
		if (command == "EXIT") {
            std::cout << "Exiting..." << std::endl;
            break;
        } else if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else if (command.empty()) {
            continue;
        } else {
            std::cout << "Unknown command. Try again." << std::endl;
        }
	}
	return 0;
}