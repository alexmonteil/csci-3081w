#include "Helicopter.h"

Helicopter::Helicopter(const JsonObject& obj) : IEntity(obj) {
  destination = getRandomPosition();
}

Helicopter::~Helicopter() {}

void Helicopter::update(double dt) {
  // if the difference between current position and destination is small enough
  // Then consider current position destination.

  if (position.dist(destination) < MIN_DISTANCE) {
    // get new random position
    destination = getRandomPosition();

  } else {
    // move helicopter towards destination
    Vector3 diff = destination - position;
    Vector3 diff_unit = diff.unit();
    Vector3 movement_vector = diff_unit * speed * dt;
    position = position + movement_vector;
  }
}

Vector3 Helicopter::getRandomPosition() const {
  return {((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400,
          position.y,
          ((static_cast<double>(rand())) / RAND_MAX) * (1600) - 800};
}
