#include "Fixed.hpp"
#include "Point.hpp"

// vec1 x vec2 = vec1.x * vec2.y - vec1.y * vec2.x
static const Fixed	crossProduct(const Point& p1, const Point& p2) {
	return (p1.getX() * p2.getY() - p1.getY() * p2.getX());
}

bool	bsp(const Point a, const Point b, const Point  c, const Point point) {
	Fixed	abToApCross = crossProduct(b - a, point -a );
	Fixed	bcToBpCross = crossProduct(c - b, point - b);
	Fixed	caToCpCross = crossProduct(a - c, point - c);

	return ((abToApCross > 0 && bcToBpCross > 0 && caToCpCross > 0)
		||  (abToApCross < 0 && bcToBpCross < 0 && caToCpCross < 0));
}

	// Point	ab = b - a;
	// Point	bc = c - b;
	// Point	ca = a - c;
	// Point	ap = point - a;
	// Point	bp = point - b;
	// Point	cp = point - c;

	// Fixed	abToApCross = Point::crossProduct(ab, ap);
	// Fixed	bcToBpCross = Point::crossProduct(bc, bp);
	// Fixed	caToCpCross = Point::crossProduct(ca, cp);

	// std::cout << "ab: " << ab << std::endl;
	// std::cout << "bc: " << bc << std::endl;
	// std::cout << "ca: " << ca << std::endl;
	// std::cout << "ap: " << ap << std::endl;
	// std::cout << "bp: " << bp << std::endl;
	// std::cout << "cp: " << cp << std::endl;

	// std::cout << "cross1: " << abToApCross << std::endl;
	// std::cout << "cross2: " << bcToBpCross << std::endl;
	// std::cout << "cross3: " << caToCpCross << std::endl;

	//const Fixed fixedZero(0.0f);
