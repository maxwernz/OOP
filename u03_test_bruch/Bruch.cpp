#include "Bruch.h"



Bruch::Bruch (int zaehler, int nenner) : _zaehler(zaehler), _nenner(nenner){
	normalisieren ();
}


Bruch& Bruch::operator*=(Bruch a) {
	this->_zaehler *= a._zaehler;
	this->_nenner *= a._nenner;
	return *this;
}

void Bruch::normalisieren () {
	if (_nenner < 0) {
		_nenner *= -1;
		_zaehler *= -1;
	}
	if (_nenner == 0) {
		std::cerr << "Fehler: Nenner gleich 0" << std::endl;
		_nenner = 1;
	}
	int gt = ggt (zaehler (), nenner());
		_zaehler = zaehler() / gt;
		_nenner = nenner() /  gt;
	}

int ggt(int a, int b) {
	while (a != 0) {
		swap (a, b);
		a %= b;
	}
	return b;
}

void swap (int& a, int& b) {
	int h = a;
	a = b;
	b = h;
}

std::ostream& operator<<(std::ostream& out, Bruch a) {
	out << a.zaehler() << "/" << a.nenner();
	return out;
}

Bruch operator* (Bruch a, Bruch b) {
	return Bruch (a.zaehler() * b.zaehler(), a.nenner() * b.nenner());
}

bool operator==(Bruch a, Bruch b) {
	if (a.zaehler() == b.zaehler() && a.nenner() == b.nenner()) {
		return 1;
	}
	return 0;
}

bool operator!=(Bruch a, Bruch b) {
	if (a.zaehler() != b.zaehler() || a.nenner() != b.nenner()) {
		return 1;
	}
	return 0;
}



