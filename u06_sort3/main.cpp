#include <iostream>
#include <vector>
#include <algorithm>
#include "ooptool.h"

//Vorraussetzung: Speicher fuer zweiten Vector verfuegbar
//Komplex: O(n)

using namespace std;

void std_sort(vector<int>& a) {
	std::sort(a.begin(), a.end());
}


void sortfunc (vector<int>& a) {
	size_t vecsize = a.size();
	int max ,min;
	max = min = a[0];

	for (size_t i=0; i < vecsize; ++i) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min  = a[i];
		}
	}

	int size = (max - min) + 1;
	vector<int> counter(size);

	int j;
	for (size_t i = 0; i < vecsize; ++i) {
		j = a[i];
		counter[j - min] += 1;
	}

	int k = 0;
	for (size_t i=0; i < counter.size(); ++i) {
		while (counter[i] > 0) {
			a[k] = i + min;
			k += 1;
			counter[i] -= 1;
		}
	}


}



int main () {
	cout << "std_sort" << endl;
	check_sort (std_sort, true, true);
	cout << "sortfunc" << endl;
	check_sort (sortfunc, true, true);
}



