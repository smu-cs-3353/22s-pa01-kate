//
// Created by Kate Bouis on 1/25/22.
//

#include "MyOptimization.h"

// https://www.geeksforgeeks.org/selection-sort/
void MyOptimization::sort(std::vector<Paintings>& unsorted) {
    valueSorted = unsorted;

    //selection sort
    int i, j, min_idx;
    int n = valueSorted.size();

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (valueSorted.at(j).getValue() > valueSorted.at(min_idx).getValue())
                min_idx = j;

        // Swap the found minimum element with the first element
        std::swap(valueSorted[min_idx], valueSorted[i]);
    }
    // now it is sorted
  // for (int k = 0; k < valueSorted.size(); k++) std::cout << valueSorted[k].getPrice() << "  " << valueSorted[k].getValue()<< std::endl;
}

std::vector<Paintings> MyOptimization::findBest(int width) {
    std::vector<Paintings> fitOnWall;
    int width_remaining = width;
    for (int i = 0; i < valueSorted.size(); i++) {
        if (valueSorted[i].getWidth() <= width_remaining) {
            fitOnWall.push_back(valueSorted[i]);
            width_remaining -= valueSorted[i].getWidth();
            price += valueSorted[i].getPrice();
        }
    }
    return fitOnWall;
}