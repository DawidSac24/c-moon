//
// Created by dawid on 10/29/26.
//

#include "../../include/core/Simulation.hpp"
#include "../../include/forces/Gravity.hpp"

#include <iostream>

void Simulation::tick(int deltaTime) {
    clearBodiesNetForces();
    calculateGravitationalForce();
    updatePositions(deltaTime);
}

void Simulation::addBody(RigidBody *body) {
    bodies_.push_back(std::unique_ptr<RigidBody>(body));
}

// void Simulation::removeBody(RigidBody *body) {
//     throw std::runtime_error("Not implemented");
// }

void Simulation::clearBodiesNetForces() const {
    for (auto &&body: bodies_) {
        body->net_force.clear();
    }
}

void Simulation::calculateGravitationalForce() {
    for (size_t i = 0; i < bodies_.size(); ++i) {
        for (size_t j = i + 1; j < bodies_.size(); ++j) {
            const Vector3 force = Gravity::calculate(*bodies_[i], *bodies_[j]);

            bodies_[i]->net_force += force;
            bodies_[j]->net_force -= force;
        }
    }
}

void Simulation::updatePositions(int deltaTime) const {
    for (auto &&body: bodies_) {
        const Vector3 acceleration = body->net_force / body->mass;
        body->velocity += acceleration * deltaTime;
        body->position += body->velocity * deltaTime;

        std::cout << body->position.x << " " << body->position.y << " " << body->position.z << std::endl;
    }
}
