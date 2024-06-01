#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, const Point b, const Point  c, const Point point);

int	main() {

	// Triangle1:
	Point	a(0.5f, 0.5f);
	Point	b(0.5f, 4.5f);
	Point	c(4.5f, 0.5f);

	// Triangle2:
	// const Point	a(-20.3f, 10.f);
	// const Point	b(20.f, 15.f);
	// const Point	c(10.f, -20.f);

	// Triangle3:
	// Point	a(0.5f, 0.5f);
	// Point	b(0.5f, 4.5f);
	// Point	c(4.5f, 0.5f);

	// Triangle4:
	// Point a(1.0f, 2.0f);
    // Point b(3.0f, 4.0f);
    // Point c(5.0f, 1.0f);

	// Test points:
	Point	d(4.5f, 0.5f);
	Point	e(1, 0.5);
	Point	f(2.5f, 1.242f);
	Point	g(0.0f, 0.0f);

	std::cout << "a: " << a << "\nb: " << b << "\nc: " << c << std::endl;
	std::cout << "d" << d << " is in the triangle: " << (bsp(a, b, c, d) ? "YES" : "NO") << std::endl;
	std::cout << "e" << e << " is in the triangle: " << (bsp(a, b, c, e) ? "YES" : "NO") << std::endl;
	std::cout << "f" << f << " is in the triangle: " << (bsp(a, b, c, f) ? "YES" : "NO") << std::endl;
	std::cout << "g" << g << " is in the triangle: " << (bsp(a, b, c, g) ? "YES" : "NO") << std::endl;
	return (0);
}
