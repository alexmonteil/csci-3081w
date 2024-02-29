#include "Human.h"

Human::Human(const JsonObject& obj) : IEntity(obj) {
  Vector3 destination1(146, 265, -121);
  destination = destination1;
}

Human::~Human() {}

void Human::update(double dt) {
  // if the difference between current position and destination is small enough
  // Then consider current position destination.

  if (position.dist(destination) < MIN_DISTANCE) {
    // reset the destination so the human keeps walking back and forth
    Vector3 destination1(146, 265, -121);
    if (destination == destination1) {
      Vector3 destination2(-191, 265, -112);
      destination = destination2;
    } else {
      destination = destination1;
    }

  } else {
    // move Human towards destination
    Vector3 diff = destination - position;
    Vector3 diff_unit = diff.unit();
    Vector3 movement_vector = diff_unit * speed * dt;
    position = position + movement_vector;
  }
}
