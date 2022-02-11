//
// Created by Kate Bouis on 1/25/22.
//

#include "Parsing.h"

// parse out input file into vector of painting objects
std::vector<Paintings> Parsing::parse(char* argv) {
    // open the input file stream and ensure that it could make it into the file
    std::ifstream in (argv);
    if (!in) exit (EXIT_FAILURE);

    // first line contains wall measurements
    in >> wallWidth >> wallHeight;
    std::string temp;
    // grab that new line
    getline (in, temp);
    // second line contains number of paintings
    in >> num;
    // grab that new line
    getline (in, temp);
    std::string line;
    // now begin to iterate through the file to populate vector
    std::vector<Paintings> totalList;
    for (int i = 0; i < num; i++) {
        // set all painting attributes to their given values in the input file
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
    // return vector of paintings
    return totalList;
}

void Parsing::output(char* argv, std::string identifier, std::vector<Paintings> vec) {

    // changing char* to string, so that the input file's name can be edited to create output file names
    std::string file_name(argv);
    // get rid of .txt in file_name
    file_name.resize(file_name.size()-4);

    // add identifier to each file name so that we know what solution belongs to which method
    std::string file = file_name + "-" + identifier + ".txt";

    // create an output file stream
    std::ofstream output (file);
    if(!output) exit (EXIT_FAILURE);

    // loop through vector to find price and print price on first line of file
    int price = 0;
    for (int i = 0; i < vec.size(); i++)
        price += vec.at(i).getPrice();
    output << price << std::endl;

   // then each line prints painting: id, then price, then width then height
   for (int i = 0; i < vec.size(); i++)
       output << vec.at(i).getID() << " " << vec.at(i).getPrice() << " " << vec.at(i).getWidth() << " " << vec.at(i).getHeight() << std::endl;
    // close output and we're done
    output.close();
}

int Parsing::getWallWidth() {return wallWidth;}
int Parsing::getNum() {return num;}