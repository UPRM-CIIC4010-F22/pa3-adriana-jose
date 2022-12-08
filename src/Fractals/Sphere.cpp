#include "Sphere.hpp"

Sphere::Sphere(string name, int level, float x, float y, float r) : AbstractFractal(name, level) {
    this->x = x;
    this->y = y;
    this->r = r;
    this->name = name;
    this->level = level;
}

void Sphere::draw(){
    angle += 0.01;
    Sphere::drawHelper(x, y, r, level);
}

void Sphere::drawHelper(float x, float y, float r, int level){
    if (0 == level) return;

    int delta = r * 0.35;

    switch(level){ //this sets the color per level.
    case 0: ofSetColor(ofColor::yellow);
    break; case 1: ofSetColor(ofColor::darkRed);
    break; case 2: ofSetColor(ofColor::mediumPurple);
    break; case 3: ofSetColor(ofColor::royalBlue);
    break; case 4: ofSetColor(ofColor::mistyRose);
    break; case 5: ofSetColor(ofColor::ghostWhite);
    break; case 6: ofSetColor(ofColor::darkMagenta);}
    ofDrawSphere(x, y, r);
    ofSetColor(ofColor::white);

    float angle1 = angle;
    float angle2 = PI / 3 + angle;
    
    Sphere::drawHelper(x + r * cos(angle1), y + r * sin(angle2), delta, level - 1);
    Sphere::drawHelper(x + r * cos(angle2), y + r * sin(angle1), delta, level - 1);
}