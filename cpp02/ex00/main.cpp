#include "Fixed.hpp"
#include <iostream>

int	main() {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);

	// Fixed	fix1;
	// Fixed	fix2(fix1);
	// Fixed	fix3;

	// std::cout << "fix1 val:" << fix1.getRawBits() << std::endl;
	// std::cout << "fix2 val:" << fix2.getRawBits() << std::endl;

	// fix1.setRawBits(5);
	// std::cout << "changing fix1 val to 5..." << std::endl;

	// std::cout << "fix1 val:" << fix1.getRawBits() << std::endl;
	// std::cout << "fix2 val:" << fix2.getRawBits() << std::endl;


	// std::cout << "fix3 val:" << fix3.getRawBits() << std::endl;
	// fix3.setRawBits(42);
	// std::cout << "changing fix3 val to 42..." << std::endl;
	// std::cout << "fix3 val:" << fix3.getRawBits() << std::endl;

	// std::cout << "fix3 = fix1..." << std::endl;
	// fix3 = fix1;
	// std::cout << "fix3 val:" << fix3.getRawBits() << std::endl;

	// return (0);
}
