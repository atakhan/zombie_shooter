#ifndef SRC_COMPONENTS_PLAYER_COMPONENT_H
#define SRC_COMPONENTS_PLAYER_COMPONENT_H

struct PlayerComponent {
    enum state {
        IDLE,
        HALT,
        WALK,
        RUN,
        ATTACK
    };
    bool isAlive_;
    state currentState_;

    PlayerComponent() : isAlive_(true), currentState_(IDLE) {};
};

#endif // SRC_COMPONENTS_PLAYER_COMPONENT_H
