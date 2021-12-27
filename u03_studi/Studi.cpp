#include "Studi.h"

/*std::ifstream& operator>> (std::ifstream& datei, std::vector<Studi>& studis) {
	std::vector<std::string> lines = read_lines("studis.txt");
	long mat;
	std::string vorname;
	std::string nachname;

	for (size_t i = 0; i < lines.size(); ++i) {
		datei.operator >>(mat);
		datei >> vorname;
		datei >> nachname;

		if (datei.good()) {
			Studi a (mat, vorname, nachname);
			studis.push_back(a);
		} else {
			datei.setstate(std::ios::failbit);
		}
	}

	return datei;
} */

std::ifstream& operator>> (std::ifstream& datei, std::vector<Studi>& studis) {

	long mat;
	std::string vorname;
	std::string nachname;
	while (datei.operator >>(mat)) {
		datei >> vorname;
		datei >> nachname;

		if (datei.good()) {
			Studi a(mat, vorname, nachname);
			studis.push_back(a);
		} else {
			datei.setstate(std::ios::failbit);
		}
	}

	return datei;
}

std::ostream& operator<< (std::ostream& out, Studi s) {
	out << s.matnr() << " " << s.vorname() << " " << s.nachname();
	return out;
}


