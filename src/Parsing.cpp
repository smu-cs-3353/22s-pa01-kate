//
// Created by Kate Bouis on 1/25/22.
//

#include "Parsing.h"

vector<Paintings> Parsing::parse(char* argv) {
    ifstream in (argv);
    if (!in) exit (EXIT_FAILURE);

    in >> wallWidth >> wallHeight;
    string temp;
    getline (in, temp);
    in >> num;
    getline (in, temp);
    string line;
    vector<Paintings> totalList;
    for (int i = 0; i < num; i++) {
        getline (in, line);
        stringstream s(line);
        s >> id >> price >> width >> height;
        Paintings p;
        p.setHeight(height);
        p.setID(id);
        p.setWidth(width);
        p.setPrice(price);
        p.setWallWidth(wallWidth);
        p.setWallHeight(wallHeight);
        totalList.push_back(p);
    }

    return totalList;
}

void Parsing::output(char *, vector<Paintings>) {

}

int Parsing::getWallWidth() {return wallWidth;}
int Parsing::getWallHeight() {return wallHeight;}
