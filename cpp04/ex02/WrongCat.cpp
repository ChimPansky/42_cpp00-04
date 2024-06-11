#include "WrongCat.hpp"
#include <iostream>

const std::string	WrongCat::_className = "Wrong Cat";
const std::string	WrongCat::_sound = "Meeooow";

WrongCat::WrongCat() {
	std::cout << _className << ": Default Constructor called" << std::endl;
	_initialize(WRONG_CAT_DEFAULT_TYPE);
}

WrongCat::WrongCat(const std::string& type) {
	std::cout << _className << ": String Constructor called" << std::endl;
	_initialize(type);
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other) {
	std::cout << _className << ": Copy Constructor called" << std::endl;
	*this = other;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	std::cout << _className << ": Copy assignment operator overloard called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << _className << ": Destructor called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << _className << " makeSound(): " << _sound << std::endl;
}
