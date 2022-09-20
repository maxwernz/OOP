#include <iostream>

void tausche(int*& a, int*& b);

int main() 
{
    int a = 1;
    int b = 2;

    int* p = &a;
    int* q = &b;

    tausche(p, q);

    std::cout << *p << ", " << *q << std::endl;
}

void tausche(int*& a, int*& b)
{
    int* hilf = a;
    a = b; 
    b = hilf;
}
