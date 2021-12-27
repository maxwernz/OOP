#include "Bruch.h"
#include "Exception.h"


Bruch::Bruch (int zaehler, int nenner) : _zaehler(zaehler), _nenner(nenner){
	if (nenner == 0) {
		throw DivideByZeroException(zaehler);
	}
	normalisieren ();
}


void Bruch::operator*=(Bruch a) {
	_zaehler *= a._zaehler;
	_nenner *= a._nenner;
	//return *this;
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

int& Bruch::operator[] (size_t idx) {
	if (idx == 0) {
		return _zaehler;
	} else if (idx == 1) {
		return _nenner;
	}
	throw std::runtime_error ("invalid index");
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



