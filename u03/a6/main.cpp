#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "ooptool.h"

int main(int argc, char* argv[]) 
{
    argsp_t argsp(argc, argv);
    std::string filepath = "/Users/max/development/OOP/u03/a6/";
    std::fstream in(filepath + argsp.pos(0, "numbers.txt"));

    std::vector<int> numbers;
    int insert;
    while (in >> insert)
        numbers.push_back(insert);
    auto result = std::max_element(numbers.begin(), numbers.end());
    if (result != numbers.end())
        std::cout << *result << std::endl;
}