//
// Created by Kate Bouis on 1/24/22.
//
#include "BruteForce.h"
#include "PriciestFirst.h"
#include "MyOptimization.h"

/**
 * Created by Kate Bouis
 * Submitted on 2/11/2022
 * CS 3353
 */

int main(int argc, char** argv) {
    // we only want 2 parameters in the terminal program call: the name of the program and the single input file
    if(argc == 2) {
        // create parsing object to begin parsing out painting input file
        Parsing p;
        // create vector of all the artworks in the painting file
        std::vector<Paintings> artworks = p.parse(argv[1]);
       // for (int i = 0; i < artworks.size(); i++) std::cout << artworks.at(i).getID() << std::endl;

       // only allow brute force to run if there are 10 or less paintings in the file
       if (p.getNum() <= 10) {
            //create brute force object
           BruteForce brute;
           // find all possible permutations of the paintings
           brute.heapPermutation(artworks, artworks.size(), artworks.size());
           //brute.printPerms();
           // return best combination possible with given paintings
           std::vector<Paintings> bruteSol = brute.findBest(p.getWallWidth());
           //for (int i = 0; i < bruteSol.size(); i++) std::cout << bruteSol.at(i).getID() << std::endl;
           // use parsing output to print out the brute force solution
           p.output(argv[1], "bruteforce", bruteSol);

       } else {
           // if the file size is too large print out a message to the terminal
           std::cout << "Did not compute brute force solution. Input was too large. Brute force will only run on 10 paintings or less." << std::endl;
       }
       // create object for priciest first algorithm
        PriciestFirst pricey;
       // put vector into descending order by price
        pricey.sort(artworks);
        // create a vector with the optimal price solution
        std::vector<Paintings> priceSol = pricey.findBest(p.getWallWidth());
       // for (int i = 0; i < priceSol.size(); i++) std::cout << priceSol.at(i).getID() << std::endl;
       // use parsing output to print out the high value solution
        p.output(argv[1], "highvalue", priceSol);

        // create object for my heuristic
       MyOptimization optimized;
       // put vector into descending order by value (price squared / width)
       optimized.sort(artworks);
       // create a vector with the optimal value solution
       std::vector<Paintings> mySol = optimized.findBest(p.getWallWidth());
       //for (int i = 0; i < mySol.size(); i++) std::cout << mySol.at(i).getID() << std::endl;
       // use parsing output to print out the custom solution
        p.output(argv[1], "custom", mySol);
    }
    // if there are too many input files or not enough, the program will not run and will print an error message
    else {
        std::cout << "Incorrect number of arguments. Run program again with only one command line argument." << std::endl;
    }
    return 0;
}