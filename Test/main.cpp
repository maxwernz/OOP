//iMax AccesToken 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


#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <functional>
#include "ooptool.h"


#include "main.h"

using namespace std;






template<typename Cont>
void Test(Cont& a) {

}


int main () {
	vector<int> a = {1, 3, 4, 4, 5, 6, 7, 8};
	cout << *myupper_bound(a.begin(), a.end(), 8);

}


