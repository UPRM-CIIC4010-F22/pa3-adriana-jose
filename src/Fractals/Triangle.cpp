#include "Triangle.hpp"

Triangle::Triangle(string name, int level, float x, float y, float size) : AbstractFractal(name, level) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->name = name;
    this->level = level;
}

void Triangle::draw(){
    float size = 0.88 * ofGetHeight();
    Triangle::drawHelper(x, y, size, level);
}

void Triangle::drawHelper(float x, float y, float size, int level){
       if (0 == level) {
        return;
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    Triangle::drawHelper(x, y, size / 2, level - 1);
    switch(level){ //this sets the color per level.
    case 0: ofSetColor(ofColor::lightBlue);
    break; case 1: ofSetColor(ofColor::blueSteel);
    break; case 2: ofSetColor(ofColor::skyBlue);
    break; case 3: ofSetColor(ofColor::royalBlue);
    break; case 4: ofSetColor(ofColor::steelBlue);
    break; case 5: ofSetColor(ofColor::dodgerBlue);
    break; case 6: ofSetColor(ofColor::blueViolet);
    break; case 7: ofSetColor(ofColor::blueSteel);
    break; case 8: ofSetColor(ofColor::skyBlue);
    break; case 9: ofSetColor(ofColor::royalBlue);
    break; case 10: ofSetColor(ofColor::steelBlue);} //color for triangle //needs fixing
    ofDrawTriangle(a, b, c);
    Triangle::drawHelper((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, level - 1);
    switch(level){ //this sets the color per level.
    case 0: ofSetColor(ofColor::lightBlue);
    break; case 1: ofSetColor(ofColor::blueSteel);
    break; case 2: ofSetColor(ofColor::skyBlue);
    break; case 3: ofSetColor(ofColor::royalBlue);
    break; case 4: ofSetColor(ofColor::steelBlue);
    break; case 5: ofSetColor(ofColor::dodgerBlue);
    break; case 6: ofSetColor(ofColor::blueViolet);
    break; case 7: ofSetColor(ofColor::blueSteel);
    break; case 8: ofSetColor(ofColor::skyBlue);
    break; case 9: ofSetColor(ofColor::royalBlue);
    break; case 10: ofSetColor(ofColor::steelBlue);}
    ofDrawTriangle(a, b, c);
    Triangle::drawHelper((c.x + a.x) / 2, (c.y + a.y) / 2, size / 2, level - 1); //added the recursion to complete the sierpinski triangle
    switch(level){ //this sets the color per level.
    case 0: ofSetColor(ofColor::lightBlue);
    break; case 1: ofSetColor(ofColor::blueSteel);
    break; case 2: ofSetColor(ofColor::skyBlue);
    break; case 3: ofSetColor(ofColor::royalBlue);
    break; case 4: ofSetColor(ofColor::steelBlue);
    break; case 5: ofSetColor(ofColor::dodgerBlue);
    break; case 6: ofSetColor(ofColor::blueViolet);
    break; case 7: ofSetColor(ofColor::blueSteel);
    break; case 8: ofSetColor(ofColor::skyBlue);
    break; case 9: ofSetColor(ofColor::royalBlue);
    break; case 10: ofSetColor(ofColor::steelBlue);}
    ofDrawTriangle(a, b, c);
    ofSetColor(ofColor::white);
}