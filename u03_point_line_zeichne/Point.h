

#ifndef POINT_H_
#define POINT_H_


class Point {
public:

	Point () : _x(0), _y(0)  {}
	Point (int x, int y) : _x(x), _y(y)  {}

	int get_x() const { return _x; }
	int get_y() const { return _y; }

	Point& operator+= (Point a);

private:
	int _x;
	int _y;
};

bool operator==(Point a, Point b);


#endif /* POINT_H_ */
