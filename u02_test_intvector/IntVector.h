
#ifndef INTVECTOR_H_
#define INTVECTOR_H_

class IntVector {
public:
	IntVector (size_t length);
	IntVector& operator=(const IntVector& other);
	IntVector (const IntVector& other);
	~IntVector () ;
	void initialize ();
	void add (int n, int idx);
	int& at(size_t idx);
	void out ();
	size_t size() const { return _length; }
private:
	int* _array;
	size_t _length;
};



#endif /* INTVECTOR_H_ */
