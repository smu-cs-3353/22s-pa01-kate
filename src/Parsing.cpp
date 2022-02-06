//
// Created by Kate Bouis on 1/25/22.
//

#include "Parsing.h"

std::vector<Paintings> Parsing::parse(char* argv) {
    std::ifstream in (argv);
    if (!in) exit (EXIT_FAILURE);

    in >> wallWidth >> wallHeight;
    std::string temp;
    getline (in, temp);
    in >> num;
    getline (in, temp);
    std::string line;
    std::vector<Paintings> totalList;
    for (int i = 0; i < num; i++) {
        getline (in, line);
        std::stringstream s(line);
        s >> id >> price >> width >> height;
        Paintings p;
        p.setHeight(height);
        p.setID(id);
        p.setWidth(width);
        p.setPrice(price);
        totalList.push_back(p);
    }

    return totalList;
}

void Parsing::output(char* argv, std::string identifier, std::vector<Paintings> vec) {

    std::string file_name(argv);
    // get rid of .txt in file_name
    file_name.resize(file_name.size()-4);

    std::string file = file_name + "-" + identifier + ".txt";

    std::ofstream output (file);
    if(!output) exit (EXIT_FAILURE);

    // loop through vector and print price on first line of file
    int price = 0;
    for (int i = 0; i < vec.size(); i++)
        price += vec.at(i).getPrice();
    output << price << std::endl;

   // then each line prints painting: id, then price, then width then height
   for (int i = 0; i < vec.size(); i++)
       output << vec.at(i).getID() << " " << vec.at(i).getPrice() << " " << vec.at(i).getWidth() << " " << vec.at(i).getHeight() << std::endl;
}

int Parsing::getWallWidth() {return wallWidth;}
int Parsing::getNum() {return num;}