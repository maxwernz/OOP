#ifndef INTVECTOR_H_
#define INTVECTOR_H_
#include <iostream>

class IntVector
{
public:
    IntVector(size_t size);
    IntVector(const IntVector& iv);
    ~IntVector(); //nötig für eigenständiges delete des angelegten Felds
    IntVector& operator=(const IntVector& iv);
    int& operator[](size_t idx);
    size_t size() const { return m_size; }
    int& at(size_t idx);
    void out();
private: 
    size_t m_size;
    int* m_array;
};

#endif
