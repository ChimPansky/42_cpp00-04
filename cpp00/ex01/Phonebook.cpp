#include "Phonebook.hpp"
#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>

Phonebook::Phonebook() {
	std::cout << "Phonebook Default Constructor" << std::endl;
	_entries = 0;
}

Phonebook::~Phonebook() {
	std::cout << "Phonebook Destructor" << std::endl;
	_entries = 0;
}

void	Phonebook::addContact(Contact newContact) {
	this->_contacts[_entries % MAX_CONTACTS] = newContact;
	_entries++;
}

void	Phonebook::printContacts() {
	std::cout << COLUMN_SEPARATOR;
	printField("Index", COLUMN_WIDTH, COLUMN_SEPARATOR);
	printField("First Name", COLUMN_WIDTH, COLUMN_SEPARATOR);
	printField("Last Name", COLUMN_WIDTH, COLUMN_SEPARATOR);
	printField("Nickname", COLUMN_WIDTH, COLUMN_SEPARATOR);
	std::cout << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++) {
		std::cout << COLUMN_SEPARATOR;
		printField(intToString(i), COLUMN_WIDTH, COLUMN_SEPARATOR);
		_contacts[i].printOverview();
	}
}

void	Phonebook::printContactDetail(int index) {
	if (index >= MAX_CONTACTS || index < 0)
	{
		std::cerr << "Error: Index " << index << " out of range." << std::endl;
		return ;
	}
		std::cout << "Index: " << index << std::endl;
	if (this->_contacts[index].getLastName().length() == 0)
		std::cout << "{Empty}" << std::endl;
	else
		this->_contacts[index].printDetail();
	std::cout << std::endl;
}

void	Phonebook::add() {
	std::cout << "adding..." << std::endl;
}

void	Phonebook::search() {
	std::cout << "searching..." << std::endl;
}
