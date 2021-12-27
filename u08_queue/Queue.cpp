
#include <cstddef>
#include <stdexcept>
#include "Queue.h"

#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
Queue<T>::Queue(size_t cap) : _cap(cap) {
	_head = 0;
	_tail = 0;
	_arr = new T[_cap];
}

template<typename T>
Queue<T>::~Queue() {
	delete[] _arr;
}

template<typename T>
bool Queue<T>::is_empty() const {
	return _head == _tail;
}

template<typename T>
bool Queue<T>::is_full() const {
	return (_tail + 1) % _cap == _head;
}

template<typename T>
T Queue<T>::front() const {
	if (is_empty()) {
		throw std::runtime_error("Queue::front(): QueueUnderflow");
	}
	return _arr[_head];
}

template<typename T>
void Queue<T>::enter(const T& ele) {
	if (is_full()) {
		throw std::runtime_error("Queue::enter: QueueOverflow");
	}
	_arr[_tail] = ele;
	_tail = (_tail + 1) % _cap;
}

template<typename T>
T Queue<T>::leave() {
	if (is_empty()) {
		throw std::runtime_error("Queue::leave: QueueUnderflow");
	}
	size_t retidx = _head;
	_head = (_head + 1) % _cap;
	return _arr[retidx];
}

#endif
