#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
    
    void setup();
    void draw();
    void keyPressed(int key);
    
    void reset();
    void setupGui();
    void drawGui();

    float r;
    float x;

    int guiX;
    int guiY;
    
    int guiWidth;
    int guiHeight;
    
    
    
    
    
        // GUI
    
    bool shouldDrawGui;
    ofxPanel squareParams;
    ofParameter<float> size;
    ofParameter<float> xRate;
    ofParameter<float> rotation;
    ofParameter<float> fade;
    
    
    
    
        
};
