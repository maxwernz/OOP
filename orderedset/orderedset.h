#include <vector>

#ifndef ORDEREDSET_H_
#define ORDEREDSET_H_


template<typename Iter>
Iter not_less_than(Iter start, Iter end, int val);


class orderedset {
	class Iter;
public:
	orderedset();
	~orderedset();
	bool is_empty() const;
	void insert(const int ele);
	void remove(const int ele);
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
		int operator->(int m);
	private:
		Iter(_node* cur) : _cur(cur) {}
		_node* _cur;
	};
private:
	_node* head;
};


void fill(orderedset& a, std::vector<int>& b);

#endif /* ORDEREDSET_H_ */
