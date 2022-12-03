#include "ofApp.hpp"
#include "SnowFlake.hpp"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetEscapeQuitsApp(false);
    fullscreen = 0;
    vector<Fractals *> polymorphic;
    Circle *circle = new Circle(ofGetWidth() / 2, ofGetHeight() / 2, 0.31 * ofGetHeight(), 3);

    polymorphic.push_back(circle);
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

    ofNoFill();
    polymorphic[index]->draw();
    switch (mode) {
    case '2': {
        // Tree
        float length = 0.31 * ofGetHeight();
        drawMode2(ofGetWidth() / 2, ofGetHeight() - 20, 10, length, 1.5 * PI);
    } break;
    case '3': {
        // Sierpinski Triangle
        float size = 0.88 * ofGetHeight();
        drawMode3((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, size, 7);
    } break;
    case '4':
        // Barnsley Fern
        drawMode4(0, 0, 10 * 1000);
        break;
    case '5':
        // Koch SnowFlake work here for sure
        SnowFlake().draw( level );
        break;
    }
}

void ofApp::drawMode2(float x, float y, int n, float length, float rad) {
    if (n == level) return;

    float x2 = x + length * cos(rad);
    float y2 = y + length * sin(rad);

    ofDrawLine(x, y, x2, y2);

    ofFill();
    ofSetColor(ofColor::paleVioletRed); //color for the most beautiful tree y'all ever seen <3
    ofDrawLine(x, y, x2, y2);
    ofSetColor(ofColor::white);

    drawMode2(x2, y2, n - 1, 0.7 * length, rad + 0.2 * PI);
    drawMode2(x2, y2, n - 1, 0.7 * length, rad - 0.2 * PI);
}

void ofApp::drawMode3(float x, float y, float size, int n) {
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

    drawMode3(x, y, size / 2, n - 1);
    drawMode3((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
}

void ofApp::drawMode4(float x, float y, float n) {
    if (n == level) return;

    float r = ofRandom(1);

    float px = ofMap(x, -2.1820, 2.6558, 0, ofGetWidth());
    float py = ofMap(y, 0, 9.9983, ofGetHeight(), 0);

    ofFill();
    ofSetColor(ofColor::lightYellow); //color for the leaf
    ofDrawCircle(px, py, 0.6);
    ofSetColor(ofColor::white);

    if (r < 0.01)
        drawMode4(0, 0.16 * y, n - 1);

    else if (r < 0.86)
        drawMode4(0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6, n - 1);

    else if (r < 0.93)
        drawMode4(0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6, n - 1);

    else
        drawMode4(-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44, n - 1);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

    if (key >= '1' && key <= '5')
        mode = key;
    else if (key == OF_KEY_F11)
        ofSetFullscreen(fullscreen++ % 2 == 0);
    else if (key == OF_KEY_ESC)
        ofSetFullscreen(false);
    else if (key == OF_KEY_RIGHT){
        if (level > -3){ //added a limit to prevent crashing. its going backwards on the snowflake
            level--; 
        }
    }
    else if (key == OF_KEY_LEFT){
        if (level < 3){ //added a limit to prevent crashing. its going backwards
            level++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}