#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main() {
	Point	a(-7.333, -2.75);
	Point	b(-3.147, 5.0546);
	Point	c(2.304, 4.798);
	Point	d(0.5, 1);

	std::cout << "a: " << a << "\nb: " << b << "\nc: " << c << std::endl;
	std::cout << "d is in the triangle: " << bsp(a, b, c, d) << std::endl;
	return (0);
}
