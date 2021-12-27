#include <iostream>
#include "Queue.h"

using namespace std;

int main () {
	Queue<int> a(3);
	a.enter(17);
	a.enter(2);
	cout << a.leave() << endl;
	cout << a.leave() << endl;
	cout << a.leave() << endl;
}




