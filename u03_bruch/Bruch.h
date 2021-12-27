#include <iostream>

#ifndef BRUCH_H_
#define BRUCH_H_

class Bruch {
public:

	Bruch (int zaehler=0, int nenner=1);
	void operator*=(Bruch a);
	int zaehler() const { return _zaehler; }
	int nenner() const {return _nenner; }
	int& operator[](size_t idx);

private:
	void normalisieren ();
	int _zaehler;
	int _nenner;
	//int _bruch; oben initialisieren mit _bruch (zaehler / nenner) ?
};

bool operator==(Bruch a, Bruch b);
bool operator!=(Bruch a, Bruch b);
Bruch operator* (Bruch a, Bruch b);
std::ostream& operator<<(std::ostream& out, Bruch a);

int ggt (int a, int b);
void swap (int& a, int& b);



#endif /* BRUCH_H_ */
