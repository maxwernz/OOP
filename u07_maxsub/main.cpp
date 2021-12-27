#include <iostream>
#include <vector>
#include "ooptool.h"

using namespace std;

int maxsub (vector<int> a) {
	int maxsub = 0;
	int sum;

	for (size_t i = 0; i < a.size(); ++i) {
		for (size_t j = i; j < a.size(); ++j) {
			sum = 0;
			for (size_t k = i; k < j; ++k) {
				sum += a[k];
				if (sum > maxsub) {
					maxsub = sum;
				}
			}
		}
	}
	return maxsub;
}

int maxsub_better (vector<int> a) {
	int maxsub = 0;
	int sum;
	for (size_t i = 0; i < a.size(); ++i) {
		sum = 0;
		for (size_t j = i; j < a.size(); ++j) {
			sum += a[j];
			if (sum > maxsub) {
				maxsub = sum;
			}
		}
	}
	return maxsub;
}

int main () {
	vector<int> a = read_ints("maxsub.dat");
	vector<int> b = {31, -4, 59};
	cout << maxsub_better (a) << endl;

}


