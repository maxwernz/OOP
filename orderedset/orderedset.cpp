#include "orderedset.h"
#include <stdexcept>


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

bool orderedset::is_empty() const {
	if (head->next == nullptr) {
		return true;
	}
	return false;
}



void orderedset::insert(const int ele) {
	_node* n = new _node;
	n->val = ele;
	if (is_empty()) {
		n->next = nullptr;
		head->next = n;
		return;
	}
	_node* h = head->next;
	while(h->next != nullptr && ele > h->next->val) {
		h = h->next;
	}
	if (h == nullptr) {
		throw std::runtime_error("orderedset::insert: pos out of bounds");
	}

	n->next = h->next;
	h->next = n;

}


void orderedset::remove(const int ele) {
	if (is_empty()) {
		throw std::runtime_error("orderedset::remove: set is empty");
	}
	_node* h = head->next;
	if (h->val == ele) {
		_node* todel = h;
		head->next = h->next;
		delete todel;
		return;
	}
	while (h != nullptr) {
		if (h->next->val == ele) {
			_node* todel = h->next;
			h->next = h->next->next;
			delete todel;
			return;
		}
		h = h->next;
	}
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

int orderedset::Iter::operator ->(int m) {
	return m;
}



typename orderedset::Iter orderedset::begin() const {
	return Iter(head->next);
}

typename orderedset::Iter orderedset::end() const {
	_node* temp = head->next;
	while (temp != nullptr) {
		temp = temp->next;
	}
	return Iter(temp);
}


void fill(orderedset& a, std::vector<int>& b) {
	for (int i : b) {
		a.insert(i);
	}
}
