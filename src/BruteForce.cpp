//
// Created by Kate Bouis on 1/25/22.
//

#include "BruteForce.h"
// https://www.geeksforgeeks.org/heaps-algorithm-for-generating-permutations/
void BruteForce::heapPermutation(vector<Paintings>& a, int size, int n){

    if (size == 1) {
        myPerms.push_back(a);
        return;
    }
    for (int j = 0; j < size; j++) {
        heapPermutation(a, size - 1, n);

        if (size % 2 == 1)
            swap (a[0], a[size - 1]);

        else
            swap(a[j], a[size - 1]);
    }
}

void BruteForce::printPerms() {
    for (int i = 0; i < 24; i++) {
        for (int k = 0; k < 4; k++) {
            cout << myPerms[i][k].getID() << " ";
        }
        cout << endl;
    }
}

vector <Paintings> BruteForce::findBest(int width) {
    vector<Paintings> bestCombo;
    for (int i = 0; i < myPerms.size(); i++) {
        vector<Paintings> currCombo;
        int width_remaining = width;
        int curr_price = 0;
        for (int j = 0; j < myPerms[i].size(); j++) {
            if (myPerms[i][j].getWidth() <= width_remaining) {
                curr_price += myPerms[i][j].getPrice();
                currCombo.push_back(myPerms[i][j]);
            } else {
                break;
            }
            width_remaining -= myPerms[i][j].getWidth();
        }
        if (curr_price > best) {
            best = curr_price;
            bestCombo = currCombo;
        }
    }
    return bestCombo;
}