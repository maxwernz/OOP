#include <iostream>
#include "LinkedQueue.h"
#include "ooptool.h"

using namespace std;

int main () {
	Timer timer;
	LinkedQueue<int> lq;
	cout << lq.is_empty() << endl;
	cout << lq.size() << endl;
	lq.enter(3);
	lq.enter(5);
	//.enter(7);
	cout << lq.leave() << endl;
	cout << lq.leave() << endl;
	cout << lq.leave() << endl;
	cout << lq.is_empty() << endl;
	cout << lq.size() << endl;
	cout << timer.humanMeasure() << endl;
}




