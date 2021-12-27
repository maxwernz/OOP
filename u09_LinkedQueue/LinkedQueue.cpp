#include <cstddef>
#include <iostream>
#include "LinkedQueue.h"


#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

template<typename T>
LinkedQueue<T>::LinkedQueue() {
	_tail = nullptr;
	_head = _tail;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
	while ( _head != _tail) {
		_node* todel = _head;
		_head = _head->next;
		delete todel;
	}
}

template<typename T>
bool LinkedQueue<T>::is_empty() const {
	return _head == _tail;
}

template<typename T>
size_t LinkedQueue<T>::size() const {
	_node* h = _head;
	size_t size = 0;
	while (h != _tail) {
		h = h->next;
		size += 1;
	}
	return size;
}

template<typename T>
void LinkedQueue<T>::enter(const T& t) {
	if (size() == 0) {
		_node* h = new _node;
		h->next = _tail;
		h->val = t;
		_head = h;
		return;
	}
	_node* h = new _node;
	h->next = _head;
	h->val = t;
	_head = h;
}

template<typename T>
T LinkedQueue<T>::leave() {
	if (size() == 0) {
		throw std::runtime_error("LinkedQueue::leave: QueueUnderflow");
	}

//	if (size() == 1) {
//		T retval = _head->val;
//		_head = _tail;
//		return retval;
//	}


	_node* todel = _head;
	while (todel->next->next != _tail) {
		todel = todel->next;
	}
	T retval = todel->next->val;
	delete todel->next;
	todel->next = _tail;
	return retval;
}

#endif
