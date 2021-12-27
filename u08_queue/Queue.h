

#ifndef QUEUE_H_
#define QUEUE_H_


template<typename T> class Queue {
public:
	Queue(size_t cap);
	~Queue();
	Queue(const Queue &other) = delete;
	Queue& operator=(const Queue &other) = delete;
	bool is_empty() const;
	bool is_full() const;
	size_t capacity() const { return _cap - 1; }
	T front() const;
	void enter (const T& ele);
	T leave();
private:
	T* _arr;
	size_t _cap;
	size_t _head;
	size_t _tail;
};

#include "Queue.cpp"

#endif /* QUEUE_H_ */
