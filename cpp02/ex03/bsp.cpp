#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>
bool	bsp(const Point a, const Point b, const Point  c, const Point point) {
	Point	ab = b - a;
	Point	bc = c - b;
	Point	ca = a - c;
	Point	ap = point - a;
	Point	bp = point - b;
	Point	cp = point - c;

	Fixed	abToApCross = Point::scalarProduct(ab, ap);
	Fixed	bcToBpCross = Point::scalarProduct(bc, bp);
	Fixed	caToCpCross = Point::scalarProduct(ca, cp);

	std::cout << "ab: " << ab << std::endl;
	std::cout << "bc: " << bc << std::endl;
	std::cout << "ca: " << ca << std::endl;
	std::cout << "ap: " << ap << std::endl;
	std::cout << "bp: " << bp << std::endl;
	std::cout << "cp: " << cp << std::endl;

	std::cout << "cross1: " << abToApCross << std::endl;
	std::cout << "cross2: " << bcToBpCross << std::endl;
	std::cout << "cross3: " << caToCpCross << std::endl;

	const Fixed fixZero(0.0f);
	return ((abToApCross > fixZero && bcToBpCross > fixZero && caToCpCross > fixZero)
		||  (abToApCross < fixZero && bcToBpCross < fixZero && caToCpCross < fixZero));
}
