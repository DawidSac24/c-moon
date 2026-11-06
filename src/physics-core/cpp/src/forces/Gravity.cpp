//
// Created by dawid on 10/29/26.
//

#include "../../include/forces/Gravity.hpp"

Vector3 Gravity::calculate(const RigidBody &body, const RigidBody &other) {
    const Vector3 r = body.position - other.position;
    const float distance = r.length();
    if (distance == 0.0f) return {};
    const Vector3 direction = r / distance;

    const double forceMagnitude = -GRAVITATIONAL_CONSTANT * body.mass * other.mass / r.magnitudeSquared();
    return direction * forceMagnitude;
}
