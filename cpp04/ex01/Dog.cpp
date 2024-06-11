#include "Dog.hpp"
#include <iostream>

const std::string	Dog::_className = "Dog";
const std::string	Dog::_sound = "Woofi";

Dog::Dog() {
	std::cout << _className << ": Default Constructor called" << std::endl;
	_initialize(DOG_DEFAULT_TYPE);
}

Dog::Dog(const Dog& other)
	: Animal(other) {
	std::cout << _className << ": Copy Constructor called" << std::endl;
	_brain = new Brain;
	*this = other;
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout << _className << ": Copy assignment operator overloard called" << std::endl;
	if (this != &other) {
		_type = other._type;
		*_brain = *other._brain;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << _className << ": Destructor called" << std::endl;
	delete _brain;
}

void	Dog::makeSound() const {
	std::cout << _className << " makeSound(): " << _sound << std::endl;
}

Brain*	Dog::getBrain() {
	return _brain;
}

void	Dog::_initialize(const std::string& type) {
	_type = type;
	_brain = new Brain;
}
