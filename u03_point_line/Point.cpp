#include "Point.h"

Point& Point::operator +=(Point a) {
	this->_x += a._x;
	this->_y += a._y;
	return *this;
}


bool operator==(Point a, Point b) {
	if (a.get_x() == b.get_x() && a.get_y() == a.get_y()) {
		return 1;
	}

	return 0;
}

