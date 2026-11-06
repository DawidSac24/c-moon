//
// Created by dawid on 10/29/26.
//

#ifndef ENGINE_SIMULATION_HPP
#define ENGINE_SIMULATION_HPP

#include <memory>
#include <vector>

#include "RigidBody.hpp"

class Simulation {
public:
    Simulation() = default;

    ~Simulation() = default;

    void tick(int deltaTime);

    void addBody(RigidBody *body);

    // void removeBody(RigidBody *body);

private:
    std::vector<std::unique_ptr<RigidBody> > bodies_;

    void clearBodiesNetForces() const;

    void calculateGravitationalForce();

    void updatePositions(int deltaTime) const;
};

#endif //ENGINE_SIMULATION_HPP