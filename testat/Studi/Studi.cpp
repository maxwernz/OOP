#include "Studi.h"
using namespace std;

Studi::Studi() {
}

Studi::Studi(long matnr, string vorname, string nachname) {
}

Studi::Studi(const Studi &other) {
}

Studi::~Studi() {
}

long Studi::matnr() const {
	return -1;
}

string Studi::vorname() const {
	return "";
}

string Studi::nachname() const {
	return "";
}

bool Studi::set_matnr(long matnr) {
}

void Studi::set_image(char *img, int size) {
}
