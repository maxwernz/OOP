#include <fstream>
#include "ooptool.h"

int main()
{

    std::ifstream file ("numbers1.txt");
    int number;
    while(file >> number)
        std::cout << number << std::endl;
    // Alternativ
    // std::vector<int> numbers = read_ints("numbers1.txt");
    // for (int i : numbers)
    //     std::cout << i << std::endl;
}