#include <algorithm>
#include "ooptool.h"

void sortfunc(std::vector<int>& vec) //sinnvoll wenn breite der Zahlen nicht allzu groß ist -> Speicher für den 2. Vector da ist
{
    int max, min; //min = offset
    max = min = vec[0];

    for (int i : vec) //maximum wird bestimmt
    {
        if (i > max)
            max = i;
        if (i < min)
            min = i;
    }

    int vecsize = (max - min) + 1;
    std::vector<int> counter (vecsize);

    for (int i : vec) //vector wird durchlaufen und der counter entsprechend erhöht
    {
        counter[i - min] += 1; //-min ist der offset
    }
    int k = 0;
    for (size_t i=0; i < counter.size(); ++i) //vec wird sortiert überschrieben
    {
        while (counter[i]-- > 0)
        {
            vec[k] = i + min; //offset rückgängig machen
            k+=1;
        }
    }
}

void std_sort(std::vector<int>& vec)
{
    std::sort(vec.begin(), vec.end());
}

int main()
{
    std::cout << "std_sort" << std::endl;
    check_sort(std_sort, true, false);
    std::cout << "sortfunc" << std::endl;
    check_sort(sortfunc, true, false);
}