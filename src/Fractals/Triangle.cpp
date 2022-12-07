#include "Triangle.hpp"

Triangle::Triangle(string name, int level, float x, float y, float size, int n) : AbstractFractal(name, level) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->n = n;
    this->name = name;
    this->level = level;
}

void Triangle::draw(){
    float size = 0.88 * ofGetHeight();
    Triangle::drawHelper(x, y, size, n);
}

void Triangle::drawHelper(float x, float y, float size, int n){
       if (n == level) {
        return;
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofDrawTriangle(a, b, c);

    ofSetColor(ofColor::steelBlue); //color for triangle
    ofDrawTriangle(a, b, c);
    ofSetColor(ofColor::white);

    Triangle::drawHelper(x, y, size / 2, n - 1);
    Triangle::drawHelper((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
}