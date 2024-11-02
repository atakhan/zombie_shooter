#ifndef SRC_ENTITIES_ZOMBIE_COMPONENTS_ZOMBIE_COMPONENT_H
#define SRC_ENTITIES_ZOMBIE_COMPONENTS_ZOMBIE_COMPONENT_H

struct ZombieComponent {
    enum class Status {
        IDLE,
        WALK,
        RUN,
        ATTACK
    };
    bool isAlive;
    Status currentState;

    ZombieComponent() : currentState(Status::WALK) {}
};

#endif // SRC_ENTITIES_ZOMBIE_COMPONENTS_ZOMBIE_COMPONENT_H
