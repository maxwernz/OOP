#include <cstring>
#include <string>
#include <vector>
#include <list>

#ifndef COMMON_H_
#define COMMON_H_

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



void insert_a1 (int m, int p, int part_size, std::vector<int>& numbers, const std::vector<int>& rand_ints);
void remove_a1(int m, int p, int part_size, std::vector<int>& numbers, const std::vector<int>& rand_ints);

int search_a1(int m, std::vector<int>& numbers, const std::vector<int>& rand_ints);

void insert_a2(int m, int p, int part_size, std::vector<int>& numbers, const std::vector<int>& rand_ints);
void remove_a2 (int m, int p, int part_size, std::vector<int>& numbers, const std::vector<int>& rand_ints);

void insert_a3(int m, int p, int part_size, std::list<int>& numbers, const std::vector<int>& rand_ints);
void remove_a3(int m, int p, int part_size, std::list<int>& numbers, const std::vector<int>& rand_ints);

void insert_a4(int m, int p, int part_size, orderedset& numbers, const std::vector<int>& rand_ints);
void remove_a4(int m, int p, int part_size, orderedset& numbers, const std::vector<int>& rand_ints);

void insert_a5(int m, int p, int part_size, sorderedset& numbers, const std::vector<int>& rand_ints);
void remove_a5(int m, int p, int part_size, sorderedset& numbers, const std::vector<int>& rand_ints);

int search_a5(int m, sorderedset& numbers, const std::vector<int>& rand_ints);

void out_ins (size_t size, int drin, std::string ins, std::string t_find);
void out_rem (size_t size, int drin, std::string remv, std::string t_find);


template<typename Iter>
Iter binary_find(Iter begin, Iter end, int val);

template<typename Iter>
Iter not_less_than(Iter start, Iter end, int val);

template<typename Iter>
Iter my_find(Iter first, Iter last, int val);

template<typename Cont>
int search_sorted(int m, Cont& numbers, const std::vector<int>& rand_ints);

template<typename Cont, typename Iter>
void insert_sorted (Iter rand_it_begin, int part_size, Cont& numbers);

template<typename Cont, typename Iter>
void remove_sorted (Iter rand_it_begin, int part_size, Cont& numbers);


#endif /* COMMON_H_ */
