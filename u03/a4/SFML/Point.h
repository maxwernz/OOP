#ifndef POINT_H_
#define POINT_H_

class Point
{
public:
    Point(int x=0, int y=0) : m_x(x), m_y(y) {}

    int get_x() const { return m_x; }
    int get_y() const { return m_y; }

    void operator+=(Point other);
private:
    int m_x;
    int m_y;
};

bool operator==(Point a, Point b);

#endif

