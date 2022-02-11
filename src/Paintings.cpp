//
// Created by Kate Bouis on 1/25/22.
//

#include "Paintings.h"
// getters and setters for my paintings objects
void Paintings::setWidth(double w) {width = w;}
void Paintings::setHeight(int h) {height = h;}
void Paintings::setPrice(double p) {price = p;}
void Paintings::setID(int i) {id = i;}

double Paintings::getWidth() {return width;}
int Paintings::getHeight() {return height;}
double Paintings::getPrice() {return price;}
int Paintings::getID() {return id;}
// "value" is how i calculate my custom heuristic: it gives a little more significance to price than to total value per square footage, but it's turned out really good results
double Paintings::getValue() {
    return (price*price)/width;
}