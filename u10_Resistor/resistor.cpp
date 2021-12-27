#include "resistor.h"

Resistor Resistor::operator*(Resistor r) {
	return Resistor(_ohm * r._ohm);
}

Resistor Resistor::operator+(Resistor r) {
	return Resistor(_ohm + r._ohm);
}

Resistor Resistor::operator/(Resistor r) {
	return Resistor(_ohm / r._ohm);
}




