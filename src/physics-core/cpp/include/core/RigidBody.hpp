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
    Vector3 net_froce;
    float mass;

    RigidBody() : position(0, 0, 0), velocity(0, 0, 0), mass(0) {
    }

    RigidBody(Vector3 position, float mass) : position(position), velocity(0, 0, 0), mass(mass) {
    }

    ~RigidBody() {
    }

    void onUpdate(u_int64_t deltaTime);
};

#endif //ENGINE_RIGIDBODY_HPP
