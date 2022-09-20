#include "IntVector.h"

IntVector::IntVector(size_t size) : m_size(size)
{
    m_array = new int[m_size]{0};
}

IntVector::IntVector(const IntVector& iv)
{
    m_size = iv.size();
    m_array = new int[m_size];
    for (size_t i=0; i<m_size; ++i)
    {
        m_array[i] = iv.m_array[i];
    }
}

IntVector::~IntVector()
{
    delete[] m_array;
}

IntVector& IntVector::operator=(const IntVector& iv)
{
    if (this != &iv)
    {
        delete[] m_array;
        m_size = iv.size();
        m_array = new int[m_size];
        for (size_t i=0; i<m_size; ++i)
        {
            m_array[i] = iv.m_array[i];
        }
    }
    return *this;
}

int& IntVector::operator[](size_t idx)
{
    if (idx > m_size)
    {
        delete[] m_array;
        throw std::runtime_error("index out of range");
    }

    return m_array[idx];
}

int& IntVector::at(size_t idx)
{
    if (idx > m_size)
    {
        delete[] m_array;
        throw std::runtime_error("index out of range");
    }
    
    return m_array[idx];
}

void IntVector::out()
{
    for (size_t i=0; i < m_size; ++i)
    {
        std::cout << m_array[i] << std::endl;
    }
}