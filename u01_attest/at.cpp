#include "at.h"

int& at(int* vec, int len, int i) {
	if (i + 1> len) {
		throw std::runtime_error ("index overflow");
	}
	else {
		return vec [i];
	}
}





