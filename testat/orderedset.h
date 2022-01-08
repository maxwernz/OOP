#include <stddef.h>

#ifndef ORDEREDSET_H_
#define ORDEREDSET_H_


class orderedset {
	class Iter;
public:
	orderedset();
	~orderedset();
	bool empty() const;
	void insert(const int ele);
	void remove(const int ele);
	size_t size() const;
	Iter begin() const;
	Iter end() const;
private:
	struct _node {
		_node* next;
		int val;
	};

	class Iter {
		friend class orderedset;
	public:
		int operator* ();
		Iter& operator++();
		bool operator==(const Iter& other);
		bool operator!=(const Iter& other);
	private:
		Iter(_node* cur) : _cur(cur) {}
		_node* _cur;
	};
private:
	_node* head;
};


#endif /* ORDEREDSET_H_ */
