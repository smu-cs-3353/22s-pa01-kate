//
// Created by Kate Bouis on 1/25/22.
//

#ifndef INC_22S_PA01_KATE_MYOPTIMIZATION_H
#define INC_22S_PA01_KATE_MYOPTIMIZATION_H

#include "Parsing.h"
#include <utility>

class MyOptimization {
private:
    double price = 0.0;
    std::vector<Paintings> valueSorted;
public:
    void sort(std::vector<Paintings>&);
    std::vector<Paintings> findBest(int);
};


#endif //INC_22S_PA01_KATE_MYOPTIMIZATION_H
