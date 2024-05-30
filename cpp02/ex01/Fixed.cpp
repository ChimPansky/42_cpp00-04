#include "Fixed.hpp"
#include <iostream>


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
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called with " << raw << std::endl;
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

std::ostream& operator<<(std::ostream& outStream, const Fixed& fixedObject) {
	outStream << fixedObject.toFloat();
	return (outStream);
}
