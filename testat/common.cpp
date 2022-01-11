#include "common.h"





/** lower_bound
 *  Bestimmt Iterator auf das erste Element was nicht kleiner ist (groesser oder gleich)
 */
template<typename Iter>
Iter not_less_than(Iter start, Iter end, int val) {
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

//find Funktion
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



/** Sucht in sortierter Datenstruktur mit Abbruch
 * 	Aufgabe 2-4
 */
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

/** Fuegt sortiert in Datenstruktur ein
 * 	Aufgabe 2-4
 */
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

/** Loescht in sortierter Struktur, Element wird gesucht -> geloescht
 * 	Aufgabe 2-4
 */
template<typename Cont, typename Iter>
void remove_sorted (Iter rand_it_begin, int part_size, Cont& numbers) {
	for (auto rand_it=rand_it_begin; rand_it != rand_it_begin+part_size; ++rand_it) {
		auto remvit = std::find(numbers.begin(), numbers.end(), *rand_it);
		if (remvit != numbers.end()) {
			numbers.erase(remvit);
		}
	}
}




//Suche fuer Augabe 1
int search_a1(int m, std::vector<int>& numbers, const std::vector<int>& rand_ints) {
	int drin=0;
	for (auto search_it=rand_ints.begin()+m; search_it != rand_ints.end(); ++search_it) {
		if (my_find(numbers.begin(), numbers.end(), *search_it) != numbers.end()) {
			drin+=1;
		}
	}
	return drin;
}

//Suche Aufgabe 5 mit search Funktion aus sorderedset
int search_a5(int m, sorderedset& numbers, const std::vector<int>& rand_ints) {
	int drin=0;
	for (auto search_it=rand_ints.begin()+m; search_it != rand_ints.end(); ++search_it) {
		if (numbers.search_ele(*search_it)) {
			drin += 1;
		}
	}
	return drin;
}



// Ausgabe fuer das Einfuegen
void out_ins (size_t size, int drin, std::string ins, std::string t_find) {
	std::cout << "anz=" << std::setw(8) << size << " drin=" << std::setw(8) << drin;
	std::cout << "   Einf= " << ins << " Such=" << t_find << std::endl;
}

//Ausgabe fuer das Entfernen
void out_rem (size_t size, int drin, std::string remv, std::string t_find) {
	std::cout << "anz=" << std::setw(8) << size << " drin=" << std::setw(8) << drin;
	std::cout << "   Entf= " << remv << " Such= " << t_find << std::endl;
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





void insert_a5(int m, int p, int part_size, sorderedset& numbers, const std::vector<int>& rand_ints) {
	auto rand_it_begin = rand_ints.begin();
	while (p-- > 0) {
		Timer t_insert;
		for (auto it = rand_it_begin; it != rand_it_begin + part_size; ++it) {
			numbers.insert(*it);
		}
		std::string ins = t_insert.humanMeasure();

		rand_it_begin += part_size;

		Timer t_find;
		int drin = search_a5(m, numbers, rand_ints);

		out_ins(numbers.size(), drin, ins, t_find.humanMeasure());
	}
}

void remove_a5(int m, int p, int part_size, sorderedset& numbers, const std::vector<int>& rand_ints) {
	auto rand_it_begin = rand_ints.begin();
	while (p-- > 0) {
		Timer t_remove;
		for (auto it = rand_it_begin; it != rand_it_begin + part_size; ++it) {
			numbers.remove(*it);
		}
		std::string remv = t_remove.humanMeasure();

		rand_it_begin += part_size;

		Timer t_find;
		int drin = search_a5(m, numbers, rand_ints);

		out_rem(numbers.size(), drin, remv, t_find.humanMeasure());
	}
}





orderedset::orderedset() {
	head = new _node;
	head->next = nullptr;
}

orderedset::~orderedset() {
	while (head->next != nullptr) {
		_node* todel = head->next;
		head->next = head->next->next;
		delete todel;
	}
	delete head;
}

bool orderedset::empty() const {
	return head->next == nullptr;
}

void orderedset::insert(const int ele) {
	if (empty()) {
		_node* n = new _node;
		n->val = ele;
		n->next = nullptr;
		head->next = n;
		return;
	}
	_node* h = head;
	while(h->next != nullptr && ele > h->next->val) {
		h = h->next;
	}
	if (h == nullptr) {
		throw std::runtime_error("orderedset::insert: pos out of bounds");
	}
	if (h->next == nullptr) {
		_node* n = new _node;
		n->val = ele;
		n->next = nullptr;
		h->next = n;
		return;
	}
	if (ele != h->next->val) {
		_node* n = new _node;
		n->val = ele;
		n->next = h->next;
		h->next = n;
	}

}

void orderedset::remove(const int ele) {
	if (empty()) {
		throw std::runtime_error("orderedset::remove: set is empty");
	}
	_node* h = head->next;
	if (h->val == ele) {
		_node* todel = h;
		head->next = h->next;
		delete todel;
		return;
	}
	while (h->next != nullptr) {
		if (h->next->val == ele) {
			_node* todel = h->next;
			h->next = h->next->next;
			delete todel;
			return;
		}
		h = h->next;
	}
}

size_t orderedset::size() const {
	_node* h = head->next;
	size_t size = 0;
	while (h != nullptr) {
		h = h->next;
		size+=1;
	}
	return size;
}


int orderedset::Iter::operator*() {
	if (_cur == nullptr) {
		throw std::runtime_error("Iter::operator*: end");
	}
	return _cur->val;
}

typename orderedset::Iter& orderedset::Iter::operator++() {
	if (_cur == nullptr) {
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
	return Iter(head->next);
}

typename orderedset::Iter orderedset::end() const {
	return Iter(nullptr);
}





int randomHeight() {
	int height = 1;
	while ((rand()%2 == 0) && (height < 31)) {
		height += 1;
	}
	return height;
}

sorderedset::node::node(int height, int ele) {
	forw = new node * [height + 1];
	memset(forw, 0, sizeof(node*) * height + 1);
	val = ele;
}

sorderedset::node::~node() {
	delete[] forw;
}

sorderedset::sorderedset() {
	head = new node(MAXHEIGHT, 0);
	height = 0;    //current max height except head;
}

sorderedset::~sorderedset() {
	while (head->forw[0] != nullptr) {
		node* todel = head->forw[0];
		head->forw[0] = head->forw[0]->forw[0];
		delete todel;
	}
	delete head;
}

size_t sorderedset::size() const {
	node* h = head->forw[0];
	size_t size = 0;
	while (h != nullptr) {
		h = h->forw[0];
		size+=1;
	}
	return size;
}

void sorderedset::insert(const int ele) {
	node* h = head;
	node* update[MAXHEIGHT + 1];
	memset(update, 0, sizeof(node*) * (MAXHEIGHT + 1));

	for (int i = height; i >= 0; --i) {
		while (h->forw[i] != nullptr && ele > h->forw[i]->val) {
			h = h->forw[i];
		}
		update[i] = h;
	}

	h = h->forw[0];

	if (h == nullptr || h->val != ele) {
		int randHeight = randomHeight();

		if (randHeight > height) {
			for (int i = height+1; i < randHeight+1; ++i) {
				update[i] = head;
			}
			height = randHeight;
		}

		node* n = new node(randHeight, ele);  //maybe fehler
		for (int i=0; i <= randHeight; ++i) {
			n->forw[i] = update[i]->forw[i];
			update[i]->forw[i] = n;
		}

	}
}

void sorderedset::remove(const int ele) {
	node* h = head;
	node* update[MAXHEIGHT + 1];
	memset(update, 0, sizeof(node*) * (MAXHEIGHT + 1));

	for (int i = height; i >= 0; --i) {
		while (h->forw[i] != nullptr && ele > h->forw[i]->val) {
			h = h->forw[i];
		}
		update[i] = h;
	}

	h = h->forw[0];

	if (h != nullptr && h->val == ele) {
		for (int i = 0; i <= height; ++i) {
			if (update[i]->forw[i] != h) {
				break;
			}

			update[i]->forw[i] = h->forw[i];
		}

		while (height > 0 && head->forw[height] == nullptr) {
			height -= 1;
		}
		delete h;
	}
}

bool sorderedset::search_ele(const int ele) {
	node* h = head;

	for (int i = height; i >= 0; --i) {
		while (h->forw[i] != nullptr && ele > h->forw[i]->val) {
			h = h->forw[i];
		}
	}

	h = h->forw[0];

	if (h != nullptr && h->val == ele) {
		return true;
	}
	return false;
}


int sorderedset::Iter::operator*() {
	if (_cur == nullptr) {
		throw std::runtime_error("Iter::operator*: end");
	}
	return _cur->val;
}

typename sorderedset::Iter& sorderedset::Iter::operator++() {
	if (_cur == nullptr) {
		throw std::runtime_error("Iter::operator++: end");
	}
	_cur = _cur->forw[0];
	return *this;
}

bool sorderedset::Iter::operator ==(const sorderedset::Iter& other) {
	return _cur == other._cur;
}

bool sorderedset::Iter::operator!=(const sorderedset::Iter& other) {
	return _cur != other._cur;
}

typename sorderedset::Iter sorderedset::begin() const {
	return Iter(head->forw[0]);
}

typename sorderedset::Iter sorderedset::end() const {
	return Iter(nullptr);
}

