#include "Fixed.hpp"
#include <iostream>
#include <cmath>


Fixed::Fixed()
	: _value(0) {
		std::cout << "Default constructor called" << std::endl;
	};

Fixed::Fixed(const int intVal) {
	std::cout << "Int constructor called" << std::endl;
	_value = intVal << _precision;
};

Fixed::Fixed(const float floatVal) {
	std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(floatVal * (1 << _precision)));
};

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
};

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_value = other._value;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called with " << raw << std::endl;
	_value = raw;
}

int		Fixed::toInt () const {
	return (_value >> _precision);
}

float	Fixed::toFloat() const {
	return (static_cast<float>(_value) / (1 << _precision));
}

std::ostream& operator<<(std::ostream& outStream, const Fixed& fixedObject) {
	outStream << fixedObject.toFloat();
	return (outStream);
}
