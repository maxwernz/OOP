#include <iostream>
#include <vector>
#include "Participant.h"
#include "time.h"
#include "ooptool.h"

using namespace std;

void winner (vector<Participant> t);

int main (int argc, char* argv[]) {


	argsp_t argsp (argc, argv);
	vector<string> namen = argsp.positionals();
	vector<Participant> teilnehmer ;
	vector<int> zeiten = create_randints(argsp.no_pos(), 0, 1000);

	for (size_t i = 0; i < argsp.no_pos(); i++) {
		string name = namen [i];
		Participant p (name);
		teilnehmer.push_back(p);
		teilnehmer[i].time().add_seconds(zeiten[i]);
		cout << teilnehmer[i].name() << endl;
		teilnehmer[i].time().ausgabe();

	}

	winner (teilnehmer);

	/*for (size_t i = 0; i < namen.size(); i++) {
		teilnehmer.push_back(argsp.pos(i));
		teilnehmer[i].time().add_seconds(abs(zeiten[i]));
		cout << teilnehmer[i].name() << endl;
		teilnehmer[i].time().ausgabe();
	} */
		//teilnehmer.push_back(argsp.pos(i));

}


void winner (vector<Participant> t) {
	int fastest = 1001;
	int winner;
	for (size_t i = 0; i < t.size(); i++) {
		if (t[i].time().justseconds() < fastest) {
			fastest = t[i].time().justseconds();
			winner = i;
		}
	}
	cout << "Der Gewinner ist " << t[winner].name() << " mit einer Zeit von ";
	t[winner].time().ausgabe();
}
