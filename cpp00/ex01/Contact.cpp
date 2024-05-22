#include "Phonebook.hpp"
#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>

Contact::Contact() {
	std::cout << "Contact Default Constructor" << std::endl;
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName) :
	_firstName(firstName), _lastName(lastName), _nickName(nickName) {
	std::cout << "Contact Constructor called with: " << firstName << std::endl;
}

Contact::~Contact() {
	std::cout << "Contact Destructor" << std::endl;
}

std::string Contact::getFirstName() {
	return (this->_firstName);
}

std::string Contact::getLastName() {
	return (this->_lastName);
}

void	Contact::printOverview() {
	printField(this->_firstName, COLUMN_WIDTH, COLUMN_SEPARATOR);
	printField(this->_lastName, COLUMN_WIDTH, COLUMN_SEPARATOR);
	printField(this->_nickName, COLUMN_WIDTH, COLUMN_SEPARATOR);
	std::cout << std::endl;
}

void	Contact::printDetail() {
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickName << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}
