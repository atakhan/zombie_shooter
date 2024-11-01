#ifndef SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_HUMAN_COMPONENT_H
#define SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_HUMAN_COMPONENT_H

#include <raylib-cpp.hpp>

struct HumanComponent {
    enum class Status {
        SLEEP,
        IDLE,
        LOOT,
        WALK,
        RUN,
        ATTACK
    };

    bool isAlive_;
    bool isTargetReached_;
    Status currentStatus_;
    Vector2 position_;
    Vector2 target_;
    float health_;
    float stamina_;
    float staminaMaxValue_;
    float staminaMinValue_;

    HumanComponent()
        : currentStatus_(Status::IDLE)
        , isTargetReached_(false)
        , isAlive_(true) 
        , position_({0.0f, 0.0f})
        , target_({0.0f, 0.0f})
        , health_(100.0f)
        , staminaMaxValue_(100.0f)
        , staminaMinValue_(1.0f)
    {}
};

#endif // SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_HUMAN_COMPONENT_H
