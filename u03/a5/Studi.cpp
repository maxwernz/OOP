#include "Studi.h"

Studi::Studi()
{
    m_matnr=999;
    m_vorname="Max";
    m_nachname="Mustermann";
}

std::ostream& operator<<(std::ostream& out, Studi stud)
{
    out << stud.matnr() << " " << stud.vorname() << " " << stud.nachname();
    return out;
}

std::ifstream& operator>>(std::ifstream& in, Studi& stud)
{
    in.operator>>(stud.m_matnr);
    in >> stud.m_vorname;
    in >> stud.m_nachname;
    return in;
}

bool operator==(Studi a, Studi b)
{
    return a.matnr() == b.matnr();
}

bool operator!=(Studi a, Studi b)
{
    return !(a==b);
}

bool operator>(Studi a, Studi b)
{
    return a.matnr() > b.matnr();
}

bool operator<(Studi a, Studi b)
{
    return a.matnr() < b.matnr();
}
