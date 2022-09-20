#include "ooptool.h"


int main(int argc, char* argv[]) 
{
    argsp_t argsp(argc, argv);

    double s = argsp.double_pos(2, 50.0)/100;
    
    std::string input = argsp.pos(0);
    std::string output = argsp.pos(1);

    std::vector<int> pgm = read_pgm(input);

    int maxV = pgm[2];
    for(size_t i = 3; i < pgm.size(); ++i)
    {
        if(maxV * s > pgm[i])
            pgm[i] = 0;
        else
            pgm[i] = maxV;
    }

    save_pgm(output, pgm);
}