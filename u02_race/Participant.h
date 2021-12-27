#include "time.h"


#ifndef PARTICIPANT_H_
#define PARTICIPANT_H_


static int np = 0;
class Participant {
public:
Participant (const std::string& name, int h=0, int m=0, int s=0) : _name (name), _time (h, m, s), _number_participants (++np) {
	//std::cout << " Participant(" << _number_participants << ", " << _name << ")" << std::endl;
}

std::string name () const { return _name; }
Time& time () {return _time; }

~Participant () {
	//std::cout << " ~Participant(" << _number_participants << ", " << _name << ")" << std::endl;
}
private:
	std::string _name;
	Time _time;
	int _number_participants;
};




#endif /* PARTICIPANT_H_ */
