//
//  main.cpp
//  a1
//
//  Created by Maximilian Wernz on 12.09.22.
//

#include <iostream>
#include "Sequence.hpp"

int main(int argc, const char * argv[]) {
    Sequence<int> seq(1);
    while(seq.capacity() < 100)
        seq.pushBack(17);
}
