//
//  Sequence.hpp
//  a1
//
//  Created by Maximilian Wernz on 12.09.22.
//

#ifndef Sequence_hpp
#define Sequence_hpp
#include <iostream>


template<typename T> class Sequence
{
public:
    Sequence(size_t cap=1);
    Sequence(const Sequence&);
    Sequence& operator=(const Sequence&);
    ~Sequence();
    size_t size() const { return m_size; }
    size_t capacity() const { return m_cap; }
    bool isEmpty() const { return m_size == 0; }
    bool  isFull() const { return m_size == m_cap; }
    T& operator[] (size_t pos);
    const T& operator[](size_t pos) const;
    void insert(size_t pos, const T& ele);
    void pushBack(const T& ele);
    void remove(size_t pos);
    bool removeEle(const T& ele);
    void resize(size_t n);
private:
    T* m_array;
    size_t m_cap;
    size_t m_size;
};

template<typename T> void show(const Sequence<T>& seq);

#include "Sequence.cpp"

#endif /* Sequence_hpp */
