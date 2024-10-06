#ifndef SRC_COMPONENTS_ZOMBIE_COMPONENT_H
#define SRC_COMPONENTS_ZOMBIE_COMPONENT_H

struct ZombieComponent {
    enum class Status {
        IDLE,
        WALK,
        RUN,
        ATTACK
    };
    bool isAlive;
    Status currentState;
};

#endif // SRC_COMPONENTS_ZOMBIE_COMPONENT_H
