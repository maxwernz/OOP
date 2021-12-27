#include <iostream>
#include "IntVector.h"
#include "ooptool.h"

using namespace std;

int main (int argc, char* argv[]) {
	argsp_t argsp(argc, argv);
	IntVector a(stoi (argsp.pos(1)));
	Timer timer;
	for (int i = stoi(argsp.pos(0)) - 1; i < stoi(argsp.pos(1)); ++i) {
		a[i] = i + 1;
	}
	int suma = 0;
	for (auto it = a.begin(); it != a.end(); ++it) {

		suma += *it;
	}
	cout << timer.humanMeasure() << endl;
	cout << "von=" << argsp.pos(0) << " bis=" << argsp.pos(1) << " sum=" << suma << endl;

}
