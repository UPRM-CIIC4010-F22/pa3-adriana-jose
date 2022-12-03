#pragma once

#include "Fractal.hpp"

class AbstractFractal : Fractals {
   public:
    string name;
    int level;
    AbstractFractal(string x, int y) {
        name = x;
        level = y;
    };

   private:
    void setName(string n){name = n;}
    string getName(){return name;}
    void setLevel(int l){level = l;}
    int getLevel(){return level;}

    void draw();
};