#include "IntVector.h"

void copyassign()
{
    IntVector v1(17);
    for (size_t i=0; i < v1.size(); ++i)
    {
        v1.at(i) = i;
    }
    IntVector v2(v1);
    IntVector v3(10);
    v3 = v2;
    v1.out();
    v2.out();
    v3.out();
}


int main(int argc, char* argv[])
{
    copyassign();
}