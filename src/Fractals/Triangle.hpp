#pragma once

#include "AbstractFractal.hpp"
#include <cmath>
#include "ofMain.h"

class Triangle : public AbstractFractal {
   private:
    float x;
    float y;
    float size;
    int level;
    int limit = 9; //extended the limit to appreaciate the recursive sierpinski triangle
    string name;

   public:
    Triangle(string name, int level, float x, float y, float size);
    virtual ~Triangle(){}
    float getX(){return x;}
    void setX(float i){x = i;}
    float getY(){return y;}
    void setY(float i){y = i;}
    float getSize(){return size;}
    void setSize(float i){size = i;}

    void draw();
    void drawHelper(float x, float y, float r, int level);

    void setName(string n){name = n;}
    string getName(){return name;}
    void setLevel(int l){level = l;}
    int getLevel(){return level;}

    int getLimit(){return limit;}
};