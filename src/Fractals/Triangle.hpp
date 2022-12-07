#pragma once

#include "AbstractFractal.hpp"
#include <cmath>
#include "ofMain.h"

class Triangle : public AbstractFractal {
   private:
    float x;
    float y;
    float size;
    int n;
    int level;

   public:
    Triangle(string name, int level, float x, float y, float size, int n);
    virtual ~Triangle(){}
    float getX(){return x;}
    void setX(float i){x = i;}
    float getY(){return y;}
    void setY(float i){y = i;}
    float getSize(){return size;}
    void setSize(float i){size = i;}
    int getN(){return n;}
    void setN(int i){n = i;}

    void draw();
    void drawHelper(float x, float y, float r, int n);

    void setName(string n){name = n;}
    string getName(){return name;}
    void setLevel(int l){level = l;}
    int getLevel(){return level;}
};