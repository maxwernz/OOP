#include "String.h"

using namespace my;

String::String(const char* str)
{
    int m_size = std::strlen(str) + 1;
    m_string = new char[m_size];
    std::strcpy(m_string, str);
}


String::String(const String& str)
{
    m_size = str.m_size;
    m_string = new char[m_size];
    std::strcpy(m_string, str.m_string);
}

String& String::operator=(const String& str)
{
    if (this != &str)
    {
        delete[] m_string;
        m_size = str.m_size;
        m_string = new char[m_size];
        std::strcpy(m_string, str.m_string);
    }
    return *this;
}


std::ostream& operator<<(std::ostream& out, const String& str)
{
    out << str.getString();
    return out;
}

void my::strcat(String& a, String& b)
{
    a.m_size += b.m_size;
    std::strcat(a.m_string, b.m_string);
}