#ifndef LINE_H_
#define LINE_H_
#include "Point.h"

class Line
{
public:
    Line(Point start, Point end) : m_start(start), m_end(end) {}
    Line() : m_start(), m_end() {}

    Point get_start() const { return m_start; }
    Point get_end() const { return m_end; }

    void operator+=(Point other);
private:
    Point m_start;
    Point m_end;
};

bool operator==(Line a, Line b);

#endif