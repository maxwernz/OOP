#include <iostream>
#include <vector>
#include <fstream>
#include "Studi.h"
#include "ooptool.h"

using namespace std;

int main () {
	vector<Studi> studis;
	ifstream datei ("studis.txt");
	 datei >> studis;
	for (size_t i = 0; i < studis.size(); ++i) {
		cout << studis[i] << endl;
	}
}

