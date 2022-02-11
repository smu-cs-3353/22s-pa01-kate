//
// Created by Kate Bouis on 1/25/22.
//

#include "MyOptimization.h"

// https://www.geeksforgeeks.org/selection-sort/
void MyOptimization::sort(std::vector<Paintings>& unsorted) {
    valueSorted = unsorted;

    //selection sort
    int i, j, min_idx;

    // size of paintings vector
    int n = valueSorted.size();

    // moving boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Finding minimum element in unsorted array
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
    // paintings that we are going to be choosing for optimization
    // vector is already sorted, private variable so we're just going to use that
    std::vector<Paintings> fitOnWall;
    // making sure that we only put enough paintings we have space for
    int width_remaining = width;
    for (int i = 0; i < valueSorted.size(); i++) {
        // only putting on paintings if there's room left for them
        if (valueSorted[i].getWidth() <= width_remaining) {
            fitOnWall.push_back(valueSorted[i]);
            // subtracting used width from width remaining
            width_remaining -= valueSorted[i].getWidth();
            // adding to total price of paintings on the wall
            price += valueSorted[i].getPrice();
        }
    }
    return fitOnWall;
}