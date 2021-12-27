#include "GraphicObject.h"
#include <cmath>

void Square::paint() {}

bool Square::is_in(int x, int y) const {
	return ((y > _y && y < _y + _width) && (x > _x && x < _x + _width));
}

void Circle::paint() {}

bool Circle::is_in(int x, int y) const {
	return sqrt(pow(( center_x - x), 2) + pow((center_y - y),2)) < radius;
}

void Rectangle::paint() {}

bool Rectangle::is_in(int x, int y) const {
	return ((y > _y && y < _y + _heigth) && (x > _x && x < _x + _length));
}

