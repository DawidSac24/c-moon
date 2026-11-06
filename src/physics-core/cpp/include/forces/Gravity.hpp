//
// Created by dawid on 10/29/26.
//

#ifndef ENGINE_GRAVITY_HPP
#define ENGINE_GRAVITY_HPP

#include "../../include/core/RigidBody.hpp"
#include "../../include/math/Vector3.hpp"
#include <cmath>

static const double GRAVITATIONAL_CONSTANT = 6.67430 * pow(10, -11);


class Gravity {
public:
    // Using Newton's law of gravitation to calculate the acceleration and applies the accumulated force +F to body 1 and -F to body 2
    static Vector3 calculate(const RigidBody &body, const RigidBody &other);
};


#endif //ENGINE_GRAVITY_HPP
