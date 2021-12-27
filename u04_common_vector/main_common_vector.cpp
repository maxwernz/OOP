#include "CommonVector.h"

int main () {
	CommonVector<int, 3> a;
	for (int i = 0; i < 3; i++) {
		a[i] = i + 1;
	}
	CommonVector<int, 3> b;
	for (int i = 0; i < 3; i++) {
		b[i] = i + 3;
	}
	a = b;
	for (int i = 0; i < 3; i++) {
		std::cout << a[i] << std::endl;
	}
}




