#include "Line.h"

Line& Line::operator+= (Point a) {
	this->_end.operator +=(a);
	return *this;
}


bool operator== (Line a, Line b) {
	if (a.get_start() == b.get_start() && a.get_end() == b.get_end()) {
		return 1;
	}
	return 0;
}


