
#ifndef EXCEPTION_H_
#define EXCEPTION_H_

class OverflowException : public std::runtime_error {
	int _index;
public:
	OverflowException(int index) : std::runtime_error("Index overflow"), _index(index) {}
	int index() const { return _index; }
};

class UnderflowException : public std::runtime_error {
	int _index;
public:
	UnderflowException(int index) : std::runtime_error("Index underflow"), _index(index) {}
	int index() const { return _index; }
};

class EmptyException : public std::runtime_error {
public:
	EmptyException() : std::runtime_error("size is 0") {}
};



#endif /* EXCEPTION_H_ */
