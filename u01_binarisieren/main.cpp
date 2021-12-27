#include <iostream>
#include <vector>
#include <stdlib.h>
#include "ooptool.h"
using namespace std;

void binarisieren (string in, string out, float s = 0.5);



int main (int argc, char* argv[])
{
	string in =  argv[1];
	string out = argv[2];

	if (argv[3] == nullptr)
		binarisieren (in, out);
	else
	{
		float s = atof (argv[3]);
		if (s <= 1 && s >= 0)
		{
			binarisieren (in, out, s);
		}
		else
		{
			cout << "Der Schwellenwert muss zwischen 0 und 1 liegen" << endl;
		}

	}

}

void binarisieren (string in, string out, float s)
{
	vector<int> a = read_pgm(in);

	for (int i = 3; i < (a[0] * a[1]); i++)
	{
		if (a[i] < (s * a[2]))
		{
			a[i] = 0;
		}
		else
		{
			a[i] = a[2];
		}
	}

	save_pgm(out, a);
}




