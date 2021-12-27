#include <iostream>
#include <vector>
#include "ooptool.h"

using namespace std;




void sortfunc (vector<int>& a, size_t li, size_t re) {
	if (li == re) {
		return;
	}
	size_t start = li, end = re;
	size_t m = li + (re - li) / 2;
	int pivot = a[m];
	do {
		while (a[li] < pivot) {
			li += 1;
		}
		while (a[re] > pivot) {
			re -= 1;
		}
		if (li < re) {
			swap (a, li++, re--);
		} else if (li == re) {
			if (li == start) {
				li += 1;
			}
			else {
				re -= 1;
			}
		} else {
		}
	} while (li <= re);
	sortfunc(a, start, re);
	sortfunc (a, li, end);
}

void sortfunc (vector<int>& a) {
	sortfunc(a, 0, a.size() - 1);
}


int main () {
	vector<int> a = { 23, 7, 2, 21, 16, 25, 12, 17 };
	sortfunc (a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) {
		cout << a[i] << endl;
	}

	check_sort (sortfunc, true, true);
}




