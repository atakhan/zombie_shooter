#ifndef HUMAN_COMPONENT_H
#define HUMAN_COMPONENT_H

struct HumanComponent {
    enum class Status {
        SLEEP,
        IDLE,
        LOOT,
        WALK,
        RUN,
        ATTACK
    };
    bool isAlive;
    Status currentStatus;

    HumanComponent() 
        : currentStatus(Status::WALK)
        , isAlive(true) 
    {}
};

#endif // HUMAN_COMPONENT_H
