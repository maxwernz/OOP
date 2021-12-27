

#ifndef LINKEDQUEUE_H_
#define LINKEDQUEUE_H_


template<typename T> class LinkedQueue {
public:
	LinkedQueue();
	~LinkedQueue();
	LinkedQueue(const LinkedQueue &other) = delete;
	LinkedQueue& operator=(const LinkedQueue &other) = delete;
	bool is_empty() const;
	size_t size() const;
	void enter (const T& t);
	T leave();
private:
	struct _node {
		T val;
		_node* next;
	};
	_node* _head;
	_node* _tail;
};

#include "LinkedQueue.cpp"

#endif /* LINKEDQUEUE_H_ */
