#include "Point.hpp"
#include <iostream>

Point::Point()
	: _x(0.0f), _y(0.0f) {};

Point::Point(const float x, const float y)
	: _x(x), _y(y) {}

Point::Point(const Fixed& x, const Fixed& y)
	: _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point& other)
	: _x(Fixed(other._x)), _y(Fixed(other._y)){};

Point& Point::operator=(const Point& other) {
	(void) other;
	return *this;
}

Point::~Point() {}

Point	Point::operator+(const Point& other) const {
	return (Point(this->getX() + other.getX(), this->getY() + other.getY()));
}

Point	Point::operator-(const Point& other) const {
	return (Point(this->getX() - other.getX(), this->getY() - other.getY()));
}

Fixed Point::getX() const {
	return (_x);
}

Fixed Point::getY() const {
	return (_y);
}

std::ostream& operator<<(std::ostream& outStream, const Point& PointObject) {
	outStream << "(" << PointObject.getX() << "/" << PointObject.getY() << ")";
	return (outStream);
}
