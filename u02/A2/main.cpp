#include <iostream>
#include <vector>
#include "Participant.h"
#include "ooptool.h"

void winner(std::vector<Participant>& teilnehmer);

int main(int argc, char* argv[])
{
    argsp_t argsp (argc, argv);
    std::vector<int> times = create_randints(argsp.no_pos(), 0, 1000);
    std::vector<Participant> teilnehmer;

    for (size_t i = 0; i < times.size(); ++i)
    {
        Participant p (argsp.pos(i));
        //p.time().addSeconds(times.at(i));
        teilnehmer.push_back(p);
    }

    winner(teilnehmer);
}

void winner(std::vector<Participant>& teilnehmer)
{   
    int fastest = teilnehmer.at(0).time().justseconds();
    size_t winnerNo = 0;
    for (size_t i = 1; i < teilnehmer.size(); ++i)
    {
        if(teilnehmer.at(i).time().justseconds() < fastest)
        {
            fastest = teilnehmer.at(i).time().justseconds();
            winnerNo = i;
        }
    }

    std::cout << "Der Gewinner ist " << teilnehmer.at(winnerNo).name() << " mit einer Zeit von ";
    teilnehmer.at(winnerNo).time().print();
}