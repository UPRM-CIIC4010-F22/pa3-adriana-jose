#include "Fern.hpp"

Fern::Fern(string name, int level, float x, float y, float n) : AbstractFractal(name, level) {
    this->x = x;
    this->y = y;
    this->n = n;
    this->name = name;
    this->level = level;
}

void Fern::draw(){
    Fern::drawHelper(x, y, n);
}

void Fern::drawHelper(float x, float y, float n){
    if (n == level) return;

    float r = ofRandom(1);

    float px = ofMap(x, -2.1820, 2.6558, 0, ofGetWidth());
    float py = ofMap(y, 0, 9.9983, ofGetHeight(), 0);

    ofFill();
    ofSetColor(ofColor::lightYellow); //color for the leaf
    ofDrawCircle(px, py, 0.6);
    ofSetColor(ofColor::white);

    if (r < 0.01)
        Fern::drawHelper(0, 0.16 * y, n - 1);

    else if (r < 0.86)
        Fern::drawHelper(0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6, n - 1);

    else if (r < 0.93)
        Fern::drawHelper(0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6, n - 1);

    else
        Fern::drawHelper(-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44, n - 1);
}