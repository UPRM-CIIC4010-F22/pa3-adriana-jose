#pragma once

#include "AbstractFractal.hpp"
#include <cmath>
#include "ofMain.h"

class Fern : public AbstractFractal {
   private:
    float x;
    float y;
    float n;
    int level;
    string name;

   public:
    Fern(string name, int level, float x, float y, float n);
    virtual ~Fern(){}
    float getX(){return x;}
    void setX(float i){x = i;}
    float getY(){return y;}
    void setY(float i){y = i;}
    float getN(){return n;}
    void setN(int i){n = i;}

    void draw();
    void drawHelper(float x, float y, float n);

    void setName(string n){name = n;}
    string getName(){return name;}
    void setLevel(int l){level = l;}
    int getLevel(){return level;}
};