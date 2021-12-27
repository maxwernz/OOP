#include <iostream>
#include <algorithm>
#include "ooptool.h"
#include "count.h"


using namespace my;


int main () {
	std::vector<int> a = create_randints(10, 1 , 10);
	for (int i : a) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	auto even = [](int val) { return val%2 ==0; };
	std::cout << "count=" << count(a.begin(), a.end(), 3) << std::endl;
	std::cout << "my_count=" << my_count(a.begin(), a.end(), 3) << std::endl;
	std::cout << "count_if=" << count_if(a.begin(), a.end(), even) << std::endl;
	std::cout << "my_count_if=" << my_count_if(a.begin(), a.end(), even) << std::endl;
}




