
#ifndef INTVECTOR_H_
#define INTVECTOR_H_

class IntVector {
	class Iterator;
public:
	IntVector (size_t length);
	IntVector& operator=(const IntVector& other);
	int& operator[](size_t idx);
	IntVector (const IntVector& other);
	~IntVector () ;
	void initialize ();
	void add (int n, int idx);
	int& at(size_t idx);
	void out ();
	size_t size() const { return _length; }
	size_t remove_even();
	size_t count_negative() const;
	void trim(size_t l);
	Iterator begin() const;
	Iterator end() const;
private:
	class Iterator {
		friend class IntVector;
	public:
		int& operator*();
		Iterator& operator++();
		bool operator==(const Iterator& other) const;
		bool operator!=(const Iterator& other) const;
	private:
		Iterator (int* arr, size_t l) : arr(arr), l(l) { };
		int* arr;
		size_t l;
	};
	int* _array;
	size_t _length;
};

IntVector reverse_copy(const IntVector& iv);
IntVector operator+(IntVector left, IntVector right);
template<typename T>
int minimum(T vec);



#endif /* INTVECTOR_H_ */
