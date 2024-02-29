#ifndef HELICOPTER_H_
#define HELICOPTER_H_

#include "IEntity.h"

/**
 * @class Helicopter 
 * @brief Represents a drone in a physical system.
 * 
 */
class Helicopter : public IEntity {
    public:
        Helicopter(const JsonObject& obj);
        ~Helicopter();
        void update(double dt);
        Vector3 getDestination() const;

        /**
         * @brief Removing the copy constructor operator
         * so that helicopters cannot be copied.
         */
        Helicopter(const Helicopter& helicopter) = delete;

        /**
         * @brief Removing the assignment operator
         * so that helicopters cannot be copied.
         */
        Helicopter& operator=(const Helicopter& helicopter) = delete;


    private:
        const double MIN_DISTANCE = 0.5; 
        Vector3 destination; 
        Vector3 getRandomPosition() const;       

};

#endif