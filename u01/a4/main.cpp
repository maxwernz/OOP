
#include "at.h"


int main()
{
    int* vec = new int[4] {};
    for (int i=0; i < 4; ++i)
    {
        vec[i] = i;
    }
    int test = at(vec, 4, 3);
    std::cout << test << std::endl;
}
