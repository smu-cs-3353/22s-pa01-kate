//
// Created by Kate Bouis on 1/25/22.
//

#ifndef INC_22S_PA01_KATE_BRUTEFORCE_H
#define INC_22S_PA01_KATE_BRUTEFORCE_H
#include "Parsing.h"
#include <algorithm>

class BruteForce {
private:
    double best = 0.0;
    vector<vector<Paintings>> myPerms;
public:
    void heapPermutation(Paintings[], int, int);
    void permutations(vector<Paintings>&);
    vector<Paintings> findBest (int, int);
};


#endif //INC_22S_PA01_KATE_BRUTEFORCE_H
