#include "common.h"
#include "ooptool.h"
#include <algorithm>


template<typename Iter>
Iter not_less_than(Iter start, Iter end, int val) { //my lower_bound
	Iter it;
	auto count = std::distance(start, end);
	auto step = count;

	if (count == 0) {
		return end;
	}

	while (count > 0) {
		it = start;
		step = count / 2;
		std::advance(it, step);
		if (!(val <= *it)) {
			start = ++it;
			count -= step + 1;
		} else {
			count = step;
		}
	}
	return start;
}



template<typename Iter>
Iter my_find(Iter first, Iter last, int val) {
	for (; first != last; ++first) {
		if (*first == val) {
			return first;
		}
	}
	return last;
}



template<typename Iter>
Iter binary_find(Iter begin, Iter end, int val) {
	begin = std::lower_bound(begin, end, val);
	if (begin != end && !(val < *begin)) {
		return begin;
	}
	return end;
}






template<typename Cont>
int search_sorted(int m, Cont& numbers, const std::vector<int>& rand_ints) {
 	int drin=0;
 	if (!numbers.empty()) {
		for (auto search_it=rand_ints.begin()+m; search_it != rand_ints.end(); ++search_it) {
			auto it=numbers.begin();
			while (*search_it > *it && it != numbers.end()) {
				++it;
			}
			if (it != numbers.end() && *it == *search_it) {
				drin+=1;
			}
		}
 	}
	return drin;
}

template<typename Cont,typename Iter>
void insert_sorted (Iter rand_it_begin, int part_size, Cont& numbers) {
	for(auto rand_it=rand_it_begin; rand_it != rand_it_begin + part_size; ++rand_it) {

		auto insit = not_less_than(numbers.begin(), numbers.end(), *rand_it);

		if (insit != numbers.end() && *insit != *rand_it) {
			numbers.insert(insit, *rand_it);
		}
		else if (insit == numbers.end()){
			numbers.push_back(*rand_it);
		}
	}
}



template<typename Cont, typename Iter>
void remove_sorted (Iter rand_it_begin, int part_size, Cont& numbers) {
	for (auto rand_it=rand_it_begin; rand_it != rand_it_begin+part_size; ++rand_it) {
		auto remvit = std::find(numbers.begin(), numbers.end(), *rand_it);
		if (remvit != numbers.end()) {
			numbers.erase(remvit);
		}
	}
}



int search_a1(int m, std::vector<int>& numbers, const std::vector<int>& rand_ints) {
	int drin=0;
	for (auto search_it=rand_ints.begin()+m; search_it != rand_ints.end(); ++search_it) {
		if (my_find(numbers.begin(), numbers.end(), *search_it) != numbers.end()) {
			drin+=1;
		}
	}
	return drin;
}

void out_ins (size_t size, int drin, std::string ins, std::string t_find) {
	std::cout << "anz=     " << size << " drin=        " << drin;
	std::cout << "     Einf=" << ins << " Such= " << t_find << std::endl;
}

void out_rem (size_t size, int drin, std::string remv, std::string t_find) {
	std::cout << "anz=     " << size << " drin=        " << drin;
	std::cout << "     Entf=" << remv << " Such= " << t_find << std::endl;
}





void insert_a1 (int m, int p, int part_size, std::vector<int>& numbers, const std::vector<int>& rand_ints) {
	auto rand_it_begin = rand_ints.begin();
	while (p-- > 0) {
		Timer t_insert;
		for (auto it=rand_it_begin; it != rand_it_begin + part_size; ++it) {
			numbers.push_back(*it);
		}
		std::string ins = t_insert.humanMeasure();

		rand_it_begin += part_size;

		Timer t_find;
		int drin = search_a1(m, numbers, rand_ints);

		out_ins(numbers.size(), drin, ins, t_find.humanMeasure());
	}
}

void remove_a1(int m, int p, int part_size, std::vector<int>& numbers, const std::vector<int>& rand_ints) {
	auto rand_it_begin = rand_ints.begin();
	while (p-- > 0) {
		Timer t_remove;
		for (auto it = rand_it_begin; it != rand_it_begin + part_size; ++it) {
			numbers.erase(numbers.begin());
		}
		std::string remv = t_remove.humanMeasure();

		rand_it_begin += part_size;

		Timer t_find;
		int drin = search_a1(m, numbers, rand_ints);

		out_rem(numbers.size(), drin, remv, t_find.humanMeasure());
	}
}





void insert_a2(int m, int p, int part_size, std::vector<int>& numbers, const std::vector<int>& rand_ints) {
	auto rand_it_begin = rand_ints.begin();
	while (p-- > 0) {

		Timer t_insert;
		insert_sorted(rand_it_begin, part_size, numbers);
		std::string ins = t_insert.humanMeasure();

		rand_it_begin += part_size;

		Timer t_find;
		int drin=search_sorted(m, numbers, rand_ints);

		out_ins(numbers.size(), drin, ins, t_find.humanMeasure());
	}
}


void remove_a2 (int m, int p, int part_size, std::vector<int>& numbers, const std::vector<int>& rand_ints) {
	auto rand_it_begin = rand_ints.begin();
	while (p-- > 0) {
		Timer t_remove;
		remove_sorted(rand_it_begin, part_size, numbers);
		std::string remv = t_remove.humanMeasure();

		rand_it_begin += part_size;

		Timer t_find;
		int drin=search_sorted(m, numbers, rand_ints);

		out_rem(numbers.size(), drin, remv, t_find.humanMeasure());
	}
}





void insert_a3(int m, int p, int part_size, std::list<int>& numbers, const std::vector<int>& rand_ints) {
	auto rand_it_begin = rand_ints.begin();
	while (p-- > 0) {

		Timer t_insert;
		insert_sorted(rand_it_begin, part_size, numbers);
		std::string ins = t_insert.humanMeasure();

		rand_it_begin += part_size;

		Timer t_find;
		int drin=search_sorted(m, numbers, rand_ints);

		out_ins(numbers.size(), drin, ins, t_find.humanMeasure());
	}
}

void remove_a3(int m, int p, int part_size, std::list<int>& numbers, const std::vector<int>& rand_ints) {
	auto rand_it_begin = rand_ints.begin();
	while (p-- > 0) {
		Timer t_remove;
		remove_sorted(rand_it_begin, part_size, numbers);
		std::string remv = t_remove.humanMeasure();

		rand_it_begin += part_size;

		Timer t_find;
		int drin = search_sorted(m, numbers, rand_ints);

		out_rem(numbers.size(), drin, remv, t_find.humanMeasure());
	}
}





void insert_a4(int m, int p, int part_size, orderedset& numbers, const std::vector<int>& rand_ints) {
	auto rand_it_begin = rand_ints.begin();
	while (p-- > 0) {
		Timer t_insert;
		for (auto it = rand_it_begin; it != rand_it_begin + part_size; ++it) {
			numbers.insert(*it);
		}

		std::string ins = t_insert.humanMeasure();

		rand_it_begin += part_size;

		Timer t_find;
		int drin = search_sorted(m, numbers, rand_ints);

		out_ins(numbers.size(), drin, ins, t_find.humanMeasure());
	}
}

void remove_a4(int m, int p, int part_size, orderedset& numbers, const std::vector<int>& rand_ints) {
	auto rand_it_begin = rand_ints.begin();
	while (p-- > 0) {
		Timer t_remove;
		for (auto it = rand_it_begin; it != rand_it_begin + part_size; ++it) {
			numbers.remove(*it);
		}
		std::string remv = t_remove.humanMeasure();

		rand_it_begin += part_size;

		Timer t_find;
		int drin = search_sorted(m, numbers, rand_ints);

		out_rem(numbers.size(), drin, remv, t_find.humanMeasure());
	}
}







