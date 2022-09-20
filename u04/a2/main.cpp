#include "CommonVector.h"
#include <string>

int main()
{
    CommonVector<int, 10> zahlen;
    for (int i=0; i < 10; ++i)
        zahlen[i] = (i+1) * (i+1);
    zahlen.print();

    CommonVector<char, 25> zeichen;
    //std::string str {"Hallo tolle C++ Welt"};
    char* str = "Hallo tolle C++ Welt";
    for (size_t i=0; i < zeichen.size(); ++i)
        zeichen[i] = str[i];
    zeichen.print();

    char* charKette[] = {"Hallo", "tolle", "C++", "Welt"};
    CommonVector<char*, 4> zeichenkette;
    for (size_t i=0; i < zeichenkette.size(); ++i)
        zeichenkette[i] = charKette[i];
    zeichenkette.print();
}