#ifndef COMMONVECTOR_H_
#define COMMONVECTOR_H_
#include <iostream>



template<typename T, size_t len>
class CommonVector
{
public:
    CommonVector();
    ~CommonVector();
    size_t size() const { return len; }
    T& operator[](size_t idx);
    void print() const;
private:
    T* m_array;
};

#include "CommonVector.cpp"

#endif