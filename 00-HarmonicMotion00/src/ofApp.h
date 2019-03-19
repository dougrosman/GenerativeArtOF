#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
    void keyPressed(int key);
    
    float circleSize = 0;
    float heightRange = 1;
    float rate = 10000;
    float circleSizeMult = 1;
    float alpha = 255;
    float sat = 255;
    float lineWidth = 1;
    
};
