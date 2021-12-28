#include "orderedset.h"
#include <iostream>
#include <algorithm>
#include <list>




void test(std::vector<int>& b) {
	std::list<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(4);


}


int main () {
	std::vector<int> a;
	for (int i=0; i < 10; ++i) {
		a.push_back(rand());
	}
	test(a);
}




