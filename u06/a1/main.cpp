#include <vector>
#include "ooptool.h"

void insertionSort(std::vector<int>& vec)
{
    for (size_t i=0; i < vec.size(); ++i)
    {
        size_t j = i;
        while((j > 0) && (vec[j-1] > vec[j]))
        {
            swap(vec, j-1, j);
            j-=1;
        }
    }
}

void selectionSort(std::vector<int>& vec)
{
    for (size_t i=0; i < vec.size(); ++i)
    {
        size_t min = i;
        for (size_t j=i+1; j < vec.size(); ++j)
        {
            if (vec[min] > vec[j])
                min = j;
        }
        if (min != i)
            swap(vec, min, i);
    }
}

int main()
{
    std::vector<int> a = create_randints(10, 0, 100);
    std::vector<int> b = create_randints(10, 0, 100);
    insertionSort(a);
    int aError;
    if (!is_sorted(a, aError))
        std::cout << "NOT SORTED: " << aError << std::endl;
    else
        std::cout << "SORTED" << std::endl;
    check_sort(insertionSort, true, false);

    selectionSort(b);
    int bError;
    if (!is_sorted(b, bError))
        std::cout << "NOT SORTED: " << bError << std::endl;
    else
        std::cout << "SORTED" << std::endl;
    check_sort(selectionSort, true, false);
}