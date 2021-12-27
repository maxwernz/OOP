#include <iostream>
#include <vector>
#include "IntVector.h"
#include "ooptool.h"


using namespace std;

void klappt();

void crash ();

void copyassign ();

int main (int argc, char* argv[]) {
	IntVector a(8);
	a.initialize();
	a.out();
	vector<int> b {17, 21, 14, 13, 17, 11, 3};
	cout << minimum(a) << endl;
	cout << minimum(b) << endl;
	a.trim(5);
	a.out();
}

void crash () {
	IntVector a (17);
	a[42];
}

void klappt () {
	IntVector a (17);
	cout << "size: " << a.size() << endl;

	a.out();

	for (size_t i = 0; i < a.size(); i++) {
		if (i % 2 == 0) {
			a.add(42, i);
		}
	}

	cout << "size: " << a.size() << endl;
	a.out();
}

void copyassign () {
	IntVector v1 (17);
	IntVector v2 (v1);
	IntVector v3 (10);
	v3 = v2;

	v1.out();
	v3.out();

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



