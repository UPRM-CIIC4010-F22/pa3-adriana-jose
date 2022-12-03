#pragma once

#include "AbstractFractal.hpp"

class Circle : AbstractFractal {
   private:
    float x;
    float y;
    float r;
    int n;
    float angle;

   public:
    Circle(string name, int level, float x, float y, float r, int n);
    float getX(){return x;}
    void setX(float i){x = i;}
    float getY(){return y;}
    void setY(float i){y = i;}
    float getR(){return r;}
    void setR(float i){r = i;}
    int getN(){return n;}
    void setN(int i){n = i;}
    
    void setAngle(float i){angle = i;}
    float getAngle(){return angle;}

    void draw(float x, float y, float r, int n);

    void setName(string n){name = n;}
    string getName(){return name;}
    void setLevel(int l){level = l;}
    int getLevel(){return level;}
};