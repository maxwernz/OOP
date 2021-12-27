#include <iostream>
#include <fstream>
#include "Sequence.h"
#include "Studi.h"
#include "ooptool.h"

using namespace std;



void linsearch(Sequence<Studi> a, long number) {
	for (size_t i = 0; i < a.size(); i += 1) {
		if (a[i] == number) {
			cout << a[i] << endl;
		}
	}
}


int main (int argc, char* argv[]) {
	argsp_t argsp(argc, argv);
	Sequence<Studi> studis(1);
	ifstream datei (argsp.pos(0));
	Studi a;
	while (datei >> a) {
		studis.push_back(a);
	}
	for (size_t i = 0; i < studis.size(); i += 1) {
		cout << studis[i] << endl;
	}
	if (argsp.no_pos() == 2) {
		linsearch(studis, stol(argsp.pos(1)));
	}
}
