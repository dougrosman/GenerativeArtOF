#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    ofSetCircleResolution(80);
    circleSize = 2;
    //ofSetBackgroundAuto(false);
}

void ofApp::update()
{

}

void ofApp::draw()
{
    
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    
    
    float spacing = circleSize*2;
    float rightLimit = w - spacing + 1;
    
    //ofSetColor(0);
    
    for(int i = spacing; i < rightLimit; i+=spacing)
    {
        float t = ofGetElapsedTimef();
        float phase = i/spacing;
        float hue = ofMap(sin(ofRadToDeg(t*i/rate))*heightRange, -heightRange, heightRange, 0, 255);
        ofPushMatrix();
        ofTranslate(i, h/2);
        ofSetColor(ofColor::fromHsb(hue, sat, 255, alpha));
        ofDrawCircle(0, sin(ofRadToDeg(t*i/rate))*heightRange, (circleSize*circleSizeMult)/2);
        
//        ofDrawLine(0, sin(ofRadToDeg(t*i/rate))*heightRange, 0, sin(ofRadToDeg(t*(i+spacing)/rate))*heightRange);

        ofSetLineWidth(lineWidth);
        ofDrawLine(cos(ofRadToDeg(t*i/rate))*heightRange, sin(ofRadToDeg(t*i/rate))*heightRange, cos(ofRadToDeg(t*(i+spacing)/rate))*heightRange, sin(ofRadToDeg(t*(i+spacing)/rate))*heightRange);
        
        ofPopMatrix();
        //std::cout << sin(ofRadToDeg(t*i/20000))*200 << std::endl;
    }
}

void ofApp::keyPressed(int key)
{
    if(key == ',' && circleSize > 1)
    {
        circleSize--;
    }
    else if(key == '.')
    {
        circleSize++;
    }
    
    else if(key == '[' && heightRange > 1)
    {
        heightRange-=2;
    }
    
    else if(key == ']' && heightRange < 1440)
    {
        heightRange+=2;
    }
    
    else if(key == '9' && rate > 1001)
    {
        rate-=1000;
    }
    
    else if(key == '0' && rate < 100000)
    {
        rate+=1000;
    }
    
    else if(key == '-' && circleSizeMult > 1)
    {
        circleSizeMult-=1;
    }
    
    else if(key == '=' && circleSizeMult < 100)
    {
        circleSizeMult+=1;
    }
    
    else if(key == 'a' && alpha > 0)
    {
        alpha-=1;
    }
    
    else if(key == 's' && alpha < 255)
    {
        alpha+=1;
    }
    
    else if(key == 'q' && sat > 0)
    {
        sat-=2;
    }
    
    else if(key == 'w' && sat < 255)
    {
        sat+=2;
    }
    
    else if(key == 'z' && lineWidth > 1)
    {
        lineWidth-=1;
    }
    
    else if(key == 'x' && lineWidth < 200)
    {
        lineWidth+=1;
    }
    
    
}

