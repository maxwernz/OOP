#include <iostream>
#include <vector>
#include "ooptool.h"

using namespace std;


void sortfunc (vector<int>& a) {
	size_t vecsize = a.size();
	for (size_t i = 0; i < vecsize - 1; ++i) {
		size_t min = i;
		for (size_t j = i + 1; j < vecsize; ++j) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		if (min != i) {
			swap (a, min, i);
		}
	}
}


int main () {
	vector<int> a = create_randints (10, 0, 100);
	sortfunc (a);
	for (size_t i = 0; i < a.size(); ++i) {
		cout << a[i] << endl;
	}

	check_sort (sortfunc);

}
