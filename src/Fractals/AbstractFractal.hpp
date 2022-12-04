#pragma once

#include "Fractal.hpp"

class AbstractFractal : public Fractals {
   protected:
    string name;
    int level;

   public:
    AbstractFractal(string x, int y);
    virtual ~AbstractFractal();
    void setName(string n){name = n;}
    string getName(){return name;}
    void setLevel(int l){level = l;}
    int getLevel(){return level;}

    virtual void draw() = 0;
};