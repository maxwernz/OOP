#include "ooptool.h"

int maxsub(std::vector<int>& numbers);

int main()
{
    std::vector<int> numbers = read_ints("/Users/max/development/OOP/u07/a1/maxsub.dat");
    std::cout << maxsub(numbers) << std::endl;
}

int maxsub(std::vector<int>& numbers)
{
    int max = 0;
    int summe = 0;
    for (size_t i=0; i < numbers.size(); ++i)
    {
        for (size_t j=i; j < numbers.size(); ++j)
        {
            summe += numbers.at(j);
            if (summe > max)
                max = summe;
        }
        summe = 0;
    }
    return max;
}