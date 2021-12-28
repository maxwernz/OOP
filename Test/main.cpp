//iMax AccesToken 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


#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <functional>
#include "ooptool.h"
#include "common.h"
#include "orderedset.h"


#include "main.h"

using namespace std;






template<typename Cont>
void Test(Cont& a) {

}


int main () {
	vector<int> a = create_same_randints(80000);
	orderedset b;
	for (int i = 0; i < 10000; ++i) {
		b.insert(a[i]);
	}
	cout << is_sorted(b.begin(), b.end());
}


