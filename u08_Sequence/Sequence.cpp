
#include "Sequence.h"

#ifndef SEQUENCE_CPP_
#define SEQUENCE_CPP_

template<typename T>
Sequence<T>::Sequence (size_t cap) : _cap(cap) {
	_array = new T[_cap];
	_size = 0;
}


template<typename T>
Sequence<T>::~Sequence() {
	delete[] _array;
}

template<typename T>
Sequence<T>::Sequence (const Sequence& other) : _cap(other._cap), _size(other._size) {
	_array = new T[_cap];
	for (size_t i = 0; i < _size; i+=1) {
		_array[i] = other._array[i];
	}
}

template<typename T>
Sequence<T>& Sequence<T>::operator= (const Sequence& other) {
	Sequence tmp(other);
	std::swap(_cap, tmp._cap);
	std::swap(_size, tmp._size);
	std::swap(_array, tmp._array);
	return *this;
}

template<typename T>
T& Sequence<T>::operator [](size_t pos) {
	if (pos >= _size) {
		throw std::runtime_error("Sequence::operator[]: pos out of bounds");
	}
	return _array[pos];
}

template<typename T>
const T& Sequence<T>::operator [](size_t pos) const {
	if (pos >= _size) {
		throw std::runtime_error("Sequence::operator[]: pos out of bounds");
	}
	return _array[pos];
}

template<typename T>
void Sequence<T>::insert(size_t pos, const T& ele) {
	 if (is_full()) {
		 //throw std::runtime_error("Sequence::insert: is full");
		 size_t incre = (_cap / 2.0) + 0.5;
		 resize(incre);
		 std::cout << "New capacity: " << capacity() << std::endl;
	 }
	 if (pos > _size) {
		 throw std::runtime_error("Sequence:insert: pos out of bounds");
	 }
	 for (size_t i = _size; i > pos; i-=1) {
		 _array[i] = _array[i - 1];
	 }

	 _size += 1;
	 _array[pos] = ele;
}

template<typename T>
void Sequence<T>::push_back(const T& ele) {
	insert(_size, ele);
}

template<typename T>
void Sequence<T>::remove(size_t pos) {
	if (pos >= _size) {
		throw std::runtime_error("Sequence::remove: pos out of bounds");
	}
	_size -= 1;
	for (size_t i = pos; i < _size; i+=1) {
		_array[i] = _array[i + 1];
	}
}

template<typename T>
bool Sequence<T>::remove_ele(const T& ele) {
	size_t pos = 0;
	while (pos < _size && !(_array[pos] == ele)) {
		pos += 1;
	}
	if (pos < _size) {
		remove(pos);
		return true;
	}
	return false;
}

template<typename T>
void Sequence<T>::resize(size_t n) {
	_cap += n;
}


#endif
