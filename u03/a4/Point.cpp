#include "Point.h"

void Point::operator+=(Point other)
{
    m_x += other.get_x();
    m_y += other.get_y();
}

bool operator==(Point a, Point b)
{
    if (a.get_x() == b.get_x() && a.get_y() == b.get_y())
        return true;
    return false;
}