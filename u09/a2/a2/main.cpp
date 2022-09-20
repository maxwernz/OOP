//
//  main.cpp
//  a2
//
//  Created by Maximilian Wernz on 13.09.22.
//

#include <iostream>
#include "LinkedQueue.h"

int main(int argc, const char * argv[]) {
    LinkedQueue<int> lq;
    
    std::cout << lq.size() << " " << lq.isEmpty() << std::endl;
    //lq.enter(1);
    //lq.leave();
    
    for (int i=0; i < 3; ++i)
        lq.enter(i);
    for (int i=0; i < 2; ++i)
        std::cout << lq.leave() << std::endl;
    
    for (int i=0; i < 1000; ++i)
        lq.enter(i);
    for (int i=0; i < 999; ++i)
        std::cout << lq.leave() << std::endl;
}
