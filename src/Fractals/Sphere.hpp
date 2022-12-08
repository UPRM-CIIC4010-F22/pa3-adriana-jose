#pragma once

#include "AbstractFractal.hpp"
#include <cmath>
#include "ofMain.h"

class Sphere : public AbstractFractal {
   private:
    float x;
    float y;
    float r;
    float angle = 0;
    int level;
    int limit = 6;
    string name;

   public:
    Sphere(string name, int level, float x, float y, float r);
    virtual ~Sphere(){}
    float getX(){return x;}
    void setX(float i){x = i;}
    float getY(){return y;}
    void setY(float i){y = i;}
    float getR(){return r;}
    void setR(float i){r = i;}

    void draw();
    void drawHelper(float x, float y, float r, int level);

    void setName(string n){name = n;}
    string getName(){return name;}
    void setLevel(int l){level = l;}
    int getLevel(){return level;}

    int getLimit(){return limit;}
};