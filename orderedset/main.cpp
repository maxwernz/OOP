#include "orderedset.h"
#include "sorderedset.h"
#include "ooptool.h"
#include <algorithm>
#include <list>

void out(sorderedset& sp) {
	for (int i : sp) {
		std::cout << i << std::endl;
	}
}


int main () {
	sorderedset sp;
	sp.insert(3);
	sp.insert(7);
	sp.insert(5);
	out(sp);
	sp.remove(5);
	out(sp);
	std::cout << sp.search_ele(9) << std::endl;

}
