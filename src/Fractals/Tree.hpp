#pragma once

#include "AbstractFractal.hpp"
#include <cmath>
#include "ofMain.h"

class Tree : public AbstractFractal {
   private:
    float x;
    float y;
    float length;
    float rad;
    int level;
    int limit = 12;
    string name;

   public:
    Tree(string name, int level, float x, float y, float length, float rad);
    virtual ~Tree(){}
    float getX(){return x;}
    void setX(float i){x = i;}
    float getY(){return y;}
    void setY(float i){y = i;}
    float getRad(){return rad;}
    void setRad(float i){rad = i;}
    float getLength(){return length;}
    void setLength(float i){length = i;}

    void draw();
    void drawHelper(float x, float y, float length, float rad, int level);

    void setName(string n){name = n;}
    string getName(){return name;}
    void setLevel(int l){level = l;}
    int getLevel(){return level;}

    int getLimit(){return limit;}
};