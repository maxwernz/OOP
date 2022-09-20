#ifndef BRUCH_H_
#define BRUCH_H_
#include <algorithm>
#include <iostream>

class Bruch
{
public:
    Bruch(int z=0, int n=1);
    int zaehler() const { return m_zaehler; }
    int nenner() const { return m_nenner; }

    void operator*=(Bruch other);

    void print();
private:
    int m_zaehler;
    int m_nenner;
    void normalize();
};

 Bruch operator* (Bruch a, Bruch b);

    bool operator==(Bruch a, Bruch b);
    bool operator!=(Bruch a, Bruch b);

#endif