//
//  main.cpp
//  a3
//
//  Created by Maximilian Wernz on 20.09.22.
//

#include <iostream>
#include "LinkedQueue.h"

int main(int argc, const char * argv[]) {
    LinkedQueue<int> lq;
    for (int i=0; i < 100; ++i) {
        lq.enter(i);
    }
    
    for (int i : lq) {
        std::cout << i << std::endl;
    }
}
