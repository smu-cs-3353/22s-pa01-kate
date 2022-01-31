//
// Created by Kate Bouis on 1/24/22.
//
#include "BruteForce.h"

int main(int argc, char** argv) {
    if(argc == 2) {
        Parsing p;
        vector<Paintings> artworks = p.parse(argv[1]);
       // for (int i = 0; i < artworks.size(); i++) cout << artworks.at(i).getID() << endl;

       /**
        * fix during office hours:
        * memory issues when trying to copy vector to array
        */
        BruteForce brute;
        brute.heapPermutation(artworks, artworks.size(), artworks.size());
        brute.printPerms();
    }
    else {
        cout << "Incorrect number of arguments. Run program again with only one command line argument." << endl;
    }
    return 0;
}