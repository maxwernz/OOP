//
//  main.cpp
//  a1
//
//  Created by Maximilian Wernz on 20.09.22.
//

#include <iostream>
#include "ElectricalNetwork.h"

int main(int argc, const char * argv[]) {
    Resistor a(100), b(200), c(300), d(400);
    Parallel par(&a, &b);
    Serial ser(&par, &c);
    
    std::cout << ser.ohm() << std::endl;
    
    Serial ab(&a, &b);
    Serial abc(&ab, &c);
    Parallel abc_d(&abc, &d);
    
    std::cout << abc_d.ohm() << std::endl;
}
