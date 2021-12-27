#include <iostream>
#include "Bruch.h"
#include "Exception.h"

using namespace std;

void tryBruch() {
	try {
		Bruch a(3,2);
		cout << a << endl;
		Bruch b(3,0);
		cout << b << endl;
	} catch (DivideByZeroException& e) {
		cout << e.what() << " Zaehler: " << e.zaehler() << endl;
	}
}

int main () {
	tryBruch();
}


