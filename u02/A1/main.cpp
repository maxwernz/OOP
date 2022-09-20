#include "Time.h"

int main()
{
    Time time(0, 3, 24);

    time.print();
    time.add_seconds(-205);
    time.print();
}