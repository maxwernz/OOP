#include "Bruch.h"

int ggt(int z, int n)
{
    while(z != 0)       
    {
        std::swap(z, n);
         z %= n;
    }
    return n;
}

void Bruch::normalize()
{
    if (m_nenner == 0)
    {
        std::cerr << "Fehler: Nenner gleich 0 -> wurde gleich 1 gesetzt" << std::endl;
        m_nenner = 1;
    }

    if (m_nenner < 0)
    {
        m_nenner *= -1;
        m_zaehler *= -1;
    }

    int gt = ggt(m_zaehler, m_nenner);
    m_zaehler /= gt;
    m_nenner /= gt;
}

Bruch::Bruch(int z, int n) : m_zaehler(z), m_nenner(n)
{
    normalize();
}

bool operator==(Bruch a, Bruch b)
{
    if (a.zaehler() == b.zaehler() && a.nenner() == b.nenner())
        return true;
    return false;
}

bool operator!=(Bruch a, Bruch b)
{
    if (a == b)
        return false;
    return true;
}

void Bruch::operator*=(Bruch other)
{
    m_zaehler *= other.zaehler();
    m_nenner *= other.nenner();
}

Bruch operator*(Bruch a, Bruch b)
{
    return Bruch(a.zaehler()*b.zaehler(), a.nenner()*b.nenner());
}

void Bruch::print()
{
    std::cout << m_zaehler << "/" << m_nenner << std::endl;
}