#pragma once

#include <ostream>

class Fixed {
  private:
	int					_value;
	static const int	_precision = 8;

  public:
  	Fixed();
	Fixed(const int intVal);
	Fixed(const float floatVal);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits() const;
	void	setRawBits(int const raw);
	int		toInt() const;
	float	toFloat() const;
};

std::ostream& operator<<(std::ostream& outStream, const Fixed& fixedObject);
