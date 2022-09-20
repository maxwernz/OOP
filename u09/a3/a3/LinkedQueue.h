
#ifndef LinkedQueue_h_
#define LinkedQueue_h_

#include <iostream>
template <typename T>
class LinkedQueue {
    class Iterator;
    struct m_node{
        T val;
        m_node* next;
    };
    m_node* m_head;
    m_node* m_tail;
    
public:
    LinkedQueue();
    ~LinkedQueue();
    LinkedQueue(const LinkedQueue& other) = delete;
    LinkedQueue& operator=(const LinkedQueue& other) = delete;
    bool isEmpty() const;
    size_t size() const;
    void enter(const T& ins);
    T leave();
    Iterator begin();
    Iterator end();
private:
    class Iterator {
        friend class LinkedQueue;
        Iterator(m_node* cur) :  it_cur(cur) {}
        m_node* it_cur;
    public:
        T& operator*();
        Iterator& operator++();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };
};

#include "LinkedQueue.cpp"

#endif
