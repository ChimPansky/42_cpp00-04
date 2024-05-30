#pragma once

#include <ostream>

class Fixed {
  private:
	int					_value;
	static const int	_precision = 8;
	static const float	_epsilon;

  public:
	// constructors
  	Fixed();
	Fixed(const int intVal);
	Fixed(const float floatVal);
	Fixed(const Fixed& other);

	// copy assignment operator overload:
	Fixed& operator=(const Fixed& other);

	// destructor
	~Fixed();

	// getter and setter:
	int		getRawBits() const;
	void	setRawBits(int const raw);

	// conversions:
	int		toInt() const;
	float	toFloat() const;


	// comparison operators overload:
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// aritmetic operators:
	Fixed	operator+(const Fixed& other);
	Fixed	operator-(const Fixed& other);
	Fixed	operator/(const Fixed& other);
	Fixed	operator*(const Fixed& other);

	// increment/decrement operators:
	Fixed	operator++(int);	// postincrement
	Fixed&	operator++();		// preincrement
	Fixed	operator--(int);	// postdecrement
	Fixed&	operator--();		// preincrement

	// min/max functions:
	static Fixed&		min(Fixed& a, Fixed&b);
	static const Fixed&	min(const Fixed& a, const Fixed&b);
	static Fixed&		max(Fixed& a, Fixed&b);
	static const Fixed&	max(const Fixed& a, const Fixed&b);

};

std::ostream& operator<<(std::ostream& outStream, const Fixed& fixedObject);
