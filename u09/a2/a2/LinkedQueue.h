
#ifndef LinkedQueue_h_
#define LinkedQueue_h_

#include <iostream>
template <typename T>
class LinkedQueue {
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
};

#include "LinkedQueue.cpp"

#endif
