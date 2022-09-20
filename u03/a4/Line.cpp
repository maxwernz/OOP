#include "Line.h"

void Line::operator+=(Point other)
{
    m_end += other;
}

bool operator==(Line a, Line b)
{
    if (a.get_start() == b.get_start() && a.get_end() == b.get_end())
        return true;
    return false;
}