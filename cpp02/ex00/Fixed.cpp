#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
	: _value(0) {
		std::cout << "Default constructor called" << std::endl;
};

// Fixed::Fixed(const Fixed& other)
// 	: _value (other.getRawBits()) {
// 		std::cout << "Copy constructor called" << std::endl;
// };

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	_value = other.getRawBits();
};

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_value = other.getRawBits();
	}
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
