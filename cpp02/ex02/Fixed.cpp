#include "Fixed.hpp"
#include <iostream>

const float	Fixed::_epsilon = 1.0f / (1 << Fixed::_precision);

Fixed::Fixed()
	: _value(0) {};

Fixed::Fixed(const int intVal) {
	std::cout << "Int constructor called" << std::endl;
	_value = intVal << _precision;
};

Fixed::Fixed(const float floatVal) {
	std::cout << "Float constructor called" << std::endl;
	int		intPart;
	float	fractionalPart;

	intPart = (int)floatVal;
	fractionalPart = floatVal - intPart;

	// std:: cout << "Integer Part: " << intPart << "| shifted left<< by 8: " << (intPart << _precision) << std::endl;
	// std:: cout << "Fractional Part: " << fractionalPart << "| shifted left<< by 8: " << (int)(fractionalPart * pow(2, _precision)) << std::endl;
	// std::cout << "Integer Part + Fractional Part: "
	// << (intPart << _precision) + (int)(fractionalPart * pow(2, _precision)) << std::endl;

	_value = intPart << _precision;
	_value += (int)(fractionalPart * (1 << _precision));
};

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
	return (_value);
}

void	Fixed::setRawBits(int const raw) {
	_value = raw;
}

int	Fixed::toInt () const {
	//return ((_value & (int)(pow(2, sizeof(int) * 8) - pow(2, _precision)) ) >> _precision);
	//return ((_value & 0xFFFFFF00) >> _precision);
	return (_value >> _precision);
}

float	Fixed::toFloat() const {
	return ((float)_value / (1 << _precision));
	//return ( (float)this->toInt() + ( (_value & 0x000000FF) / pow(2, _precision)) );
	//return ( (float)toInt() + ( (_value & (int)(pow(2, _precision) - 1)) / pow(2, _precision)) );
}

bool Fixed::operator>(const Fixed& other) const {
	return (_value > other.getRawBits() ? true : false);
}

bool Fixed::operator<(const Fixed& other) const {
	return (_value < other.getRawBits() ? true : false);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (_value >= other.getRawBits() ? true : false);
}

bool Fixed::operator<=(const Fixed& other) const {
	return (_value <= other.getRawBits() ? true : false);
}

bool Fixed::operator==(const Fixed& other) const {
	return (_value == other.getRawBits() ? true : false);
}

bool Fixed::operator!=(const Fixed& other) const {
	return (_value != other.getRawBits() ? true : false);
}

Fixed	Fixed::operator+(const Fixed& other) {
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) {
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) {
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) {
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	Fixed::operator++(int) {
	Fixed	fixedCopy(*this);
	_value++;
	//this->setRawBits(Fixed(this->toFloat() + _epsilon).getRawBits());
	//*this = Fixed(this->toFloat() + _epsilon).getRawBits();
	return (fixedCopy);
}

Fixed&	Fixed::operator++() {
	_value++;
	//this->setRawBits(Fixed(this->toFloat() + _epsilon).getRawBits());
	//*this = Fixed(this->toFloat() + _epsilon).getRawBits();
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


// Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
// 	return (a < b ? a : b);
// }

std::ostream& operator<<(std::ostream& outStream, const Fixed& fixedObject) {
	outStream << fixedObject.toFloat();
	return (outStream);
}
