#ifndef PARTICIPANT_H_
#define PARTICIPANT_H_

#include <string>
#include "Time.h"

static int np = 0;
class Participant 
{
public:
    Participant(std::string name) : m_name(name), m_participants(++np) { std::cout << m_participants << " " << m_name << std::endl; }
    ~Participant() { std::cout << m_participants << " " << m_name << std::endl; }
    std::string name() const { return m_name; }
    Time& time() { return m_time; }
private:
    std::string m_name;
    int m_participants;
    Time m_time;
};

#endif