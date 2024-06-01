#include "Fixed.hpp"
#include <iostream>

int	main() {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.424564f );
	Fixed const d( b );
	a = Fixed( 1234.4321f);
	//a = b;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;

	// float	source2 = 42.54867312;
	// Fixed	fix3(source2);

	// std::cout << "fix3 val:" << fix3.getRawBits() << std::endl;
	// std::cout << "fix3.toInt():" << fix3.toInt() << std::endl;
	// std::cout << "fix3.toFloat():" << fix3.toFloat() << std::endl;
	// std::cout << "outstream << overload: " << fix3 << std::endl;

	// return (0);
}
