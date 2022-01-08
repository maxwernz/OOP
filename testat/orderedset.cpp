#include "orderedset.h"
#include <stdexcept>


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
	if (head->next == nullptr) {
		return true;
	}
	return false;
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
		n->next = h->next;
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
//	_node* temp = head->next;
//	while (temp != nullptr) {
//		temp = temp->next;
//	}
//	return Iter(temp);
	return Iter(nullptr);
}

