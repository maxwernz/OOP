#include <stddef.h>
#include <stdlib.h>


#ifndef SORDEREDSET_H_
#define SORDEREDSET_H_

class sorderedset {
	class node;
	class Iter;
public:
	sorderedset();
	~sorderedset();
	void insert(const int  ele);
	void remove(const int ele);
	size_t size() const;
	bool search_ele(const int ele);
	Iter begin() const;
	Iter end() const;
private:
	class node {
	public:
		node(int height, int ele);
		~node();
		int val;
		node** forw;
	};
	class Iter {
			friend class sorderedset;
		public:
			int operator* ();
			Iter& operator++();
			bool operator==(const Iter& other);
			bool operator!=(const Iter& other);
		private:
			Iter(node* cur) : _cur(cur) {}
			node* _cur;
		};
private:
	node* head;
	int height;    //current max height except head
	int MAXHEIGHT = 30;
};


int randomHeight();

#endif /* SORDEREDSET_H_ */
