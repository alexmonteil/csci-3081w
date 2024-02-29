#include "Helicopter.h"

Helicopter::Helicopter(const JsonObject& obj) : IEntity(obj) {
    destination = {((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400,
           position.y,
           ((static_cast<double>(rand())) / RAND_MAX) * (1600) - 800};
}

Helicopter::~Helicopter() {};

void Helicopter::update(double dt) {

    // if the difference between current position and destination is small enough
    // Then consider current position destination.

    // Follow python pseudo code + use methods offered by vector3 class to achieve update logic

}

Vector3 Helicopter::getDestination() const {
   return destination; 
}