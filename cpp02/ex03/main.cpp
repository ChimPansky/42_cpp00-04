#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);
Point	vector(const Point& p1, const Point& p2);
float	scalar(const Point& v1, const Point& v2);

int	main() {
	// Point	a(-7.333, -2.75);
	// Point	b(-3.147, 5.0546);
	// Point	c(2.304, 4.798);
	// Point	d(0.5, 1);

	Point	a(-2, 1);
	Point	b(2, 2);
	Point	c(2, -3);
	Point	d(1, 1);

	std::cout << "a: " << a << "\nb: " << b << "\nc: " << c << std::endl;
	std::cout << "d is in the triangle: " << bsp(a, b, c, d) << std::endl;
	std::cout << "a + b:" << a + b << std::endl;
	std::cout << "a - b:" << a - b << std::endl;
	std::cout << "a x b:" << Point::scalarProduct(a, b) << std::endl;
	return (0);
}
