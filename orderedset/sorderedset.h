#include <stddef.h>
#include <stdlib.h>


#ifndef SORDEREDSET_H_
#define SORDEREDSET_H_

inline int newnode();

class sorderedset {
public:
	sorderedset();
	~sorderedset();
private:
	struct _node {
		_node* follower[newnode()];
		int val;
	};
private:
	_node* dummy;
};

inline int newnode() {
	int height = 1;
	while((std::rand()%2 ==0) && (height < 31)) { height += 1; }
	return height;
}



#endif /* SORDEREDSET_H_ */
