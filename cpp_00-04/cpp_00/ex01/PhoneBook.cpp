#include <iostream>
#include <iomanip>  // for std::setw, std::right
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->_count = 0;
    this->_oldestIndex = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact()
{
    // We will overwrite the oldest contact if we already have 8
    int index = this->_count;
    if (this->_count == MAX_CONTACTS)
        index = this->_oldestIndex;

    // Temporary variables
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << "Enter first name: ";
    if (!std::getline(std::cin, firstName))
        return;
    std::cout << "Enter last name: ";
    if (!std::getline(std::cin, lastName))
        return;
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, nickname))
        return;
    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, phoneNumber))
        return;
    std::cout << "Enter darkest secret: ";
    if (!std::getline(std::cin, darkestSecret))
        return;

    // All fields must not be empty
    if (firstName.empty() || lastName.empty() || nickname.empty() ||
        phoneNumber.empty() || darkestSecret.empty())
    {
        std::cout << "Error: fields must not be empty." << std::endl;
        return;
    }

    // Assign values
    this->_contacts[index].setFirstName(firstName);
    this->_contacts[index].setLastName(lastName);
    this->_contacts[index].setNickname(nickname);
    this->_contacts[index].setPhoneNumber(phoneNumber);
    this->_contacts[index].setDarkestSecret(darkestSecret);

    // Update counters
    if (this->_count < MAX_CONTACTS)
        this->_count++;
    if (this->_count == MAX_CONTACTS)
        this->_oldestIndex = (this->_oldestIndex + 1) % MAX_CONTACTS;
}

void PhoneBook::searchContacts() const
{
    if (this->_count == 0)
    {
        std::cout << "PhoneBook is empty. Add some contacts first." << std::endl;
        return;
    }
    // Print the table of contacts
    this->_printContacts();

    // Prompt user for an index
    std::cout << "Enter the contact index to display: ";
    std::string input;
    if (!std::getline(std::cin, input))
        return; // handle EOF or error

    if (input.size() != 1 || !std::isdigit(input[0]))
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    int index = input[0] - '0';
    if (index < 0 || index >= this->_count)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    // Print contact details
    this->_printContactDetail(index);
}

void PhoneBook::_printContacts() const
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < this->_count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << this->_truncateField(_contacts[i].getFirstName()) << "|"
                  << std::setw(10) << this->_truncateField(_contacts[i].getLastName()) << "|"
                  << std::setw(10) << this->_truncateField(_contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::_printContactDetail(int index) const
{
    std::cout << "First Name: " << this->_contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << this->_contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << this->_contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
}

std::string PhoneBook::_truncateField(const std::string &str) const
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return str;
}