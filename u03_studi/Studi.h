#include <iostream>
#include <vector>
#include <fstream>
#include "ooptool.h"

#ifndef STUDI_H_
#define STUDI_H_


class Studi {
public:
	friend std::istream& operator>> (std::istream& in, Studi& s);
	Studi (long matnr=0, std::string vorname="Max", std::string nachname="Mustermann") : _matnr (matnr), _vorname(vorname), _nachname(nachname) {}
	long matnr() const { return _matnr; }
	std::string vorname() const { return _vorname; }
	std::string nachname() const { return _nachname; }
private:
	long _matnr;
	std::string _vorname;
	std::string _nachname;
};

std::ifstream& operator>> (std::ifstream& datei, std::vector<Studi>& studis);
std::ostream& operator<< (std::ostream& out, Studi s);
#endif /* STUDI_H_ */
