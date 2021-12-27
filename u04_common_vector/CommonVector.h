#include <iostream>

#ifndef COMMONVECTOR_H_
#define COMMONVECTOR_H_

template<typename T, size_t len> class CommonVector;

template<typename T, size_t len>
class CommonVector {
public:
	CommonVector();
	~CommonVector();
	CommonVector& operator=(const CommonVector& other);
//	{
//		if (this != &other) {
//			delete[] _array;
//			len = other.size();
//			_array = new T[len];
//		}
//		for (size_t i = 0; i < len; ++i) {
//			_array[i] = other._array[i];
//		}
//		return * this;
//	}



	size_t size() const { return len; }
	T& operator[] (size_t idx);
private:
	T* _array;
};





#include "CommonVector.cpp"

#endif /* COMMONVECTOR_H_ */
