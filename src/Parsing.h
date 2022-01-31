//
// Created by Kate Bouis on 1/25/22.
//

#ifndef INC_22S_PA01_KATE_PARSING_H
#define INC_22S_PA01_KATE_PARSING_H
// more like docHandler but i named this before deciding i wanted it to handle output as well
#include "Paintings.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Parsing {
private:
    int wallWidth;
    int wallHeight;
    int width;
    int height;
    int price;
    int id;
    int num;
public:
    //parse
    std::vector<Paintings> parse (char*);
    //output
    void output (char*, std::string, std::vector<Paintings>);
    int getWallWidth();
};

#endif //INC_22S_PA01_KATE_PARSING_H