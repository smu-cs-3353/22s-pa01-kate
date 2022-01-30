//
// Created by Kate Bouis on 1/25/22.
//

#include "Paintings.h"
void Paintings::setWidth(int w) {width = w;}
void Paintings::setHeight(int h) {height = h;}
void Paintings::setPrice(int p) {price = p;}
void Paintings::setID(int i) {id = i;}

int Paintings::getWidth() {return width;}
int Paintings::getHeight() {return height;}
int Paintings::getPrice() {return price;}
int Paintings::getID() {return id;}
double Paintings::getValue() {return price/width;}