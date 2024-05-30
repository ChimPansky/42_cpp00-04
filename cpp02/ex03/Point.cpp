#include "Point.hpp"
#include <iostream>


Point::Point()
	: _x(0.0f), _y(0.0f) {};

Point::Point(const float x, const float y)
	: _x(x), _y(y) { }


Point::Point(const Point& other) {
	(void)other;
};

Point& Point::operator=(const Point& other) {
	(void)other;
	return *this;
}

Point::~Point() {
	std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const {
	return (Fixed(_x));
}

Fixed Point::getY() const {
	return (Fixed(_y));
}

bool bsp( Point const a, Point const b, Point const c, Point const point);


std::ostream& operator<<(std::ostream& outStream, const Point& PointObject) {
	outStream << "(" << PointObject.getX() << "/" << PointObject.getX() << ")";
	return (outStream);
}
