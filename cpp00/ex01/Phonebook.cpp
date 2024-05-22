#include "Phonebook.hpp"
#include "Contact.hpp"
#include "phonebook_utils.hpp"
#include <iostream>

Phonebook::Phonebook() {
	std::cout << "Phonebook Default Constructor" << std::endl;
	_entries = 0;
	_fieldNames[FIELD_INDEX] = "Index";
	_fieldNames[FIELD_FNAME] = "First Name";
	_fieldNames[FIELD_LNAME] = "Last Name";
	_fieldNames[FIELD_NICK] = "Nick Name";
	_fieldNames[FIELD_PHONENR] = "Phone Number";
	_fieldNames[FIELD_SECRET] = "Darkest Secret";
}

Phonebook::~Phonebook() {
	std::cout << "Phonebook Destructor" << std::endl;
	_entries = 0;
}

void	Phonebook::addContact(Contact newContact) {
	this->_contacts[_entries % MAX_CONTACTS] = newContact;
	this->_contacts[_entries % MAX_CONTACTS].setIndex(_entries);
	_entries++;
}

void	Phonebook::printContacts() {
	std::cout << COLUMN_SEPARATOR;
	for (int i = 0; i < FIELD_PHONENR; i++)
		printField(_fieldNames[i], COLUMN_WIDTH, COLUMN_SEPARATOR);
	std::cout << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++) {
		std::cout << COLUMN_SEPARATOR;
		_contacts[i].printOverview();
	}
}

void	Phonebook::printContactDetail(int contactIndex) {
	if (contactIndex >= MAX_CONTACTS || contactIndex < 0)	{
		std::cerr << "Error: Index " << contactIndex << " out of range." << std::endl;
		return ;
	}
	if (this->_contacts[contactIndex].getFields()[FIELD_INDEX].length() == 0)
		std::cout << "{Empty}" << std::endl;
	else {
		for (int fieldIndex = FIELD_INDEX; fieldIndex < FIELD_COUNT; fieldIndex++)
			std::cout << this->_fieldNames[fieldIndex] << ": "
				<< this->_contacts[contactIndex].getFields()[fieldIndex] << std::endl;
	}
	std::cout << std::endl;
}

void	Phonebook::add() {
	std::cout << "adding..." << std::endl;
}

void	Phonebook::search() {
	std::cout << "searching..." << std::endl;
}
