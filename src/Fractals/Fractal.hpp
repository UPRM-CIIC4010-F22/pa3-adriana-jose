#pragma once

#include "ofMain.h"
#include <cmath>

class Fractals {
   public:
    virtual void draw(){}
    virtual int getLevel(){}
    virtual void setLevel(int l){}
    virtual string getName(){}
};