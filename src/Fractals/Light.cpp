#include "Light.hpp"

Light::Light(string name, int level, float x, float y, float size) : AbstractFractal(name, level) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->name = name;
    this->level = level;
}

void Light::draw(){
    float size = 0.88 * ofGetHeight();
    Light::drawHelper(x, y, size, level);
}

void Light::drawHelper(float x, float y, float size, int level){
       if (0 == level) {
        return;
    }


    ofPoint p1(150,150);
    ofPoint p2(x + size, y );
    ofPoint p3(x , y + size);   
    ofDrawTriangle(p1, p2, p3);

    
    switch(level){ //this sets the color per level.
    case 0: ofSetColor(ofColor::blue);
    break; case 1: ofSetColor(ofColor::gray);
    break; case 2: ofSetColor(ofColor::brown);
    break; case 3: ofSetColor(ofColor::red);
    break; case 4: ofSetColor(ofColor::orange);
    break; case 5: ofSetColor(ofColor::yellow);
    break; case 6: ofSetColor(ofColor::green);
    break; case 7: ofSetColor(ofColor::blue);
    break; case 8: ofSetColor(ofColor::purple);
    break; case 9: ofSetColor(ofColor::pink);
    break; case 10: ofSetColor(ofColor::lightBlue);
    break; case 11: ofSetColor(ofColor::white);
    }
    ofDrawTriangle(p1, p2, p3);
    ofSetColor(ofColor::white);

    Light::drawHelper(x, y, size - 80, level - 1);
    
    
    }