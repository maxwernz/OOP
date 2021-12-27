#include <iostream>
#include "resistor.h"

using namespace std;

void test1() {
	Resistor r1(100), r2(200), r3(300);
	Parallel par(&r1, &r2);
	Serial ser(&par, &r3);
	cout << "Netzwiderstand: " << ser.ohm() << " Ohm" << endl;
}

void test2() {
	Resistor r1(100), r2(200), r3(300), r4(400);
	Serial ser1(&r1, &r2), ser(&ser1, &r3);
	Parallel par (&ser, &r4);
	cout << "Netzwiderstand: " << par.ohm() << " Ohm" << endl;
}

int main () {
	test1();
	test2();

}




