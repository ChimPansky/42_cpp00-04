#include "Fixed.hpp"
#include "Point.hpp"


Point	vector(const Point& p1, const Point& p2) {
	Fixed	vX = p2.getX() - p1.getX();
	Fixed	vY = p2.getY() - p1.getY();
	return (Point(vX, vY));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Point	ab = b - a;
	Point	bc = vector(b, c);
	Point	ca = vector(c, a);
	Point	ap = vector(a, point);
	Point	bp = vector(b, point);
	Point	cp = vector(c, point);

	Fixed	abToApCross = Point::scalarProduct(ab, ap);
	Fixed	bcToBpCross = Point::scalarProduct(bc, bp);
	Fixed	caToCpCross = Point::scalarProduct(ca, cp);

	return ((abToApCross > 0 && bcToBpCross > 0 && caToCpCross > 0)
		|| (abToApCross < 0 && bcToBpCross < 0 && caToCpCross < 0));
}
