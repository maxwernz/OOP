

#ifndef COUNT_H_
#define COUNT_H_


namespace my {

	template <typename Iter>
	int my_count(Iter anf, Iter end, int t);

	template <typename Iter, typename Pred>
	int my_count_if(Iter anf, Iter end, Pred pred);

}

#include "count.cpp"


#endif /* COUNT_H_ */
