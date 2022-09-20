//
//  main.cpp
//  a1
//
//  Created by Maximilian Wernz on 12.09.22.
//

#include <iostream>
#include "IntVector.h"
#include "ooptool.h"

int main(int argc, const char * argv[]) {
    argsp_t argsp(argc, argv);
    int start = argsp.int_pos(0, 1);
    int end = argsp.int_pos(1, 10000);
    int diff = end - start;
    IntVector iv(diff + 1);
    std::cout << iv.size() << std::endl;
    
    for (int i=0; i <= diff; ++i)
        iv[i] = start++;
    
    int sumA = 0;
    for (auto it=iv.begin(); it != iv.end(); ++it)
        sumA += *it;
    
    std::cout << sumA << std::endl;
    
    int sumB = 0;
    for (auto it : iv)
        sumB += it;
    std::cout << sumB << std::endl;
}
