#include "CommonVector.h"


#ifndef COMMONVECTOR_CPP_
#define COMMONVECTOR_CPP_


template<typename T, size_t len>
CommonVector<T, len>::CommonVector() {
	_array = new T[len];
}

template<typename T, size_t len>
CommonVector<T, len>::~CommonVector() {
	delete[] _array;
}

template<typename T, size_t len>
CommonVector<T, len>& CommonVector<T, len>::operator=(const CommonVector& other) {
		for (size_t i = 0; i < other.size(); i += 1) {
			_array[i] = other._array[i];
		}

	return *this;
}


template<typename T, size_t len>
T& CommonVector<T, len>::operator[] (size_t idx) {
	if (idx >= len) {
		std::cerr << "Fehler: Index " << idx << " ungueltig" << std::endl;
		throw std::runtime_error("Index overflow");
	}
	return _array[idx];
}

#endif
