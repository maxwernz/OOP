#include <iostream>
#include "time.h"

using namespace std;

int main () {
Time time(0, 3, 24);


time.ausgabe();
time.add_seconds(-205);
time.ausgabe();



}

