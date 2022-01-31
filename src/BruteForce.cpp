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

vector <Paintings> BruteForce::findBest(int width, int height) {

}
