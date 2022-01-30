//
// Created by Kate Bouis on 1/24/22.
//
#include "Parsing.h"

int main(int argc, char** argv) {
    if(argc == 2) {
        Parsing p;
        vector<Paintings> test = p.parse(argv[1]);

    }
    else {
        cout << "Incorrect number of arguments. Run program again with only one command line argument." << endl;
    }
    return 0;
}