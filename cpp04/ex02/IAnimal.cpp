#include "IAnimal.hpp"
#include <iostream>

const std::string	IAnimal::_className = "IAnimal";

IAnimal::IAnimal() {
	std::cout << _className << ": Default Constructor called" << std::endl;
	_initialize();
}

IAnimal::IAnimal(const std::string& type) {
	std::cout << _className << ": String Constructor called" << std::endl;
	_initialize(type);
}

IAnimal::IAnimal(const IAnimal& other) {
	std::cout << _className << ": Copy Constructor called" << std::endl;
	_type = other._type;
}

std::string IAnimal::getType() const {
	return _type;
}

IAnimal&	IAnimal::operator=(const IAnimal& other) {
	std::cout << _className << ": Copy assignment operator overloard called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

void	IAnimal::_initialize(const std::string& type) {
	_type = type;
}

IAnimal::~IAnimal() {
	std::cout << _className << ": Destructor called" << std::endl;
}
