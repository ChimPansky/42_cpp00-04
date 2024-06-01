#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
	: _value(0) {
		std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
};

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other._value;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called with " << raw << std::endl;
	_value = raw;
}
