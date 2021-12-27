#include <iostream>

#include "Line.h"
#include "Point.h"
#include "ooptool.h"
#include "ooptoolg.h"

using namespace std;

int main () {
	Point a (2, 3);
	Point b (10, 12);
	Canvas c;
	c.add_line (a.get_x(), a.get_y(), b.get_x(), b.get_y());


}




