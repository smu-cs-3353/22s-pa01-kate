//
// Created by Kate Bouis on 1/25/22.
//

#include "MyOptimization.h"

// https://www.geeksforgeeks.org/selection-sort/
void MyOptimization::sort(vector<Paintings>& unsorted) {
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
        swap(valueSorted[min_idx], valueSorted[i]);
    }
    // now it is sorted
   // for (int k = 0; k < valueSorted.size(); k++) cout << valueSorted[k].getPrice() << "  " << valueSorted[k].getValue()<< endl;
}

vector<Paintings> MyOptimization::findBest(int width) {
//    vector<Paintings> fitOnWall;
//    int width_remaining = width;
//    for (int i = 0; i < priciest.size(); i++) {
//        if (priciest[i].getWidth() <= width_remaining) {
//            fitOnWall.push_back(priciest[i]);
//            width_remaining -= priciest[i].getWidth();
//            price += priciest[i].getPrice();
//        }
//    }
//    return fitOnWall;
}