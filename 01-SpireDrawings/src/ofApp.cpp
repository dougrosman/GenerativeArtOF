#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    r = 0;
    x = 0;
    
    ofBackground(255);
    ofSetColor(255, 255, 255);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetBackgroundAuto(false);
    shouldDrawGui = true;
    guiWidth = 1080;
    guiHeight = 25;
    guiX = 0;
    guiY = 0;
    
    setupGui();
    
}

//--------------------------------------------------------------


void ofApp::draw(){
    
    ofPushMatrix();
    
    ofPushStyle();
    ofSetColor(0);
    ofNoFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofTranslate(x, ofGetHeight()/2);
    ofRotateDeg(r);
    
    ofDrawRectangle(0, 0, size, size);
    ofPopStyle();
    ofPopMatrix();
    
    
    x+=xRate;
    r+=rotation;
    
    if(x > ofGetWidth() + size)
    {
        reset();
    }
    
    drawGui();
    
    if(!shouldDrawGui)
    {
        ofSetColor(255, 255, 255);
        ofDrawRectangle(guiX, guiY, guiWidth+20, guiHeight*5);
    }
    
    
    
    
    
//    ofBeginShape();
//
//    ofVertex(x, y);
//    ofVertex(m, n);
//    ofVertex(o, p);
//
//    ofEndShape;
    

}

void ofApp::reset(){
    
    x = 0;
    r = 0;
    fade = 0;
    ofSetColor(255, 255, 255);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}

void ofApp::setupGui(){
    
    squareParams.setup();
    squareParams.setSize(guiWidth, guiHeight);
    squareParams.setPosition(guiX, guiY);
    ofxGuiSetDefaultWidth(guiWidth);
    ofxGuiSetDefaultHeight(guiHeight);
    squareParams.add(size.set("Size", 100, 0, 600 ));
    squareParams.add(xRate.set("xRate", 1, 0.25, 50 ));
    squareParams.add(rotation.set("Rotation", 1, 0, 180 ));
    squareParams.add(fade.set("Fade", 1, 0, 4 ));
}

void ofApp::drawGui(){
    
    
    squareParams.draw();
    
    
    
}

void ofApp::keyPressed(int key){
 
    if(key == 'g')
    {
        shouldDrawGui = !shouldDrawGui;
    }
    
    if (key == 'r')
    {
        reset();
    }
}
