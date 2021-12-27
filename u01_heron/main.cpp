#include <iostream>
#include <math.h>
#include <string>
#include "ooptool.h"

double heron (double x, double eps);

int main (int argc, const char* argv[]) {
	argsp_t argsp(argc, argv);
	double x = argsp.double_pos (0, 10.0);
	double eps = argsp.double_pos (1, 1e-6);

	double a = heron (x, eps);
	std::cout << a << std::endl;
}

double heron (double x, double eps) {
	double a = (1 + x) / 2;
	double dif = 1;
	double a_neu;

	while (dif >= eps) {
		a_neu = (a + x / a) / 2;
		dif = fabs (a - a_neu);
		a = a_neu;
	}

	return a;
}

