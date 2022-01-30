//
// Created by Kate Bouis on 1/25/22.
//

#ifndef INC_22S_PA01_KATE_BRUTEFORCE_H
#define INC_22S_PA01_KATE_BRUTEFORCE_H
#include "Parsing.h"

class BruteForce {
private:
    double best = 0.0;
public:
    vector<vector<Paintings>> permutations(vector<Paintings>);
    vector<Paintings> findBest (vector<vector<Paintings>>, int, int);
};


#endif //INC_22S_PA01_KATE_BRUTEFORCE_H
