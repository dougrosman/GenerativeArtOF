#include "Particle.h"


void Particle::update()
{
    vel+=accel;
    //vel+=drag;
    pos+=vel;
}
