//
// Created by Kate Bouis on 1/24/22.
//
#include "BruteForce.h"
#include "PriciestFirst.h"
#include "MyOptimization.h"

int main(int argc, char** argv) {
    if(argc == 2) {
        Parsing p;
        std::vector<Paintings> artworks = p.parse(argv[1]);
       // for (int i = 0; i < artworks.size(); i++) std::cout << artworks.at(i).getID() << std::endl;

        BruteForce brute;
        brute.heapPermutation(artworks, artworks.size(), artworks.size());
        //brute.printPerms();
        std::vector<Paintings> bruteSol = brute.findBest(p.getWallWidth());
        //for (int i = 0; i < bruteSol.size(); i++) std::cout << bruteSol.at(i).getID() << std::endl;

        PriciestFirst pricey;
        pricey.sort(artworks);
        std::vector<Paintings> priceSol = pricey.findBest(p.getWallWidth());
       // for (int i = 0; i < priceSol.size(); i++) std::cout << priceSol.at(i).getID() << std::endl;

       MyOptimization optimized;
       optimized.sort(artworks);
       std::vector<Paintings> mySol = optimized.findBest(p.getWallWidth());
       //for (int i = 0; i < mySol.size(); i++) std::cout << mySol.at(i).getID() << std::endl;

        p.output(argv[1], "bruteforce", bruteSol);
        p.output(argv[1], "highvalue", priceSol);
        p.output(argv[1], "custom", mySol);
    }
    else {
        std::cout << "Incorrect number of arguments. Run program again with only one command line argument." << std::endl;
    }
    return 0;
}