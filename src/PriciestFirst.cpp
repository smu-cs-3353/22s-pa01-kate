//
// Created by Kate Bouis on 1/25/22.
//

#include "PriciestFirst.h"

// https://www.geeksforgeeks.org/selection-sort/
void PriciestFirst::sort(std::vector<Paintings>& unsorted) {
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
        std::swap(priciest[min_idx], priciest[i]);
    }
    // now priciest is sorted
  //  for (int k = 0; k < priciest.size(); k++) std::cout << priciest[k].getPrice() << std::endl;
}

std::vector<Paintings> PriciestFirst::findBest(int width) {
    // finding vectors that can fit on the wall using private variable vector "priciest" which is already sorted
    std::vector<Paintings> fitOnWall;
    int width_remaining = width;
    // loop through vector which is sorted from most to least expensive
    for (int i = 0; i < priciest.size(); i++) {
        // if there's space on the wall, add next painting
        if (priciest[i].getWidth() <= width_remaining) {
            fitOnWall.push_back(priciest[i]);
            // subtract painting width from width left
            width_remaining -= priciest[i].getWidth();
            // add price of painting to total price of wall
            price += priciest[i].getPrice();
        }
    }
    return fitOnWall;
}