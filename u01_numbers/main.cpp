#include <iostream>
#include <fstream>

using namespace std;


int main () {
	std::ifstream datei ("Numbers");
	int number;
	while (datei >> number) {
		std::cout << number << std::endl;
	}
}

