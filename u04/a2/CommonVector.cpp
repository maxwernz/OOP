#include "CommonVector.h"
#include <cstring>

#ifndef COMMONVECTOR_CPP_
#define COMMONVECTOR_CPP_

template<typename T, size_t len>
CommonVector<T, len>::CommonVector()
{
    m_array = new T[len] {};
}

template<typename T, size_t len>
CommonVector<T, len>::~CommonVector()
{
    delete[] m_array;
}

template<typename T, size_t len>
T& CommonVector<T, len>::operator[](size_t idx)
{
    if (idx >= len)
        throw std::runtime_error("CommonVector: index overflow");
    return m_array[idx];
}

template<typename T, size_t len>
void CommonVector<T, len>::print() const
{
    std::cout << "[ ";
    for (size_t i=0; i < len; ++i)
    {
        //if (i > 0 && i%10 == 0) { std::cout << std::endl << "   "; }
        std::cout << m_array[i] << " ";
    }
    std::cout << "]" << std::endl;;
}

#endif