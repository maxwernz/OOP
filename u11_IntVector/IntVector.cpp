#include <iostream>
#include "IntVector.h"
#include "Exception.h"


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

int& IntVector::operator [](size_t idx) {
	if (idx >= _length) {
		std::cerr << "Fehler: Index " << idx << " ungueltig" << std::endl;
		throw std::runtime_error ("Index overflow");
	}
	return _array[idx];
}

IntVector::IntVector (const IntVector& other) {
	_length = other._length;
	_array = new int [_length];
	for (size_t i = 0; i < _length; i++) {
		_array [i] = other._array [i];
	}
}


IntVector::	~IntVector () {
//	std::cout << "delete" << std::endl;
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
	try {
		if (idx < _length) {
			throw UnderflowException(idx);
		}
		if (idx >= _length) {
			throw OverflowException(idx);
		}
		if (size() == 0) {
			throw EmptyException();
		}
		return _array[idx];
	} catch(UnderflowException& e) {

	}
//	if (idx < _length) {
//		return _array[idx];
//	}
//	else {
//
//		throw std::runtime_error ("index out of range");
//		//delete[] _array;
//	}
}

void IntVector::out() {
	for (size_t i = 0; i < _length; i++) {
		std::cout << _array[i] << std::endl;
	}
}

size_t IntVector::remove_even() {
	size_t counter = 0;
	for (size_t i = 0; i < _length; ++i) {
		if ((at(i) % 2) == 0) {
			counter += 1;
		}
	}
	IntVector not_even (_length - counter);
	size_t j = 0;
	for (size_t i = 0; i < _length; ++i) {
		if ((at(i) % 2) == 1) {
			not_even.at(j++) = at(i);
		}
	}
	*this = not_even;
	return counter;
}

size_t IntVector::count_negative() const {
	size_t counter = 0;
	for (size_t i = 0; i < _length; i += 1) {
		if (_array[i] < 0) {
			counter += 1;
		}
	}
	return counter;
}

void IntVector::trim(size_t l) {
	if (_length >= l) {
		IntVector a(l);
		for (size_t i = 0; i < l; i+=1) {
			a[i] = _array[i];
		}
		*this = a;
	}
}
//
//IntVector reverse_copy(const IntVector& iv) {
//	size_t size = iv.size();
//	IntVector a(size);
//	size_t counter = size - 1;
//	for (size_t i = 0; i < size; i += 1) {
//		a[i] = iv[counter--];
//	}
//	return a;
//}

IntVector operator+(IntVector left, IntVector right) {
	if (left.size() == right.size()) {
		for (size_t i = 0; i < left.size(); i += 1) {
			left[i] += right[i];
		}
	}
	return left;
}

template<typename T>
int minimum(T vec) {
    int min = vec[0];
    for(size_t i = 0; i < vec.size(); i += 1) {
        if (vec[i] < min) {
            min = vec[i];
        }
    }
    return min;
}

typename IntVector::Iterator IntVector::begin() const {
	return Iterator(_array, _length);
}

typename IntVector::Iterator IntVector::end() const {
	return Iterator(_array + _length, _length);
}

int& IntVector::Iterator::operator *() {
	if (arr == arr + l) {
		throw std::runtime_error("IntVector::Iterator::operator*: end");
	}
	return *arr;
}

typename IntVector::Iterator& IntVector::Iterator::operator ++() {
	if (arr == arr + l) {
		throw std::runtime_error("IntVector::Iterator::operator++: end");
	}
	arr++;
	return *this;
}

bool IntVector::Iterator::operator==(const Iterator& other) const {
	return arr == other.arr;
}

bool IntVector::Iterator::operator!=(const Iterator& other) const {
	return arr != other.arr;
}




