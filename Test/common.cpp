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



int search_a1(int m, std::vector<int>& m_numbers, const std::vector<int>& rand_ints) {
	int drin=0;
	for (auto search_it=rand_ints.begin()+m; search_it != rand_ints.end(); ++search_it) {		//Fuer alle Suchzahlen in der Menge schauen ob sie vorkommen
		if (my_find(m_numbers.begin(), m_numbers.end(), *search_it) != m_numbers.end()) {
			drin+=1;
		}
	}
	return drin;
}



template<typename Cont>
int search_sorted(int m, Cont& m_numbers, const std::vector<int>& rand_ints) {
	int drin=0;
	for (auto search_it=rand_ints.begin()+m; search_it != rand_ints.end(); ++search_it) {
		auto it=m_numbers.begin();
		while (*search_it > *it && it != m_numbers.end()) {
			++it;
		}
		if (it != m_numbers.end() && *it == *search_it) {
			drin+=1;
		}
	}
	return drin;
}



template<typename Cont,typename Iter>
void insert_sorted (Iter rand_it_begin, int part_size, Cont& m_numbers) {
	for(auto rand_it=rand_it_begin; rand_it != rand_it_begin + part_size; ++rand_it) {

		auto insit = not_less_than(m_numbers.begin(), m_numbers.end(), *rand_it);

		if (insit != m_numbers.end() && *insit != *rand_it) {
			m_numbers.insert(insit, *rand_it);
		}
		else if (insit == m_numbers.end()){
			m_numbers.push_back(*rand_it);
		}
//		if (m_numbers.size() == 0) {
//			m_numbers.push_back(*rand_it);
//			continue;
//		}
//		auto insitr = not_greater_than(m_numbers.begin(), m_numbers.end(), *rand_it);
//		if (*insitr != *rand_it) {
//			m_numbers.insert(insitr, *rand_it);
//		}


	}
}



template<typename Cont, typename Iter>
void remove_sorted (Iter rand_it_begin, int part_size, Cont& m_numbers) {
	for (auto rand_it=rand_it_begin; rand_it != rand_it_begin+part_size; ++rand_it) {
		auto remvit = std::find(m_numbers.begin(), m_numbers.end(), *rand_it);
		if (remvit != m_numbers.end()) {
			m_numbers.erase(remvit);
		}
//		for (auto remove_it=m_numbers.begin(); remove_it != m_numbers.end(); ++remove_it) {
//			if (*rand_it == *remove_it) {
//				m_numbers.erase(remove_it);
//				break;
//			}
//		}
	}
}



void insert_a1(int& anz, int part_size, int m, std::vector<int>& m_numbers, const std::vector<int>& rand_ints) {
	while (anz != m) {

		Timer t_insert;
		for (int i=0; i < part_size; ++i) {
			m_numbers.push_back(rand_ints[i + anz]);
		}
		std::string ins = t_insert.humanMeasure();


		Timer t_find;
		int drin=search_a1(m, m_numbers, rand_ints);


		anz += part_size;

		std::cout << "anz=     " << anz << " drin=        " << drin;
		std::cout << "     Einf=" << ins << " Such= " << t_find.humanMeasure() << std::endl;
	}
}



void remove_a1(int& anz, int part_size, int m, std::vector<int>& m_numbers, const std::vector<int>& rand_ints) {
	while (anz != 0) {

		Timer t_remove;
		for (int i=0; i < part_size; ++i) {			//Element welches als erstes eingefuegt wurde, wird als erstes entfernt
			m_numbers.erase(m_numbers.begin());
		}
		std::string remv = t_remove.humanMeasure();

		Timer t_find;
		int drin=search_a1(m, m_numbers, rand_ints);

		anz -= part_size;

		std::cout << "anz=     " << anz << " drin=        " << drin;
		std::cout << "     Entf=" << remv << " Such= " << t_find.humanMeasure() << std::endl;
	}
}



void insert_a2(int m, int p, int part_size, std::vector<int>& m_numbers, const std::vector<int>& rand_ints) {
	auto rand_it_begin = rand_ints.begin();
	while (p-- > 0) {

		Timer t_insert;
		insert_sorted(rand_it_begin, part_size, m_numbers);
		std::string ins = t_insert.humanMeasure();

		rand_it_begin += part_size;

		Timer t_find;
		int drin=search_sorted(m, m_numbers, rand_ints);

		std::cout << m_numbers.size() << "drin=        " << drin;
		std::cout << "     Einf=  " << ins << " Such= " << t_find.humanMeasure() << std::endl;
	}
}



void remove_a2 (int m, int p, int part_size, std::vector<int>& m_numbers, const std::vector<int>& rand_ints) {
	auto rand_it_begin = rand_ints.begin();
	while (p-- > 0) {
		Timer t_remove;
		remove_sorted(rand_it_begin, part_size, m_numbers);
		std::string remv = t_remove.humanMeasure();

		rand_it_begin += part_size;

		Timer t_find;
		int drin=search_sorted(m, m_numbers, rand_ints);


		std::cout << m_numbers.size() << "drin=        " << drin;
		std::cout << "     Entf=  " << remv << " Such= " << t_find.humanMeasure() << std::endl;
	}
}



void insert_a3(int m, int p, int part_size, std::list<int>& m_numbers, const std::vector<int>& rand_ints) {
	auto rand_it_begin = rand_ints.begin();
	while (p-- > 0) {

		Timer t_insert;
		insert_sorted(rand_it_begin, part_size, m_numbers);
		std::string ins = t_insert.humanMeasure();

		rand_it_begin += part_size;

		Timer t_find;
		int drin=search_sorted(m, m_numbers, rand_ints);

		std::cout << m_numbers.size() << "drin=        " << drin;
		std::cout << "     Einf=  " << ins << " Such= " << t_find.humanMeasure() << std::endl;

	}
}



void remove_a3(int m, int p, int part_size, std::list<int>& m_numbers, const std::vector<int>& rand_ints) {
	auto rand_it_begin = rand_ints.begin();
	while (p-- > 0) {
		Timer t_remove;
		remove_sorted(rand_it_begin, part_size, m_numbers);
		std::string remv = t_remove.humanMeasure();

		rand_it_begin += part_size;

		Timer t_find;
		int drin = search_sorted(m, m_numbers, rand_ints);

		std::cout << m_numbers.size() << "drin=        " << drin;
		std::cout << "     Entf=  " << remv << " Such= " << t_find.humanMeasure() << std::endl;
	}
}


orderedset::orderedset() {
	head = new _node;
	head->next = nullptr;
}

bool orderedset::is_empty() const {
	if (head->next == nullptr) {
		return true;
	}
	return false;
}



void orderedset::insert(int ele) {
//	_node* h = head;
//	h->val = ele;
//	while (h->next != nullptr && h->val > h->next->val) {
//		h = h->next;
//	}
//
	_node* n = new _node;
	n->val = ele;
	Iter s = begin();
	Iter e = end();
	while (s != e && ele > *s) {
		++s;
	}

}

int orderedset::Iter::operator *() {
	if (_cur->next == nullptr) {
		throw std::runtime_error("Iter::operator*: end");
	}
	return _cur->val;
}

typename orderedset::Iter& orderedset::Iter::operator++() {
	if (_cur->next == nullptr) {
		throw std::runtime_error("Iter::operator++: end");
	}
	_cur = _cur->next;
	return *this;
}

bool orderedset::Iter::operator ==(const orderedset::Iter& other) {
	return _cur == other._cur;
}

bool orderedset::Iter::operator!=(const orderedset::Iter& other) {
	return _cur != other._cur;
}

typename orderedset::Iter orderedset::begin() const {
	return Iter(head);
}

typename orderedset::Iter orderedset::end() const {
	_node* temp = head;
	while (temp != nullptr) {
		temp = temp->next;
	}
	return Iter(temp);
}

