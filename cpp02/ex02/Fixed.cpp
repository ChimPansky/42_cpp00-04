#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
	: _value(0) {};

Fixed::Fixed(const int intVal) {
	_value = intVal << _precision;
};

Fixed::Fixed(const float floatVal) {
	_value = static_cast<int>(roundf(floatVal * (1 << _precision)));
};

Fixed::Fixed(const Fixed& other) {
	_value = other._value;
};

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		_value = other._value;
	return *this;
}

Fixed::~Fixed() {}

int		Fixed::getRawBits() const {
	return (_value);
}

void	Fixed::setRawBits(int const raw) {
	_value = raw;
}

int		Fixed::toInt () const {
	return (_value >> _precision);
}

float	Fixed::toFloat() const {
	return (static_cast<float>(_value) / (1 << _precision));
}

bool Fixed::operator>(const Fixed& other) const {
	return (_value > other._value ? true : false);
}

bool Fixed::operator<(const Fixed& other) const {
	return (_value < other._value ? true : false);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (_value >= other._value ? true : false);
}

bool Fixed::operator<=(const Fixed& other) const {
	return (_value <= other._value ? true : false);
}

bool Fixed::operator==(const Fixed& other) const {
	return (_value == other._value ? true : false);
}

bool Fixed::operator!=(const Fixed& other) const {
	return (_value != other._value ? true : false);
}

Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed	result;

	result._value = _value + other._value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed	result;

	result._value = _value - other._value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed	result;

	result._value = (_value * other._value) >> _precision;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const {
	Fixed	result;

	result._value = ((_value << _precision) / other._value);
	return (result);
}

Fixed	Fixed::operator++(int) {
	Fixed	fixedCopy(*this);
	_value++;
	return (fixedCopy);
}

Fixed&	Fixed::operator++() {
	_value++;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	fixedCopy(*this);
	_value--;
	return (fixedCopy);
}

Fixed&	Fixed::operator--() {
	_value--;
	return (*this);
}

// min/max functions:
Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a > b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b ? a : b);
}

std::ostream& operator<<(std::ostream& outStream, const Fixed& fixedObject) {
	outStream << fixedObject.toFloat();
	return (outStream);
}
