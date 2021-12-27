#include "tausche.h"

void tausche (int*& a, int*& b) {
	 int* tmp = a;
	 a = b;
	 b = tmp;
}

