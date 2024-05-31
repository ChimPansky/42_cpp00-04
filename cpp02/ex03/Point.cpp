#include "Point.hpp"
#include <iostream>


Point::Point()
	: _x(0.0f), _y(0.0f) {};

Point::Point(const float x, const float y)
	: _x(x), _y(y) {}

Point::Point(const Fixed& x, const Fixed& y)
	: _x(Fixed(x)), _y(Fixed(y)) {}

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

Point	Point::operator+(const Point& other) {
	return (Point(this->getX() + other.getX(), this->getY() + other.getY()));
}

Point	Point::operator-(const Point& other) {
	return (Point(this->getX() - other.getX(), this->getY() - other.getY()));
}

Fixed Point::getX() const {
	return (Fixed(_x));
}

Fixed Point::getY() const {
	return (Fixed(_y));
}

const Fixed	Point::scalarProduct(const Point& p1, const Point& p2) {
	return (p1.getX() * p2.getY() - p1.getY() * p2.getX());
}

// vec1 x vec2 = vec1.x * vec2.y - vec1.y * vec2.x
Fixed	scalarProduct(const Point& p1, const Point& p2) {
	return (p1.getX() * p2.getY() - p1.getY() * p2.getX());
}

std::ostream& operator<<(std::ostream& outStream, const Point& PointObject) {
	outStream << "(" << PointObject.getX() << "/" << PointObject.getY() << ")";
	return (outStream);
}
