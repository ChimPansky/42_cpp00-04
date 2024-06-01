#include "Point.hpp"
#include <iostream>

bool	bsp(const Point a, const Point b, const Point  c, const Point point);
float	scalar(const Point& v1, const Point& v2);

int	main() {
	// Point	a(-7.333, -2.75);
	// Point	b(-3.147, 5.0546);
	// Point	c(2.304, 4.798);
	// Point	d(0.5, 1);

	// const Point	a(-20.3f, 10.f);
	// const Point	b(20.f, 15.f);
	// const Point	c(10.f, -20.f);
	// const Point	d(2.f, 5.f);

	Point a(1.0f, 2.0f);
    Point b(3.0f, 4.0f);
    Point c(5.0f, 1.0f);
    Point d(1.01f, 2.05f);

	std::cout << "a: " << a << "\nb: " << b << "\nc: " << c << std::endl;
	std::cout << "b - a       : " << b - a << std::endl;
	std::cout << "d is in the triangle: " << (bsp(a, b, c, d) ? "YES" : "NO") << std::endl;
	std::cout << "a + b:" << a + b << std::endl;
	std::cout << "a - b:" << a - b << std::endl;
	std::cout << "a x b:" << Point::scalarProduct(a, b) << std::endl;
	return (0);
}
