#include "IntVector.h"
#include "ooptool.h"

void klappt()
{
    IntVector a(17);
    for (size_t i=0; i < a.size(); ++i)
    {
        a.at(i) = i;
    }

    std::cout << a.size() << std::endl;
    a.out();

    for (size_t i=0; i < a.size(); ++i)
    {
        if (i%2 == 0)
            a.at(i) += 42;
    }
    std::cout << a.size() << std::endl;
    a.out();
}

void crash()
{
    IntVector a(17);
    a.at(42);
}

int main(int argc, char* argv[])
{
    argsp_t argsp(argc, argv);
    if(argsp.flag("crash"))
        crash();
    klappt();
}

