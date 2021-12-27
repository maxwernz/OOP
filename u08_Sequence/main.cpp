#include <iostream>
#include "Sequence.h"

using namespace std;

int main () {
	Sequence<int> a(1);
	while (a.capacity() <= 100) {
		a.push_back(17);
		cout << "cap: " << a.capacity() << endl;
	}
	cout << a[93] << endl;
}




