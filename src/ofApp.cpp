#include "ofApp.hpp"
#include "SnowFlake.hpp"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetEscapeQuitsApp(false);
    fullscreen = 0;
    float length = 0.31 * ofGetHeight();
    animationTimer = 30;

    Circle* newCircle = new Circle("circle", 3, ofGetWidth() / 2, ofGetHeight() / 2, 0.31 * ofGetHeight());
    Tree* newTree = new Tree("Tree", 10, ofGetWidth() / 2, ofGetHeight() - 20, length, 1.5 * PI);
    Triangle* newTriangle = new Triangle("Sierpinski Triangle", 7, (ofGetWidth() - (0.88 * ofGetHeight())) / 2, ofGetHeight() / 2 - 0.4 * (0.88 * ofGetHeight()), (0.88 * ofGetHeight()));
    Fern* newFern = new Fern("Bernsley Fern", 10 * 1000, 0, 0);
    SnowFlake* newFlake = new SnowFlake();

    polymorphic.push_back(newCircle);
    polymorphic.push_back(newTree);
    polymorphic.push_back(newTriangle);
    polymorphic.push_back(newFern);
    polymorphic.push_back(newFlake);

}

//--------------------------------------------------------------
void ofApp::update() {
    if (animation == true){
        if (animationUp == true){
            if (polymorphic[index]->getLevel() < polymorphic[index]->getLimit()){
                if (animationTimer == 0){
                    if (index != 3){
                        polymorphic[index]->setLevel(polymorphic[index]->getLevel() + 1);
                    }
                    else {
                        polymorphic[index]->setLevel(polymorphic[index]->getLevel() + 1000);
                    }
                    animationTimer = 30;
                }
            }
            else {
                animationUp = false;
            }
        }
        else {
            if (polymorphic[index]->getLevel() > 0){
                if (animationTimer == 0){
                    if (index != 3){
                        polymorphic[index]->setLevel(polymorphic[index]->getLevel() - 1);
                    }
                    else {
                        polymorphic[index]->setLevel(polymorphic[index]->getLevel() - 1000);
                    }
                    animationTimer = 30;
                }
            }
            else {
                animationUp = true;
            }
        }
        animationTimer--;
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

    ofNoFill();
    polymorphic[index]->draw();
    ofSetColor(ofColor::white);
    ofDrawBitmapString(polymorphic[index]->getName(), 50, 50);
    ofDrawBitmapString("Level: " + ofToString(polymorphic[index]->getLevel()), 50, 75);

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

    if (key >= '1' && key <= '5'){
        switch(key){
        case '1':
            index = 0;
            break;
        case '2':
            index = 1;
            break;
        case '3':
            index = 2;
            break;
        case '4':
            index = 3;
            break;
        case '5':
            index = 4;
            break;
        }
    }
    else if (key == OF_KEY_F11)
        ofSetFullscreen(fullscreen++ % 2 == 0);
    else if (key == OF_KEY_ESC)
        ofSetFullscreen(false);
    else if (key == OF_KEY_RIGHT){
        if (index != 3){
            if (polymorphic[index]->getLevel() < polymorphic[index]->getLimit()){ //added a limit to prevent crashing.
                polymorphic[index]->setLevel(polymorphic[index]->getLevel() + 1);
            }
        }
        else {
            if (polymorphic[index]->getLevel() < polymorphic[index]->getLimit()){
                polymorphic[index]->setLevel(polymorphic[index]->getLevel() + 1000);
            }
        }
    }
    else if (key == OF_KEY_LEFT){
        if (index != 3) {
            if (polymorphic[index]->getLevel() > 0){ //added a limit to prevent crashing.
                polymorphic[index]->setLevel(polymorphic[index]->getLevel() - 1);
            }
        }
        else {
            if (polymorphic[index]->getLevel() > 0){
                polymorphic[index]->setLevel(polymorphic[index]->getLevel() - 1000);
            }
        }
    }
    else if (key == ' '){
        if (animation == true){
            animation = false;
        }
        else {
            animation = true;
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