#include "Animal.hpp"
#include <iostream>

const std::string	Animal::_className = "Animal";
const std::string	Animal::_sound = "random sound";

Animal::Animal() {
	std::cout << _className << ": Default Constructor called" << std::endl;
	_initialize(ANIMAL_DEFAULT_TYPE);
}

Animal::Animal(const std::string& type) {
	std::cout << _className << ": String Constructor called" << std::endl;
	_initialize(type);
}

Animal::Animal(const Animal& other) {
	std::cout << _className << ": Copy Constructor called" << std::endl;
	*this = other;
}

std::string Animal::getType() const {
	return _type;
}

Animal&	Animal::operator=(const Animal& other) {
	std::cout << _className << ": Copy assignment operator overloard called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

void	Animal::_initialize(const std::string& type) {
	_type = type;
}

Animal::~Animal() {
	std::cout << _className << ": Destructor called" << std::endl;
}

// protected methods:
void	Animal::makeSound() const {
	std::cout << _className << " makeSound(): " << _sound << std::endl;
}
