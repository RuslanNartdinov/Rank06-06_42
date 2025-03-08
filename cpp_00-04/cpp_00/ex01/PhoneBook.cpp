#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : _count(0), _oldestIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}

static std::string cutOrNot(const std::string &str)
{
	if (str.size() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::addContact()
{
	Contact newContact;
	std::string input;

	std::cout << "Enter First Name: ";
	if (!std::getline(std::cin, input))
		return;
	newContact.setFirstName(input);

	std::cout << "Enter Last Name: ";
	if (!std::getline(std::cin, input))
		return;
	newContact.setLastName(input);

	std::cout << "Enter Nickname: ";
	if (!std::getline(std::cin, input))
		return;
	newContact.setNickname(input);

	std::cout << "Enter Phone Number: ";
	if (!std::getline(std::cin, input))
		return;
	newContact.setPhoneNumber(input);

	std::cout << "Enter Darkest Secret: ";
	if (!std::getline(std::cin, input))
		return;
	newContact.setDarkestSecret(input);

	if (newContact.getFirstName().empty() ||
		newContact.getLastName().empty() ||
		newContact.getNickname().empty() ||
		newContact.getPhoneNumber().empty() ||
		newContact.getDarkestSecret().empty())
	{
		std::cout << "ERROR: All fields must be non-empty. Contact not saved." << std::endl;
		return;
	}
	_contacts[_oldestIndex] = newContact;
	_oldestIndex = (_oldestIndex + 1) % MAX_CONTACTS;
	_count++;
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact()
{
	int numberOfContacts = (_count < MAX_CONTACTS) ? _count : MAX_CONTACTS;
	if (numberOfContacts == 0)
	{
		std::cout << "PhoneBook is empty. Use ADD to add contacts." << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "FirstName" << "|"
			  << std::setw(10) << "LastName" << "|"
			  << std::setw(10) << "NickName" << std::endl;
	for (int i = 0; i < numberOfContacts; i++)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << cutOrNot(_contacts[i].getFirstName()) << "|"
				  << std::setw(10) << cutOrNot(_contacts[i].getLastName()) << "|"
				  << std::setw(10) << cutOrNot(_contacts[i].getNickname()) << std::endl;
	}
	std::cout << "Enter the contact index to display: ";
	std::string indexStr;
	if (!std::getline(std::cin, indexStr))
		return;
	int index;
	try
	{
		index = std::stoi(indexStr);
	}
	catch (...)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	if (index < 0 || index >= numberOfContacts){
		std::cout << "Index out of range." << std::endl;
        return;
	}
	std::cout << "First Name:     " << _contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name:      " << _contacts[index].getLastName() << std::endl;
    std::cout << "Nickname:       " << _contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number:   " << _contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}