//
// Created by Kate Bouis on 1/25/22.
//

#ifndef INC_22S_PA01_KATE_BRUTEFORCE_H
#define INC_22S_PA01_KATE_BRUTEFORCE_H
#include "Parsing.h"
#include <utility>

class BruteForce {
private:
    double best = 0.0;
    vector<vector<Paintings>> myPerms;
public:
    void heapPermutation(vector<Paintings>&, int, int);
    vector<Paintings> findBest (int, int);
    void printPerms();
};


#endif //INC_22S_PA01_KATE_BRUTEFORCE_H
