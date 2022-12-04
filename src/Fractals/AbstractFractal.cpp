#include "AbstractFractal.hpp"

AbstractFractal::AbstractFractal(string name, int level) : Fractals() {
    this->name = name;
    this->level = level;
};

AbstractFractal::~AbstractFractal(){

};