
#ifndef EXCEPTION_H_
#define EXCEPTION_H_

class DivideByZeroException : public std::runtime_error {
public:
	DivideByZeroException(int zaehler) : runtime_error("divide by zero"), _zaehler(zaehler) {}
	int zaehler() const { return _zaehler; }

private:
	int _zaehler;
};



#endif /* EXCEPTION_H_ */
