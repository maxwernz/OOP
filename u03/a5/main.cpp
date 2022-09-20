#include <vector>
#include <iostream>
#include "Studi.h"

int main()
{
    std::ifstream is("/Users/max/development/OOP/u03/a5/studis.txt");
    std::vector<Studi> studis;

    Studi s;
    while (is >> s)
        studis.push_back(s);

    for (Studi studi : studis)
        std::cout << studi << std::endl;
    // std::cout << "Hello" << std::endl;
}