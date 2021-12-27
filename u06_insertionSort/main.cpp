#include <iostream>
#include <vector>
#include "ooptool.h"

using namespace std;


void sortfunc(vector<int>& a) {
	size_t vecsize = a.size();
	for (size_t i = 0; i < vecsize; ++i) {
		size_t j = i;
		while ((j > 0) && (a[j - 1] > a[j])) {
			swap (a, j - 1, j);
			j -= 1;
		}
	}
}


int main () {
	vector<int> a = create_randints (10, 0, 100);
	sortfunc(a);
	int first_error;
	if ( !is_sorted(a, first_error)) {
	      cout << "NOT SORTED: " << first_error << endl;
		}
	else {
		cout << "SORTED" << endl;
	}

	for (size_t i = 0; i < a.size(); ++i) {
		cout << a[i] << endl;
	}
}




