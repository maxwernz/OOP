#include <iostream>
#include "Bruch.h"


using namespace std;

void gleichheit ();
void malgleich ();
void mal ();



int main () {
	//gleichheit();
	//malgleich();
	//mal();
	Bruch a(1, 2);
	Bruch b (2, 3);
	cout << a * b << endl;
}

void mal () {
	Bruch a(2, 3);
	Bruch b(3, 4);
	Bruch c;

	cout << b[1] << endl << b[0] << endl << b[4] << endl;
}

void malgleich () {
	Bruch a(2, 3);
	Bruch b(4, 5);

	a *= b;
	cout << a << endl;
}

void gleichheit () {
	Bruch a(3, 2);
	Bruch b(3, 2);
	Bruch c(4, 3);

	if (a == b) {
		cout << "gleich" << endl;
	}

	if (a == c) {
		cout << "gleich" << endl;
	} else if (a != c){
		cout << "ungleich" << endl;
	}
}
