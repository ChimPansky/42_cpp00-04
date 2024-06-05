#include "Cat.hpp"
#include <iostream>

const std::string	Cat::_className = "Cat";
const std::string	Cat::_sound = "Meeooow";

Cat::Cat() {
	std::cout << _className << ": Default Constructor called" << std::endl;
	_initialize(CAT_DEFAULT_TYPE);
}

Cat::Cat(const std::string& type) {
	std::cout << _className << ": String Constructor called" << std::endl;
	_initialize(type);
}

Cat::Cat(const Cat& other)
	: Animal(other) {
	std::cout << _className << ": Copy Constructor called" << std::endl;
	_type = other._type;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << _className << ": Copy assignment operator overloard called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

Cat::~Cat() {
	std::cout << _className << ": Destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << _className << " makeSound(): " << _sound << std::endl;
}