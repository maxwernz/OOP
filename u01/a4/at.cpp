#include "at.h"

int& at(int* vec, int len, int i)
{
    if (i > len - 1)
        throw std::runtime_error("index overflow");
    else
        return vec[i];
}
