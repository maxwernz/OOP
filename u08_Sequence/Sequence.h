#include <iostream>


#ifndef SEQUENCE_H_
#define SEQUENCE_H_

template <typename T> class Sequence {
public:
	Sequence (size_t cap);
	Sequence(const Sequence&);
	Sequence& operator=(const Sequence& other);
	~Sequence();
	size_t size() const { return _size; };
	size_t capacity() const { return _cap; };
	bool is_empty () const { return _size == 0; };
	bool is_full() const { return _cap == _size; };
	T& operator[](size_t pos);
	const T& operator[] (size_t pos) const;
	void insert (size_t pos, const T& ele);
	void push_back(const T& ele);
	void remove(size_t pos);
	bool remove_ele(const T& ele);
	void resize(size_t n);

private:
	T* _array;
	size_t _cap;
	size_t _size;
};

#include "Sequence.cpp"

#endif /* SEQUENCE_H_ */
