#ifndef ZOMBIE_COMPONENT_H
#define ZOMBIE_COMPONENT_H

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

#endif // ZOMBIE_COMPONENT_H
