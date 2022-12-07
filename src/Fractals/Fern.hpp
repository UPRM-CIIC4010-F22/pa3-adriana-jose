#pragma once

#include "AbstractFractal.hpp"
#include <cmath>
#include "ofMain.h"

class Fern : public AbstractFractal {
   private:
    float x;
    float y;
    int level;
    int limit = 10 * 1000;
    string name;

   public:
    Fern(string name, int level, float x, float y);
    virtual ~Fern(){}
    float getX(){return x;}
    void setX(float i){x = i;}
    float getY(){return y;}
    void setY(float i){y = i;}

    void draw();
    void drawHelper(float x, float y, int level);

    void setName(string n){name = n;}
    string getName(){return name;}
    void setLevel(int l){level = l;}
    int getLevel(){return level;}

    int getLimit(){return limit;}
};