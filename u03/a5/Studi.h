#ifndef STUDI_H_
#define STUDI_H_
#include <string>
#include <iostream>
#include <fstream>

class Studi
{
public:
    Studi();
    Studi(long matnr, std::string vorname, std::string nachname) : m_matnr(matnr), m_vorname(vorname), m_nachname(nachname) {}

    long matnr() const { return m_matnr; }
    std::string vorname() const { return m_vorname; }
    std::string nachname() const { return m_nachname; }
    friend std::ifstream& operator>>(std::ifstream& in, Studi& stud);
private:
    long m_matnr;
    std::string m_vorname;
    std::string m_nachname;
};

std::ostream& operator<<(std::ostream& out, Studi stud);

bool operator==(Studi a, Studi b);
bool operator!=(Studi a, Studi b);
bool operator>(Studi a, Studi b);
bool operator<(Studi a, Studi b);


#endif
