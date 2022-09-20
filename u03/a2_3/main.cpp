
#include "Bruch.h"

int main()
{
    Bruch a(2);
    Bruch b(3, 2);
    Bruch c(4, 2);
    if (a == c)
        std::cout << "a = c" << std::endl;
    if (a != b)
        std::cout << "a != b" << std::endl;
    Bruch d = 2 * Bruch(15, 4);
    d.print();
}