#pragma once

#include <cmath>

#include "ofMain.h"
#include "Circle.hpp"
#include "tree.hpp"
#include "Triangle.hpp"
#include "Fern.hpp"
#include "AbstractFractal.hpp"
#include "Fractal.hpp"
#include "Light.hpp"
#include "Sphere.hpp"

class ofApp : public ofBaseApp {
  private:
    char mode = '1';
    unsigned int fullscreen;
    int level = 0; //levels go from -3 to 3.
    int index = 0;
    bool animation = false;
    bool animationUp = true;
    int animationTimer;

    vector<Fractals *> polymorphic;

  public:
    void setup();
    void update();
    void draw();
    int getLevel(){return level;}
    void setLevel(int L){level = L;} //fixed from int to void

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void drawMode2(float x, float y, int n, float length, float rad);
    void drawMode3(float x, float y, float size, int n);
    void drawMode4(float x, float y, float n);
    void drawMode5(float x, float y, float r);
    void drawMode6(float x, float y, float r);
};
