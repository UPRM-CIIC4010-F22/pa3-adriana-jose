#pragma once

#include "Fractal.hpp"

class AbstractFractal : Fractals {
   protected:
    string name;
    int level;

   public:
    AbstractFractal(string x, int y);
    void setName(string n){name = n;}
    string getName(){return name;}
    void setLevel(int l){level = l;}
    int getLevel(){return level;}

    void draw();
};