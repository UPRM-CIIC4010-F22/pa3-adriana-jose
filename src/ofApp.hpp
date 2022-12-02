#pragma once

#include <cmath>

#include "ofMain.h"

class ofApp : public ofBaseApp {
  private:
    char mode = '1';
    float angle = 0;
    unsigned int fullscreen;
    int level = 0; //levels go from -3 to 3.

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

    void drawMode1(float x, float y, float r, int n);
    void drawMode2(float x, float y, int n, float length, float rad);
    void drawMode3(float x, float y, float size, int n);
    void drawMode4(float x, float y, float n);
};
