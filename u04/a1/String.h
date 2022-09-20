#ifndef STRING_H_
#define STRING_H_
#include <cstring>
#include <fstream>



namespace my 
{
    class String
    {
    public:
        String (const char* str="");
        String(const String& str);
        String& operator=(const String& str);
        char* getString() const { return m_string; }
        friend void strcat(String& a, String& b);
    private:
        int m_size;
        char* m_string;
    };

    void strcat(String& a, String& b);
}


std::ostream& operator<<(std::ostream& out, const my::String& str);

#endif