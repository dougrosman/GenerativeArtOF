#pragma once

#include "ofMain.h"

class Particle {

	public:
		void setup();
		void update();
		void draw();
    
    
    float size;
    
    glm::vec3 pos;
    glm::vec3 vel;
    glm::vec3 accel;
    
    float drag;
    
    ofColor color;
    
    
		
};
