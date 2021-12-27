#include <iostream>
#include "IntVector.h"


IntVector::IntVector (size_t length) : _length (length) {
	_array = new int [length];
	initialize ();
}

IntVector& IntVector::operator=(const IntVector& other) {
	if (this != &other) {
		delete[] _array;
		_length = other._length;
		_array = new int [_length];
		for (size_t i = 0; i < _length; i++) {
			_array[i] = other._array[i];
		}
	}
	return *this;
}

IntVector::IntVector (const IntVector& other) {
	_length = other._length;
	_array = new int [_length];
	for (size_t i = 0; i < _length; i++) {
		_array [i] = other._array [i];
	}
}


IntVector::	~IntVector () {
	delete[] _array;
}

void IntVector::initialize () {
	for (size_t i = 0; i < _length; i++) {
		_array [i] = i;
	}
}

void IntVector::add(int n, int idx) {
	_array[idx] += n;

}



int& IntVector::at(size_t idx) {
	if (idx  < _length) {
		return _array[idx];
	}
	else {

		throw std::runtime_error ("index out of range");
		//delete[] _array;
	}
}

void IntVector::out() {
	for (size_t i = 0; i < _length; i++) {
		std::cout << _array[i] << std::endl;
	}
}


