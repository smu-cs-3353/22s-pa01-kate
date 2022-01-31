//
// Created by Kate Bouis on 1/25/22.
//

#include "PriciestFirst.h"

// https://www.geeksforgeeks.org/selection-sort/
void PriciestFirst::sort(vector<Paintings>& unsorted) {
    priciest = unsorted;

    //selection sort
    int i, j, min_idx;
    int n = priciest.size();

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (priciest.at(j).getPrice() > priciest.at(min_idx).getPrice())
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(priciest[min_idx], priciest[i]);
    }
    // now priciest is sorted
  //  for (int k = 0; k < priciest.size(); k++) cout << priciest[k].getPrice() << endl;
}

vector<Paintings> PriciestFirst::findBest(int width) {
    vector<Paintings> fitOnWall;
    int width_remaining = width;
    for (int i = 0; i < priciest.size(); i++) {
        if (priciest[i].getWidth() <= width_remaining) {
            fitOnWall.push_back(priciest[i]);
            width_remaining -= priciest[i].getWidth();
            price += priciest[i].getPrice();
        }
    }
    return fitOnWall;
}