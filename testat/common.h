#include "orderedset.h"
#include "sorderedset.h"
#include <string>
#include <vector>
#include <list>

#ifndef COMMON_H_
#define COMMON_H_

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
