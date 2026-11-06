//
// Created by dawid on 10/29/26.
//

#ifndef ENGINE_RIGIDBODY_HPP
#define ENGINE_RIGIDBODY_HPP


#include "../math/Vector3.hpp"

class RigidBody {
public:
    Vector3 position;
    Vector3 velocity;
    Vector3 net_force;
    float mass;

    RigidBody(float mass) : mass(mass) {
    }

    RigidBody(Vector3 position, float mass) : position(position), mass(mass) {
    }

    ~RigidBody() = default;

    void onUpdate(int deltaTime);
};

#endif //ENGINE_RIGIDBODY_HPP
