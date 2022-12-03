#include "Circle.hpp"

Circle::Circle(float x, float y, float r, int n) : AbstractFractal(name, level) {
    this->x = x;
    this->y = y;
    this->r = r;
    this->n = n;
}

void Circle::draw(float x, float y, float r, int n){
        if (n == level) return;

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
    Circle::draw(x + r * cos(angle1), y + r * sin(angle1), delta, n - 1);
    Circle::draw(x + r * cos(angle2), y + r * sin(angle2), delta, n - 1);
    Circle::draw(x + r * cos(angle3), y + r * sin(angle3), delta, n - 1);
    Circle::draw(x + r * cos(angle4), y + r * sin(angle4), delta, n - 1);
    Circle::draw(x + r * cos(angle5), y + r * sin(angle5), delta, n - 1);
    Circle::draw(x + r * cos(angle6), y + r * sin(angle6), delta, n - 1);
}