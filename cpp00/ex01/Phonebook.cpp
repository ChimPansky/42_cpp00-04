#include "Phonebook.hpp"
#include "Contact.hpp"
#include "phonebook_utils.hpp"
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

Phonebook::Phonebook() {
	_entries = 0;
	_fieldNames[FIELD_INDEX] = "Index";
	_fieldNames[FIELD_FNAME] = "First Name";
	_fieldNames[FIELD_LNAME] = "Last Name";
	_fieldNames[FIELD_NICK] = "Nick Name";
	_fieldNames[FIELD_PHONENR] = "Phone Number";
	_fieldNames[FIELD_SECRET] = "Darkest Secret";
}

Phonebook::~Phonebook() {}

// private methods:
void	Phonebook::_addContact(Contact newContact) {
	this->_contacts[_entries % MAX_CONTACTS] = newContact;
	this->_contacts[_entries % MAX_CONTACTS].setIndex(_entries % MAX_CONTACTS + 1);
	_entries++;
}

void	Phonebook::_printContacts() {
	std::cout << std::endl << COLUMN_SEPARATOR;
	for (int i = 0; i < FIELD_PHONENR; i++)
		printField(_fieldNames[i], COLUMN_WIDTH, COLUMN_SEPARATOR);
	std::cout << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++) {
		std::cout << COLUMN_SEPARATOR;
		_contacts[i].printOverview();
	}
}

void	Phonebook::_printContactDetail(int contactIndex) {
	if (contactIndex > MAX_CONTACTS || contactIndex < 0)	{
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

bool	Phonebook::_fieldValueIsValid(const std::string& str) {
	bool	valid;

	valid = false;
	for (int i = 0; i < (int)str.length(); i++) {
		if (!std::isprint(str[i]))
			return (false);
		if (!valid && !std::isspace(str[i]))
			valid = true;
	}
	return (valid);
}

bool	Phonebook::_strToInt(const std::string& str, int& target) {
	std::stringstream	strStream(str);

	strStream >> target;
	if (strStream.fail())
		return (false);
	return (true);
}

// public methods:
void	Phonebook::add() {
	std::string	userInput[FIELD_COUNT];

	for (int i = FIELD_FNAME; i < FIELD_COUNT; i++) {
		while (1) {
			userInput[i] = readLine(_fieldNames[i]);
			if (std::cin.eof())
				return ;
			if (userInput[i].length() == 0)
				std::cout << "Field " << _fieldNames[i] << " cannot be empty!" << std::endl;
			else if (!_fieldValueIsValid(userInput[i]))
				std::cout << "Field " << _fieldNames[i] << " is invalid!" << std::endl;
			else
				break ;
		}
	}
	this->_addContact(Contact(userInput[FIELD_FNAME], userInput[FIELD_LNAME], userInput[FIELD_NICK], userInput[FIELD_PHONENR], userInput[FIELD_SECRET]));
}

void	Phonebook::search() {
	std::string	userInput;
	int			searchIndex;

	_printContacts();
	while (1) {
		userInput = readLine("Which contact details do you want to display? (Index)");
		if (std::cin.eof())
				return ;
		if (_strToInt(userInput, searchIndex) && searchIndex > 0 && searchIndex <= MAX_CONTACTS)
			break ;
		std::cout << "Invalid index: " << searchIndex << std::endl;
	}
	std::istringstream(userInput) >> searchIndex;
	this->_printContactDetail(searchIndex - 1);
}
