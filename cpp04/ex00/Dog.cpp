#include "Dog.hpp"
#include <iostream>

const std::string	Dog::_className = "Dog";
const std::string	Dog::_sound = "Woofi";

Dog::Dog() {
	std::cout << _className << ": Default Constructor called" << std::endl;
	_initialize(DOG_DEFAULT_TYPE);
}

Dog::Dog(const std::string& type) {
	std::cout << _className << ": String Constructor called" << std::endl;
	_initialize(type);
}

Dog::Dog(const Dog& other)
	: Animal(other) {
	std::cout << _className << ": Copy Constructor called" << std::endl;
	_type = other._type;
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout << _className << ": Copy assignment operator overloard called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

Dog::~Dog() {
	std::cout << _className << ": Destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << _className << " makeSound(): " << _sound << std::endl;
}
