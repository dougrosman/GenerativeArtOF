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
    
    // PDF
    isSaving = false;
    
    fbo.allocate(ofGetWidth(), ofGetHeight());
    fbo.begin();
    ofClear(0);
    fbo.end();
    
    img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    
}

//--------------------------------------------------------------


void ofApp::draw(){
    
    
    fbo.begin();
    ofPushMatrix();
    
    ofPushStyle();
    ofSetColor(0);
    ofNoFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofTranslate(x, ofGetHeight()/2);
    ofRotateDeg(r);
    
    // ofDrawRectangle(0, 0, size, size);
    float xRateMouse = ofMap(ofGetMouseX(), 0, 1440, 0.0, 5.0);
    sizeMouse = ofMap(ofGetMouseY(), 0, 900, 0.0, 400.0);
    ofDrawRectangle(0, 0, sizeMouse, sizeMouse);
    ofPopStyle();
    ofPopMatrix();
    
    //x+=xRate;
    r+=rotation;
    x+=xRateMouse;
    
    fbo.end();
    fbo.draw(0, 0);
    
    //if(x > ofGetWidth() + size)
    if(x > ofGetWidth() - sizeMouse)
    {
        ofBeginSaveScreenAsPDF("screenshot_"+ofGetTimestampString()+".pdf");
        ofEndSaveScreenAsPDF();
        reset();
    }
    
    
    
//    if(!shouldDrawGui)
//    {
//        ofSetColor(255, 255, 255);
//        ofDrawRectangle(guiX, guiY, guiWidth+20, guiHeight*5);
//    }
//    else{
//        drawGui();
//    }
    
    
    
    
    
//    ofBeginShape();
//
//    ofVertex(x, y);
//    ofVertex(m, n);
//    ofVertex(o, p);
//
//    ofEndShape;
    

}

void ofApp::reset(){
    
    x = sizeMouse;
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
    
    else if (key == 'r')
    {
        reset();
    }
    
    else if (key == 's') {
        isSaving = true;
    }
    
    else if (key == OF_KEY_RIGHT)
    {
        rotation+=0.1;
    }
    
    else if (key == OF_KEY_LEFT)
    {
        rotation-=0.1;
    }
}
