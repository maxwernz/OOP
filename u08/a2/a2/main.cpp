//
//  main.cpp
//  a2
//
//  Created by Maximilian Wernz on 12.09.22.
//

#include <iostream>
#include "Sequence.hpp"
#include "Studi.h"
#include "ooptool.h"

void findMatnr(Sequence<Studi>& studis, long matnr);

int main(int argc, const char * argv[]) {
    argsp_t argsp(argc, argv);
    std::ifstream data(argsp.pos(0));
    
    Sequence<Studi> studis;
    Studi help;
    while (data >> help)
        studis.pushBack(help);
    
    if (argsp.no_pos() == 2)
        findMatnr(studis, stol(argsp.pos(1)));
    else
        show(studis);
    
}

void findMatnr(Sequence<Studi>& studis, long matnr)
{
    for (size_t i=0; i < studis.size(); ++i)
    {
        if (studis[i].matnr() == matnr)
            std::cout << studis[i] << std::endl;
    }
}
