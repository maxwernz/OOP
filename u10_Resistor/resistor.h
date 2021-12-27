
#ifndef RESISTOR_H_
#define RESISTOR_H_

class Resistor {
public:
	Resistor(double ohm=0) : _ohm(ohm) {}
	Resistor(const Resistor& r) : _ohm(r._ohm) {}
	double ohm() const { return _ohm; };
	const Resistor& parallel(Resistor*& r1, Resistor*& r2) ;
	Resistor operator*(Resistor r);
	Resistor operator+(Resistor r);
	Resistor operator/(Resistor r);
private:
	double _ohm;
};

class Serial : public Resistor {
public:
	Serial(Resistor* r1, Resistor* r2) : Resistor(*r1 + *r2) {}
};

class Parallel : public Resistor {
public:
	Parallel(Resistor* r1, Resistor* r2) : Resistor((*r1 * *r2) / (*r1 + *r2)) {}
};



#endif /* RESISTOR_H_ */
