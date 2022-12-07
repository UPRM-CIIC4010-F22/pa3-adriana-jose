#include "Tree.hpp"

Tree::Tree(string name, int level, float x, float y, float length, float rad) : AbstractFractal(name, level) {
    this->x = x;
    this->y = y;
    this->length = length;
    this->rad = rad;
    this->name = name;
    this->level = level;
}

void Tree::draw(){ 
    Tree::drawHelper(x, y, length, rad, level);
    Tree::drawHelper(x / 2, y, length / 3.5, rad, level); //left baby tree
    Tree::drawHelper(x * 1.5, y, length / 3.5, rad, level); // right baby tree
}

void Tree::drawHelper(float x, float y, float length, float rad, int level){
    if (0 == level) return;

    float x2 = x + length * cos(rad);
    float y2 = y + length * sin(rad);

    ofDrawLine(x, y, x2, y2);

    ofFill();
    ofSetColor(ofColor::paleVioletRed); //color for the most beautiful tree y'all ever seen <3
    ofDrawLine(x, y, x2, y2);
    ofSetColor(ofColor::white);

    Tree::drawHelper(x2, y2, 0.7 * length, rad + 0.2 * PI, level - 1);
    Tree::drawHelper(x2, y2, 0.7 * length, rad - 0.2 * PI, level - 1);
}