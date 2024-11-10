// RightFootComponent.h
#ifndef SRC_ENTITIES_PLAYER_COMPONENTS_RIGHT_FOOT_COMPONENT_H
#define SRC_ENTITIES_PLAYER_COMPONENTS_RIGHT_FOOT_COMPONENT_H

#include <raylib.hpp>
#include "../../../core/Components.h"

struct RightFootComponent {
    float radius_;
    Vector2 pos_;
    Vector2 idlePos_;
    Vector2 goalPosition_;
    bool moving_;

    RightFootComponent(Vector2 pos)
        : radius_(10.0f)
        , pos_(pos)
        , goalPosition_(pos)
        , idlePos_(pos)
        , moving_(false)
        {};
};

#endif // SRC_ENTITIES_PLAYER_COMPONENTS_RIGHT_FOOT_COMPONENT_H