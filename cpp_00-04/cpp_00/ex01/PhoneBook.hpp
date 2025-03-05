#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook
{
private:
	Contact _contacts[MAX_CONTACTS];
	int _count;		  // number of contacts added so far (<= 8)
	int _oldestIndex; // tracks which contact is the "oldest"

public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContacts() const;

private:
	void _printContacts() const;
	void _printContactDetail(int index) const;
	std::string _truncateField(const std::string &str) const;
};

#endif