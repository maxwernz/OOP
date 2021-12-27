#include "Point.h"

#ifndef LINE_H_
#define LINE_H_

class Line {
public:
	Line (Point start, Point end) : _start(start), _end(end) {}
	Line () : _start(), _end(1,1) {}

	Point get_start() const { return _start; }
	Point get_end() const { return _end; }

	Line& operator+= (Point a);
private:
	Point _start;
	Point _end;
};

bool operator==(Line a, Line b);



#endif /* LINE_H_ */
