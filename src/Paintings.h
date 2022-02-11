//
// Created by Kate Bouis on 1/25/22.
//

#ifndef INC_22S_PA01_KATE_PAINTINGS_H
#define INC_22S_PA01_KATE_PAINTINGS_H

class Paintings {
private:
    double width;
    int height;
    double price;
    int id;
public:
    void setWidth(double);
    void setHeight(int);
    void setPrice(double);
    void setID(int);

    double getWidth();
    int getHeight();
    double getPrice();
    int getID();
    double getValue();
};


#endif //INC_22S_PA01_KATE_PAINTINGS_H
