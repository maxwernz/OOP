#include "count.h"

#ifndef COUNT_CPP
#define COUNT_CPP

namespace my {

	template <typename Iter>
	int my_count(Iter anf, Iter end, int t) {
		int counter = 0;
		for (Iter it = anf; it != end; ++it) {
			if (*it == t) {
				counter+=1;
			}
		}
		return counter;
	}


	template <typename Iter, typename Pred>
	int my_count_if(Iter anf, Iter end, Pred pred) {
		int counter = 0;
		for (Iter it=anf; it != end; ++it) {
			if (pred(*it)) {
				counter+=1;
			}
		}
		return counter;
	}

}

#endif
