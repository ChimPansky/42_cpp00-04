#include "Contact.hpp"
#include <iostream>
#include <sstream>

Contact::Contact() {}

Contact::Contact(std::string fName, std::string lName,
	std::string nick, std::string phoneNr, std::string secret) {
	this->_fields[FIELD_FNAME] = fName;
	this->_fields[FIELD_LNAME] = lName;
	this->_fields[FIELD_NICK] = nick;
	this->_fields[FIELD_PHONENR] = phoneNr;
	this->_fields[FIELD_SECRET] = secret;
}

Contact::~Contact() {}

// private methods:
std::string		Contact::_intToString(int nbr) {
	std::ostringstream	temp_str;

	temp_str << nbr;
	return (temp_str.str());
}

// public methods:
std::string*	Contact::getFields() {
	return (this->_fields);
}

void			Contact::setIndex(int index) {
	this->_fields[FIELD_INDEX] = _intToString(index);
}

void			Contact::printOverview() {
	for (int i = 0; i < FIELD_PHONENR; i++)
		printField(this->_fields[i], COLUMN_WIDTH, COLUMN_SEPARATOR);
	std::cout << std::endl;
}
