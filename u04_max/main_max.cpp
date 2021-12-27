#include <iostream>
#include <typeinfo>
#include <cstring>

using namespace std;


char* max (char* vec[], size_t len) {
	char* max = "";
	for (size_t i = 0; i < len; ++i) {
		if (strcmp (vec[i], max) > 0) {
			max = vec[i];
		}
	}
	return max;
}

template<typename T>
T max(T* vec, size_t len) {
	T max = 0;

	for (size_t i = 0; i < len; ++i) {
		if (vec[i] > max) {
			max = vec[i];
		}
	}
	return max;
}





int main () {
	int a[] = {1, 5, 2, 6, 8, 9, 18, 278};
	char* c[] = {"Hallo", "Hello"};
	cout << max (a, sizeof(a) / sizeof(int)) << endl;
	cout << max (c, sizeof(c) / sizeof(char*)) << endl;
}
