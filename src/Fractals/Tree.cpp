#include "Tree.hpp"

Tree::Tree(string name, int level, float x, float y, float length, float rad, int n) : AbstractFractal(name, level) {
    this->x = x;
    this->y = y;
    this->length = length;
    this->rad = rad;
    this->n = n;
    this->name = name;
    this->level = level;
}

void Tree::draw(){ 
    Tree::drawHelper(x, y, length, rad, n);
}

void Tree::drawHelper(float x, float y, float length, float rad, int n){
    if (n == level) return;

    float x2 = x + length * cos(rad);
    float y2 = y + length * sin(rad);

    ofDrawLine(x, y, x2, y2);

    ofFill();
    ofSetColor(ofColor::paleVioletRed); //color for the most beautiful tree y'all ever seen <3
    ofDrawLine(x, y, x2, y2);
    ofSetColor(ofColor::white);

    Tree::drawHelper(x2, y2, 0.7 * length, rad + 0.2 * PI, n - 1);
    Tree::drawHelper(x2, y2, 0.7 * length, rad - 0.2 * PI, n - 1);
}