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

        /**
         * @brief Parameter constructor - constructs a new Helicopter object
         * 
         * @param obj JSON object containing the Helicopters's information
         */
        Helicopter(const JsonObject& obj);

        /**
         * @brief Destructor
         * 
         */
        ~Helicopter();

        /**
         * @brief Updates the Helicopter's position within the simulation
         * 
         * @param dt Delta time
         */
        void update(double dt);


        /**
         * @brief Removes the copy constructor operator
         * so that helicopters cannot be copied.
         */
        Helicopter(const Helicopter& helicopter) = delete;

        /**
         * @brief Removes the assignment operator
         * so that helicopters cannot be copied.
         */
        Helicopter& operator=(const Helicopter& helicopter) = delete;


    private:
        const double MIN_DISTANCE = 0.1;
        Vector3 destination; 
        Vector3 getRandomPosition() const;       

};

#endif