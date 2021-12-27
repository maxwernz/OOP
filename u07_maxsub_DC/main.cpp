#include <iostream>
#include <vector>
#include "ooptool.h"

using namespace std;


int partleft (vector<int> a, int li, int re) {
	int sum = 0;
	int max = 0;
	for(int i = re; i >= li; --i) {
		sum += a[i];
		if (sum > max) {
			max = sum;
		}
	}
	return max;
}

int partright (vector<int> a, int li, int re) {
	int sum = 0;
	int max = 0;
	for (int i = li; i <= re; ++i) {
		sum += a[i];
		if (sum > max) {
			max = sum;
		}
	}
	return max;
}

int max (int ml, int mm, int mr) {
	if (ml > mm && ml > mr) {
		return ml;
	} else if (mr > ml && mr > mm) {
		return mr;
	}
	return mm;
}

int maxsub_DC (vector<int> a, int li, int re) {
	int maxsub;

	if (li == re) {
		return a[li];
	}

	int mid = li + (re - li)/2;


	int maxli = maxsub_DC (a, li, mid);
	int maxre = maxsub_DC (a, mid + 1, re);
	int ml = partleft (a, li, mid);
	int mr = partright (a, mid + 1, re);

	maxsub = max(maxli, ml + mr, maxre);
	return maxsub;
}

int main () {
	Timer timer;
	vector<int> a = read_ints("maxsublarge.dat");
	int max = maxsub_DC (a, 0, a.size() - 1);
	cout << max << endl;
	cout << timer.humanMeasure() << endl;
}

//int part (vector<int> a, int li, int re) {
//	int sum = 0;
//	int max = 0;
//	if (li < re) {
//		for (int i = re; i >= li; --i) {
//			sum += a[i];
//			if (sum > max) {
//				max = sum;
//			}
//		}
//	} else if (li > re) {
//		for (int i = re; i <= li; ++i) {
//			sum += a[i];
//			if (sum > max) {
//				max = sum;
//			}
//		}
//	}
//	else {
//		max = a[li];
//	}
//	return max;
//}
