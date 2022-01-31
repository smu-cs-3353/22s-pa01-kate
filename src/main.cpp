//
// Created by Kate Bouis on 1/24/22.
//
#include "BruteForce.h"
#include "PriciestFirst.h"
#include "MyOptimization.h"

int main(int argc, char** argv) {
    if(argc == 2) {
        Parsing p;
        vector<Paintings> artworks = p.parse(argv[1]);
       // for (int i = 0; i < artworks.size(); i++) cout << artworks.at(i).getID() << endl;

        BruteForce brute;
        brute.heapPermutation(artworks, artworks.size(), artworks.size());
        //brute.printPerms();
        vector<Paintings> bruteSol = brute.findBest(p.getWallWidth());
        //for (int i = 0; i < bruteSol.size(); i++) cout << bruteSol.at(i).getID() << endl;

        PriciestFirst pricey;
        pricey.sort(artworks);
        vector<Paintings> priceSol = pricey.findBest(p.getWallWidth());
       // for (int i = 0; i < priceSol.size(); i++) cout << priceSol.at(i).getID() << endl;

       MyOptimization optimized;
       optimized.sort(artworks);
       vector<Paintings> mySol = optimized.findBest(p.getWallWidth());
       //for (int i = 0; i < mySol.size(); i++) cout << mySol.at(i).getID() << endl;

    }
    else {
        cout << "Incorrect number of arguments. Run program again with only one command line argument." << endl;
    }
    return 0;
}