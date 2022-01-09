#include "sorderedset.h"
#include <cstring>
#include <memory>

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




