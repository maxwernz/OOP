//
//  Sequence.cpp
//  a1
//
//  Created by Maximilian Wernz on 12.09.22.
//

#ifndef Sequence_cpp_
#define Sequence_cpp_

#include "Sequence.hpp"


template<typename T> Sequence<T>::Sequence(size_t cap) : m_cap(cap)
{
    m_array = new T[m_cap];
    m_size = 0;
}
template<typename T> Sequence<T>::~Sequence()
{
     delete[] m_array;
}

template<typename T> Sequence<T>::Sequence(const Sequence& other) : m_cap(other.m_cap), m_size(other.m_size)
{
    m_array = new T[m_cap];
    for (size_t i=0; i < m_size; i+=1) {
            m_array[i] = other.m_array[i];
        }
}
template<typename T>
Sequence<T>& Sequence<T>::operator=(const Sequence& other)
{
    Sequence tmp(other);
    std::swap(m_cap, tmp.m_cap);
    std::swap(m_size, tmp.m_size);
    std::swap(m_array, tmp.m_array);
    return *this;
}

template<typename T> T& Sequence<T>::operator[](size_t pos)
{
    if (pos >= m_size)
    {
        std::string msg = "Sequence::operator[]: pos out of bounds";
        throw std::runtime_error(msg);
    }
    return m_array[pos];
}

template<typename T> const T& Sequence<T>::operator[](size_t pos) const
{
    if (pos >= m_size)
    {
        std::string msg = "const Sequence::operator[]: pos out of bounds";
        throw std::runtime_error(msg);
    }
    return m_array[pos];
}

template<typename T> void Sequence<T>::insert(size_t pos, const T& ele)
{
    if (isFull())
    {
        size_t inc = (m_cap / 2.0) + 0.5;
        resize(inc);
        std::cout << "New Capacity: " << m_cap << std::endl;
    }
    if (pos > m_size)
    {
        throw std::runtime_error("Sequence::insert: pos out of bounds");
    }
    // Alle Elemente hinter Einfügeposition nach hinten schieben
    for (size_t idx= m_size; idx > pos; idx-=1)
    {
        m_array[idx] = m_array[idx-1]; // Zuweisungsoperator für T notwendig
    }
    m_size += 1;
    m_array[pos] = ele; // Zuweisungsoperator für T notwendig
}

template<typename T> void Sequence<T>::pushBack(const T& ele)
{
    insert(m_size, ele);
}

template<typename T> void Sequence<T>::remove(size_t pos)
{ // Alle Elemente vor Löschposition nach vorne
    if (pos >= m_size)
    {
        throw std::runtime_error("Sequence::remove: pos out of bounds");
    }
    m_size -= 1;
    for (size_t idx=pos; idx < m_size; idx+=1)
    {
        m_array[idx] = m_array[idx+1];
    }
}

template<typename T> bool Sequence<T>::removeEle(const T& ele)
{
    // Suche erstes Vorkommen und entferne gdw gefunden
    size_t pos = 0;
    while (pos < m_size && !(m_array[pos] == ele))
    { // == notwendig
        pos += 1;
    }
    if (pos < m_size)
    {
        remove(pos); return true;
    }
    return false;
}

template<typename T> void Sequence<T>::resize(size_t n)
{
    m_cap += n;
    Sequence<T> help(*this);
    *this = help;
}

template<typename T> void show(const Sequence<T>& seq)
{
    std::cout << "[" << seq.size() << "/" << seq.capacity() << "] ";
    for (size_t pos=0; pos < seq.size(); pos+=1)
        std::cout << seq[pos] << " ";
    std::cout << std::endl;
}


#endif
