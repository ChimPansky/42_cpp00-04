#include "WrongAnimal.hpp"
#include <iostream>

const std::string	WrongAnimal::_className = "WrongAnimal";
const std::string	WrongAnimal::_sound = "random sound";

WrongAnimal::WrongAnimal() {
	std::cout << _className << ": Default Constructor called" << std::endl;
	_initialize(WRONG_ANIMAL_DEFAULT_TYPE);
}

WrongAnimal::WrongAnimal(const std::string& type) {
	std::cout << _className << ": String Constructor called" << std::endl;
	_initialize(type);
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << _className << ": Copy Constructor called" << std::endl;
	_type = other._type;
}

std::string WrongAnimal::getType() const {
	return _type;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << _className << ": Copy assignment operator overloard called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

void	WrongAnimal::_initialize(const std::string& type) {
	_type = type;
}

WrongAnimal::~WrongAnimal() {
	std::cout << _className << ": Destructor called" << std::endl;
}

// protected methods:
void	WrongAnimal::makeSound() const {
	std::cout << _className << " makeSound(): " << _sound << std::endl;
}
