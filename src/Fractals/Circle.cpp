#include "Circle.hpp"

Circle::Circle(string name, int level, float x, float y, float r) : AbstractFractal(name, level) {
    this->x = x;
    this->y = y;
    this->r = r;
    this->name = name;
    this->level = level;
}

void Circle::draw(){
    angle += 0.01;
    Circle::drawHelper(x, y, r, level);
}

void Circle::drawHelper(float x, float y, float r, int level){
    if (0 == level) return;

    int delta = r * 0.35;
    ofDrawCircle(x, y, r);

    
    ofSetColor(ofColor::seaGreen); //color for THAT figure
    ofDrawCircle(x, y, r);
    ofSetColor(ofColor::white);

    float angle1 = angle;
    float angle2 = PI / 3 + angle;
    float angle3 = PI + angle;
    float angle4 = 2 * PI / 3 + angle;
    float angle5 = 4 * PI / 3 + angle;
    float angle6 = 5 * PI / 3 + angle;
    Circle::drawHelper(x + r * cos(angle1), y + r * sin(angle1), delta, level - 1);
    Circle::drawHelper(x + r * cos(angle2), y + r * sin(angle2), delta, level - 1);
    Circle::drawHelper(x + r * cos(angle3), y + r * sin(angle3), delta, level - 1);
    Circle::drawHelper(x + r * cos(angle4), y + r * sin(angle4), delta, level - 1);
    Circle::drawHelper(x + r * cos(angle5), y + r * sin(angle5), delta, level - 1);
    Circle::drawHelper(x + r * cos(angle6), y + r * sin(angle6), delta, level - 1);
}