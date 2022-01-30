//
// Created by Kate Bouis on 1/24/22.
//
#include "BruteForce.h"

int main(int argc, char** argv) {
    if(argc == 2) {
        Parsing p;
        vector<Paintings> artworks = p.parse(argv[1]);

        BruteForce brute;
        brute.permutations(artworks);
    }
    else {
        cout << "Incorrect number of arguments. Run program again with only one command line argument." << endl;
    }
    return 0;
}