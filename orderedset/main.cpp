#include "orderedset.h"
#include "ooptool.h"
#include <algorithm>
#include <list>

template<typename Cont>
int search_sorted(int m, Cont& numbers, const std::vector<int>& rand_ints) {
	int drin=0;
	for (auto search_it=rand_ints.begin()+m; search_it != rand_ints.end(); ++search_it) {
		auto it=numbers.begin();
		while (*search_it > *it && it != numbers.end()) {
			++it;
		}
		if (it != numbers.end() && *it == *search_it) {
			drin+=1;
		}
	}
	return drin;
}



void test(std::vector<int>& b) {

}


int main () {
	std::vector<int> test = {2, 4, 6, 1, 8, 2, 0, 98 };
	orderedset a;
	for (int i : test) {
		a.insert(i);
	}
	for (int i : a) {
		std::cout << i << std::endl;
	}
	for (int i : test) {
		a.remove(i);
		std::cout << "y ";
	}
	std::cout << a.size() << std::endl;
}
