#include "ooptool.h"


bool Dame (int* damen , int n, int row, bool allSol, int& counter);
bool checkFree(int* damen , int row, int column);
void ausgabe(int* damen, int n);


int main(int argc, char* argv[])
{
    argsp_t argsp(argc, argv);
    int n = argsp.int_pos(0, 8);

    int damen[n];

    bool allSolutions = false;
    if (argsp.no_pos() > 1)
        allSolutions = true;

    int counter = 0;
    bool res = Dame(damen, n, 0, allSolutions, counter);

    if (allSolutions)
        std::cout << counter << std::endl;
    else if (res)
        ausgabe(damen, n);
    else
        std::cout << "Es wurde keine Lösung gefunden" << std::endl;
}

bool Dame(int* damen , int n, int row, bool allSol, int& counter)
{
    if (row == n)
    {
        if (allSol)
        {
            counter += 1;
            return false;
        }
        return true;
    }

    for (int column=0; column < n; ++column)
    {
        if (checkFree(damen, row, column))
        {
            damen[row] = column;            //am index (Zeilen) wird die Spalte gemerkt vgl. A1 oder E7
            if (Dame(damen, n, row+1, allSol, counter))
                return true;
        }
    }
    return false;
}

bool checkFree(int* damen , int row, int column)
{
    for (int cur=row-1; cur >= 0; --cur)
    {
        if (damen[cur] == column || abs(damen[cur] - column) == abs(cur - row)) //geht man gleich viele Felder links/rechts wie nach unten dann ist besetzt
            return false;
    }
    return true;
}

void ausgabe (int* damen , int n)
{
    for (int column=n-1; column >= 0; --column)
    {
        std::cout << column << "|";
        for (int row=0; row < n; ++row)
        {
            if (damen[row] == column)
                std::cout << "* ";
            else 
                std::cout << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}