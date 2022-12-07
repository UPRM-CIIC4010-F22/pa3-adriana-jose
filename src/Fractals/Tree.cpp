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
    switch(level){ //this sets the color per level.
    case 0: ofSetColor(ofColor::darkBlue);
    break; case 1: ofSetColor(ofColor::blue);
    break; case 2: ofSetColor(ofColor::skyBlue);
    break; case 3: ofSetColor(ofColor::darkGreen);
    break; case 4: ofSetColor(ofColor::green);
    break; case 5: ofSetColor(ofColor::lightGreen);
    break; case 6: ofSetColor(ofColor::greenYellow);
    break; case 7: ofSetColor(ofColor::yellowGreen);
    break; case 8: ofSetColor(ofColor::yellow);
    break; case 9: ofSetColor(ofColor::orange);
    break; case 10: ofSetColor(ofColor::orangeRed);
    break; case 11: ofSetColor(ofColor::red);
    break; case 12: ofSetColor(ofColor::darkRed);}
    ofDrawLine(x, y, x2, y2);
    ofSetColor(ofColor::white);

    Tree::drawHelper(x2, y2, 0.7 * length, rad + 0.2 * PI, level - 1);
    Tree::drawHelper(x2, y2, 0.7 * length, rad - 0.2 * PI, level - 1);
}