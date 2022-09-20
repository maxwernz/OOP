#ifndef LinkedQueue_cpp_
#define LinkedQueue_cpp_
#include "LinkedQueue.h"

template<typename T>
LinkedQueue<T>::LinkedQueue() {
    m_tail = nullptr;
    m_head = m_tail;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    while (m_head != m_tail) {
        m_node* todel = m_head;
        m_head = m_head->next;
        delete todel;
    }
}

template<typename T>
bool LinkedQueue<T>::isEmpty() const {
    return m_head == m_tail;
}

template<typename T>
size_t LinkedQueue<T>::size() const {
    m_node* help = m_head;
    size_t size = 0;
    while (help != m_tail) {
        help = help->next;
        size += 1;
    }
    return size;
}

template<typename T>
void LinkedQueue<T>::enter(const T& ins) {
    m_node* help = new m_node;
    help->next = m_head;
    help->val = ins;
    m_head = help;
}

template<typename T>
T LinkedQueue<T>::leave() {
    if (size() == 0)
        throw std::runtime_error ("Queue is already empty");
    if (size() == 1) {
        T ret = m_head->val;
        delete m_head;
        m_head = m_tail;
        return ret;
    }
    m_node* todel = m_head;
    
    while (todel->next->next != m_tail)
        todel = todel->next;
    
    T ret = todel->next->val;
    delete todel->next;
    todel->next = m_tail;
    return ret;
}

template<typename T>
typename LinkedQueue<T>::Iterator LinkedQueue<T>::begin() {
    return Iterator(m_head);
}

template<typename T>
typename LinkedQueue<T>::Iterator LinkedQueue<T>::end() {
    return Iterator(m_tail);
}

template<typename T>
T& LinkedQueue<T>::Iterator::operator*() {
    if (it_cur == nullptr)
        throw std::runtime_error("LinkedQueue::Iterator::operator*: end");
    return it_cur->val;
}

template<typename T>
typename LinkedQueue<T>::Iterator& LinkedQueue<T>::Iterator::operator++() {
    if (it_cur == nullptr)
        throw std::runtime_error ("LinkedQueue::Iterator::operator++: end");
    it_cur = it_cur->next;
    return *this;
}

template<typename T>
bool LinkedQueue<T>::Iterator::operator==(const Iterator &other) const {
    return it_cur == other.it_cur;
}

template<typename T>
bool LinkedQueue<T>::Iterator::operator!=(const Iterator &other) const {
    return it_cur != other.it_cur;
}


#endif
