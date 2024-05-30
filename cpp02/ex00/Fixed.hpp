#pragma once

class Fixed {
  private:
	int					_value;
	static const int	_precision = 8;

  public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits() const;
	void	setRawBits(int const raw);
};
