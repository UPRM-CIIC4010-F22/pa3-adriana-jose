#include "Fern.hpp"

Fern::Fern(string name, int level, float x, float y) : AbstractFractal(name, level) {
    this->x = x;
    this->y = y;
    this->name = name;
    this->level = level;
}

void Fern::draw(){
    Fern::drawHelper(x, y, level);
    colorLevel = level / 1000;
}

void Fern::drawHelper(float x, float y, int level){
    if (0 == level) return;

    float r = ofRandom(1);

    float px = ofMap(x, -2.1820, 2.6558, 0, ofGetWidth());
    float py = ofMap(y, 0, 9.9983, ofGetHeight(), 0);

    ofFill();
    switch(colorLevel){ //this sets the color per level.
    case 0: ofSetColor(ofColor::red);
    break; case 1: ofSetColor(ofColor::orangeRed);
    break; case 2: ofSetColor(ofColor::orange);
    break; case 3: ofSetColor(ofColor::yellow);
    break; case 4: ofSetColor(ofColor::yellowGreen);
    break; case 5: ofSetColor(ofColor::greenYellow);
    break; case 6: ofSetColor(ofColor::lightGreen);
    break; case 7: ofSetColor(ofColor::darkSeaGreen);
    break; case 8: ofSetColor(ofColor::seaGreen);
    break; case 9: ofSetColor(ofColor::forestGreen);
    break; case 10: ofSetColor(ofColor::green);}
    ofDrawCircle(px, py, 0.6);
    ofSetColor(ofColor::white);

    if (r < 0.01)
        Fern::drawHelper(0, 0.16 * y, level - 1);

    else if (r < 0.86)
        Fern::drawHelper(0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6, level - 1);

    else if (r < 0.93)
        Fern::drawHelper(0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6, level - 1);

    else
        Fern::drawHelper(-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44, level - 1);
}