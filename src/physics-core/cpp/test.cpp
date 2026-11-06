#include "./include/core/Simulation.hpp"
#include "./include/core/RigidBody.hpp"

int main() {
    Simulation simulation;
    simulation.addBody(new RigidBody(1));
    simulation.addBody(new RigidBody({3, 3, 3}, 100));

    for (int i = 0; i < 100; ++i) {
        simulation.tick(1);
    }

    return 0;
}
