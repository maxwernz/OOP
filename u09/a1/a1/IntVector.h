#ifndef INTVECTOR_H_
#define INTVECTOR_H_
#include <iostream>

class IntVector
{
    class Iterator;
public:
    IntVector(size_t size);
    IntVector(const IntVector& iv);
    ~IntVector(); //nötig für eigenständiges delete des angelegten Felds
    IntVector& operator=(const IntVector& iv);
    int& operator[](size_t idx);
    size_t size() const { return m_size; }
    int& at(size_t idx);
    void out();
    Iterator begin() const;
    Iterator end() const;
private: 
    size_t m_size;
    int* m_array;
    
    class Iterator
    {
        friend class IntVector;
    public:
        int& operator*();
        Iterator& operator++();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    private:
        Iterator(int* cur, size_t length) : it_cur(cur), it_length(length) {}
        int* it_cur;
        size_t it_length;
    };
};

#endif
