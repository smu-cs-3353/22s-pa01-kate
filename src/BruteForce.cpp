//
// Created by Kate Bouis on 1/25/22.
//

#include "BruteForce.h"
// https://www.geeksforgeeks.org/heaps-algorithm-for-generating-permutations/
void BruteForce::heapPermutation(Paintings a[], int size, int n){
    if (size == 1) {
        vector<Paintings> vec(n);
        for (int i = 0; i < n; i++) {
           // cout << a[i].getID() << " ";
           // vec.at(i) = a[i];
        }
        cout << endl;

        myPerms.push_back(vec);
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

void BruteForce::permutations(vector<Paintings>& total) {
    int length = total.size();
    Paintings p[length - 1];
    //cout << total.at(0).getID();
    for (int i = 0; i < length; i++) {
        p[i] = total.at(i);
    }
   // cout << p[0].getID();
    heapPermutation(p, length, length);
}

vector <Paintings> BruteForce::findBest(int width, int height) {

}
