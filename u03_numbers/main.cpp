#include <iostream>
#include <vector>
#include <fstream>
#include "ooptool.h"

using namespace std;

int main (int argc, char* argv[]) {


	vector<int> numbers = read_ints(argv[1]);
	int max = -1;
	for (size_t i = 0; i < numbers.size(); ++i) {
		if (numbers[i] > max) {
			max = numbers[i];
		}
	}
	cout << max << endl;
}

/*argsp_t arsp (argc, argv);
	int n = 28;
	string sw [n] = { "", "eins", "zwei", "drei", "vier", "fuenf", "sechs",
					  "sieben", "acht", "neun", "zehn", "elf", "zwoelf", "dreizehn", "vierzehn",
					   "fuenfzehn", "sechzehn", "siebzehn", "achtzehn", "neunzehn", "zwanzig", "dreissig",
					   "vierzig", "fuenfzig", "sechzig", "siebzig", "achtzig", "neunzig" };
	string key = "und";
	string first = "ein";

	ifstream datei ("numbers.txt");
	vector<string> words = read_words("numbers.txt");
	vector<int> numbers;
	for (size_t i = 0; i < words.size(); ++i) {
		if (words[i + 1] == key) {
			for (int k = 0; k < n; ++k) {

			}
			i += 3;
		}
		else {
			for (int j = 0; j < n; ++j) {
				int add = 9;
				if (words[i] == sw[j]) {
					if (j > 20) {
						numbers.push_back(j + add);
						add += add;
					}
					else {
						numbers.push_back(j);
					}

				}
			}
		}
	}

	for (size_t j = 0; j < numbers.size(); ++j) {
		cout << numbers[j] << endl;
	} */
