#ifndef HUMAN_H_
#define HUMAN_H_

#include "IEntity.h"

/**
 * @class Human
 * @brief Represents a human in a physical system.
 */
class Human : public IEntity {
 public:
  /**
   * @brief Parameter constructor - constructs a new Human object
   *
   * @param obj JSON object containing the Human's information
   */
  Human(const JsonObject& obj);

  /**
   * @brief Destructor
   *
   */
  ~Human();

  /**
   * @brief Updates the Human's position within the simulation
   *
   * @param dt Delta time
   */
  void update(double dt);

  /**
   * @brief Removes the copy constructor operator
   * so that helicopters cannot be copied.
   */
  Human(const Human& human) = delete;

  /**
   * @brief Removes the assignment operator
   * so that helicopters cannot be copied.
   */
  Human& operator=(const Human& human) = delete;

 private:
  const double MIN_DISTANCE = 0.1;
  Vector3 destination;
};

#endif
