#include <iostream>
#include "Line.h"

int main()
{
    Point a;
    std::cout << a.get_x() << " " << a.get_y() << std::endl;

    Line b;
    std::cout << b.get_start().get_x() << " " << b.get_start().get_y() << std::endl;
}