#include <iostream>
#include <vector>
#include <algorithm>
#include "ooptool.h"

using namespace std;

int main () {
	vector<int> a = create_randints(10, 1, 100);
	sort(a.rbegin(), a.rend());
	for (int i : a) {
		cout << i << " ";
	}

}


