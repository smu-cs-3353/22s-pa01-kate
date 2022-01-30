//
// Created by Kate Bouis on 1/25/22.
//

#ifndef INC_22S_PA01_KATE_PAINTINGS_H
#define INC_22S_PA01_KATE_PAINTINGS_H
using namespace std;

class Paintings {
private:
    int width;
    int height;
    int price;
    int id;
public:
    void setWidth(int);
    void setHeight(int);
    void setPrice(int);
    void setID(int);

    int getWidth();
    int getHeight();
    int getPrice();
    int getID();
    double getValue();
};


#endif //INC_22S_PA01_KATE_PAINTINGS_H
