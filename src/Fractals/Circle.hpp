#pragma once

#include "AbstractFractal.hpp"
#include <cmath>
#include "ofMain.h"

class Circle : public AbstractFractal {
   private:
    float x;
    float y;
    float r;
    float angle = 0;
    int level;
    string name;

   public:
    Circle(string name, int level, float x, float y, float r);
    virtual ~Circle(){}
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
};