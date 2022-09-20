#include <iostream>
#include "ooptool.h"

int main (int argc, char* argv[]) 
{
    argsp_t argsp(argc, argv);

    double x = argsp.double_pos(0, 10.0);
    double eps = argsp.double_pos(1, 1e-6);


    double ai, aI, diff;

    ai = (1 + x) / 2.0;
    

    do 
    {
        aI = (ai + x / ai) / 2.0;
        diff = abs(ai - aI);
        ai = aI;
    } while (eps < diff);

    std::cout << "heron(" << x << ", " << eps << ") = " << ai << std::endl;
}