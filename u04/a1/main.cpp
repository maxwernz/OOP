#include <iostream>
#include <cstring>

template<typename T>
T max (T* vec, size_t len)
{
    T max = 0;
    for (size_t i=0; i < len; ++i)
    {
        if (vec[i] > max)
            max =  vec[i];
    }
    return max;
}

char* max(char** vec, size_t len)
{
    char* max = "";
    for (size_t i=0; i < len; ++i)
    {
        if (std::strcmp(vec[i], max) > 0)
            max = vec[i];
    }
    return max;
}

int main()
{
    int a[] = {1, 5, 2, 7, 18, 3};
    char* c[] = {"Hallo", "Hello"};
    std::cout << max(a, 6) << std::endl;
    std::cout << max(c, 2) << std::endl;
}