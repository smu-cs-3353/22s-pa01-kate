//
// Created by Kate Bouis on 1/25/22.
//

#ifndef INC_22S_PA01_KATE_PAINTINGS_H
#define INC_22S_PA01_KATE_PAINTINGS_H


class Paintings {
private:
    int width;
    int height;
    int price;
    int id;
    double value;
public:
    void setWidth(int);
    void setHeight(int);
    void setPrice(int);
    void setID(int);
    void setValue();

    int getWidth();
    int getHeight();
    int getPrice();
    int getID();
    double getValue();
};


#endif //INC_22S_PA01_KATE_PAINTINGS_H
