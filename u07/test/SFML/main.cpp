#include <iostream>
#include <vector>
#include "Board.h"
#include "ooptool.h"
#include "ooptoolg.h"

using namespace std;

Board* board;

bool check(vector<int>& a, int z, int i) {
	//z: Zeilenanzahl
	//i: zu checkende Position in der aktuellen Zeile

	int k=1;
	for(int j=z-1; j>=0; --j) {
		if(a[j] == i || a[j] == i+k || a[j] == i-k) {
			return false;
		}
		k += 1;
	}
	return true;
}

bool dame(vector<int>& a, int n, int z) {
	if(z==n){
		return true;
	}
	for(int i=0; i<n; ++i) {
		a[z] = i;
		board->setSquare(z, i, Gruen);
		board->render();
		schlafeMs(1);
		if(check(a, z, i)) {
			if(dame(a, n, z+1)) {
				return true;
			}
		}
		board->resetSquare(z, i);
	}
	return false;
}

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);

	board = new Board(n);
	board->render();
	schlafeMs(1000);

	vector<int> a(n);

//	for(size_t i=0; i<a.size(); ++i) {
//		a[i] = 0;
//	}

	dame(a, n, 0);

	for(int i=1; i<=n; ++i) {
		cout << n-i << "| ";
		for(int j=0; j<n; ++j) {
			if(a[n-i]==j) {
				cout << "* ";
			}
			else {
				cout << "O ";
			}
		}
		cout << endl;
	}

	schlafeMs(10000);
	delete board;
}




