//
// Created by Kate Bouis on 1/25/22.
//

#include "BruteForce.h"
// https://www.geeksforgeeks.org/heaps-algorithm-for-generating-permutations/
void BruteForce::heapPermutation(std::vector<Paintings>& a, int size, int n){

    /** heap's permutation works by starting at the end of an array, keeping that last element in place,
     * then swapping out the rest of the elements until you have every permutation with that last element in
     * place. Then you trade out that last element for a different element in the array and repeat.
    **/
    // base case for recursive algorithm
    // myPerms is a private vector of vector of Paintings variable that contains all permutations.
    if (size == 1) {
        myPerms.push_back(a);
        return;
    }
    // heaps permutation is recursive. we decrease the size of the array on each function call.
    for (int j = 0; j < size; j++) {
        heapPermutation(a, size - 1, n);

        // if the vector has an odd number of elements, you swap the last element with the first after computing all permutations with the last element in place
        if (size % 2 == 1)
            std::swap (a[0], a[size - 1]);
        //if the vector has an even number of elements, you swap the last element with the element at your current iteration after computing all permutations with the last element in place
        else
            std::swap(a[j], a[size - 1]);
    }
}

void BruteForce::printPerms() {
    // this was just a function made for my personal testing purposes to make sure permutations were correct
    // this was with a dataset of 4 paintings, which has 24 total permutations. i looped through each of the 4 elements of each
    // permutation so that i could make sure they were all unique
    for (int i = 0; i < 24; i++) {
        for (int k = 0; k < 4; k++) {
            std::cout << myPerms[i][k].getID() << " ";
        }
        std::cout << std::endl;
    }
}

std::vector <Paintings> BruteForce::findBest(int width) {
    std::vector<Paintings> bestCombo;
    // loop through vector of permutations
    for (int i = 0; i < myPerms.size(); i++) {
        std::vector<Paintings> currCombo;
        int width_remaining = width;
        int curr_price = 0;
        // loop through each vector within vector of permutations
        for (int j = 0; j < myPerms[i].size(); j++) {
            // add price to price on the wall if the painting can fit
            if (myPerms[i][j].getWidth() <= width_remaining) {
                curr_price += myPerms[i][j].getPrice();
                currCombo.push_back(myPerms[i][j]);
            } else {
                // if the painting can't fit, we don't just move onto the next in the series like we do with the other
                // two heuristics, because brute force already covers all possible permutations so that is unnecessary
                break;
            }
            // account for width of painting just added
            width_remaining -= myPerms[i][j].getWidth();
        }
        // if the price of the permutation at i is better than any prices before, this is the permutation that
        // we are selecting until another better one is found
        if (curr_price > best) {
            best = curr_price;
            bestCombo = currCombo;
        }
    }
    // return vector of permutation that gives highest price
    return bestCombo;
}