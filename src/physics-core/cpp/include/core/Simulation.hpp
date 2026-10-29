//
// Created by dawid on 10/29/26.
//

#ifndef ENGINE_SIMULATION_HPP
#define ENGINE_SIMULATION_HPP
#include <memory>
#include <vector>

#include "RigidBody.hpp"

#endif //ENGINE_SIMULATION_HPP

class Simulation {
public:
    Simulation() = default;

    ~Simulation() = default;

    void tick(u_int64_t deltaTime);

private:
    std::vector<std::unique_ptr<RigidBody> > bodies_;
};
