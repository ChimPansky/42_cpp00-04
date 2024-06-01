#include "Fixed.hpp"
#include <iostream>

int	main() {
	// Fixed a;
	// Fixed const b( 10 );
	// Fixed const c( 42.424564f );
	// Fixed const d( b );
	// a = Fixed( 1234.4321f);
	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;

	// std::cout << "a > b (" << a << ">" << b << "): " << (a > b) << std::endl;
	// std::cout << "b > a (" << b << ">" << a << "): " << (b > a) << std::endl;
	// std::cout << "a > a (" << a << ">" << a << "): " << (a > a) << std::endl;
 	// std::cout << "a < b (" << a << "<" << b << "): " << (a < b) << std::endl;
 	// std::cout << "a >= b (" << a << ">=" << b << "): " << (a >= b) << std::endl;
	// std::cout << "a >= a (" << a << ">=" << a << "): " << (a >= a) << std::endl;
 	// std::cout << "a <= b (" << a << "<=" << b << "): " << (a <= b) << std::endl;
	// std::cout << "a <= a (" << a << "<=" << a << "): " << (a <= a) << std::endl;

	// std::cout << "a == b (" << a << "==" << b << "): " << (a == b) << std::endl;
	// std::cout << "a == a (" << a << "==" << a << "): " << (a == a) << std::endl;
	// std::cout << "a != b (" << a << "!=" << b << "): " << (a != b) << std::endl;
	// std::cout << "a != a (" << a << "!=" << a << "): " << (a != a) << std::endl;

	// Fixed	aplusb = a + b;

	// std::cout << "a + b (" << a << "+" << b << "): " << a + b << std::endl;
	// std::cout << "a + b (" << a << "+" << b << "): " << aplusb << std::endl;

	// std::cout << "a - b (" << a << "-" << b << "): " << a - b << std::endl;
	// std::cout << "a * b (" << a << "*" << b << "): " << a * b << std::endl;
	// std::cout << "a / b (" << a << "/" << b << "): " << a / b << std::endl;

	// for (int i = 0; i < 10; i++) {
	// 	std::cout << "++a (++" << a << "): " << ++a << std::endl;
	// }

	// for (int i = 0; i < 10; i++) {
	// 	std::cout << "a++ (" << a << "++): " << a++ << std::endl;
	// }

	// return 0;

	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << "\n\n" << b << std::endl;
	// std::cout << "min(" << a << "," << b << "): " << Fixed::min( a, b ) << std::endl;
	// std::cout << "max(" << a << "," << b << "): " << Fixed::max( a, b ) << std::endl;

	// std::cout << "\n\n" << a << std::endl;
	// std::cout << --a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a-- << std::endl;
	// std::cout << a << "\n\n" << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 5.00f ) / Fixed( 2 ) );
	std::cout << "5.05 / 2.0: " << c << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "division by zero:" << Fixed(42.42f) / Fixed(0.0f) << std::endl;


	// float	source2 = 42.54867312;
	// Fixed	fix3(source2);

	// std::cout << "fix3 val:" << fix3.getRawBits() << std::endl;
	// std::cout << "fix3.toInt():" << fix3.toInt() << std::endl;
	// std::cout << "fix3.toFloat():" << fix3.toFloat() << std::endl;
	// std::cout << "outstream << overload: " << fix3 << std::endl;

	return (0);
}
