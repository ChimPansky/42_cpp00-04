#pragma once

#include "Fixed.hpp"
#include <ostream>

class Point {
  private:
	const Fixed	_x;
	const Fixed	_y;

  public:
	// constructors
  	Point();
	Point(const float x, const float y);
	Point(const Point& other);

	// copy assignment operator overload:
	Point& operator=(const Point& other);

	// destructor
	~Point();

	// getter and setter:
	Fixed	getX() const;
	Fixed	getY() const;

};

std::ostream& operator<<(std::ostream& outStream, const Point& pointObject);
