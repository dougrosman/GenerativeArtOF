#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    
    bass.load("bass.aif");
    snare.load("snare.aif");
    
    snare.setMultiPlay(true);
    bass.setMultiPlay(true);
    for(int i = 0; i < numParticles; i++)
    {
        Particle p;
        p.pos = {0, 0, 0};
        p.vel = {ofRandom(-4, 4), ofRandom(-4, 4), ofRandom(-4, 4)};
        p.accel = {ofRandom(-0.01, 0.01), ofRandom(-0.01, 0.01), ofRandom(-0.02, 0.02)};
        p.size = 2;
        p.drag = 0.01;
        
        float velTotal = p.vel.x + p.vel.y + p.vel.z;
        float hue = ofMap(velTotal, -12, 12, 0, 60);
        
        p.color = ofColor::fromHsb(hue, 255, 255);
        particles.push_back(p);
    }
}


void ofApp::update()
{
    ofSoundUpdate();
    
    for(auto& p : particles)
    {
        p.update();
        
        if(p.pos.x < -boxSize/2 || p.pos.x > boxSize/2)
        {
            p.vel.x*=-1;
            snare.play();
        }
        if(p.pos.y < -boxSize/2 || p.pos.y > boxSize/2)
        {
            p.vel.y*=-1;
            snare.play();
        }
        if(p.pos.z < -boxSize/2 || p.pos.z > boxSize/2)
        {
            p.vel.z*=-1;
            bass.play();
        }
    }
}


void ofApp::draw()
{
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    cam.begin();
    ofPushMatrix();
    ofTranslate(w/2, h/2, 0);
    
    for(auto& p : particles)
    {
        ofSetColor(p.color);
        ofDrawSphere(p.pos, p.size);
        
    }
    ofNoFill();
    ofSetColor(255);
    ofDrawBox(0, 0, 0, boxSize);
    ofPopMatrix();
    cam.end();
}


void ofApp::keyPressed(int key){

}


void ofApp::keyReleased(int key){

}


void ofApp::mouseMoved(int x, int y ){

}


void ofApp::mouseDragged(int x, int y, int button){

}


void ofApp::mousePressed(int x, int y, int button){

}


void ofApp::mouseReleased(int x, int y, int button){

}


void ofApp::mouseEntered(int x, int y){

}


void ofApp::mouseExited(int x, int y){

}


void ofApp::windowResized(int w, int h){

}


void ofApp::gotMessage(ofMessage msg){

}


void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
