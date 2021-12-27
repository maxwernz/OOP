//iMax AccesToken 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


#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <functional>
#include "ooptool.h"
#include "common.h"


#include "main.h"

using namespace std;






template<typename Cont>
void Test(Cont& a) {

}


int main () {
	orderedset a;
	a.insert(1);
	for (auto it=a.begin(); it != a.end(); ++it) {
		cout << *it << endl;
	}
}


