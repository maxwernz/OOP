//Maximilian Wernz 2112041
#include "common.h"
#include "ooptool.h"
#include <iostream>
#include <algorithm>


using namespace std;

void a_1 (int m, int part_size, const vector<int>& rand_ints) {
	vector<int> numbers;
	int anz = 0;

	insert_a1 (anz, part_size, m, numbers, rand_ints);
	remove_a1 (anz, part_size, m, numbers, rand_ints);
}

void a_2 (int m, int p, int part_size, const vector<int>& rand_ints) {
	vector<int> numbers;
	insert_a2(m, p, part_size, numbers, rand_ints);
	remove_a2(m, p, part_size, numbers, rand_ints);

}

void a_3 (int m, int p, int part_size, const vector<int>& rand_ints) {
	list<int> numbers;
	insert_a3(m, p, part_size, numbers, rand_ints);
	remove_a3(m, p, part_size, numbers, rand_ints);
}

void a_4 (int m, int p, int part_size, const vector<int>& rand_ints) {
	orderedset numbers;
	insert_a4(m, p, part_size, numbers, rand_ints);
}

void test() {
	vector<int> s = { 2 };
	orderedset a;
	a.insert(1);
	a.insert(3);
	a.insert(2);



}

int main (int argc, char* argv[]) {

	argsp_t argsp (argc, argv);
	int m = argsp.int_option("m", 40000);
	int s = argsp.int_option("s", 40000);
	int p = argsp.int_option("p", 4);
	int a = argsp.int_option("a", 0);

	if ((m%p) == 0) {
		vector<int> rand_ints = create_same_randints(m + s);
		vector<int> meine { 4, 2, 5, 9, 1, 12, 38, 29, 2 , 4, 8, 1, 98, 83, 2, 57, -2 };

		int part_size = m / p;


		cout << "mengen: m=" << m << ", s=" << s << ", p=" << p << endl;
		Timer timer;
		switch (a) {
		case 0: cout << "Kein a angegeben" << endl;
			break;
		case 1: cout << "unsorted_vec" << endl; a_1(m, part_size, rand_ints);
			break;
		case 2: cout << "sorted_vec" << endl; a_2(m, p, part_size, rand_ints);
			break;
		case 3: cout << "sorted_list" << endl; a_3(m, p, part_size, rand_ints);
			break;
		case 4: cout << "ordered_list" << endl; a_4(m, p, part_size, rand_ints);
			break;
		}
		cout << "Gesamtzeit:" << timer.humanMeasure() << endl;
	} else {
		cout << "p ist kein Teiler von m" << endl;
	}
}


