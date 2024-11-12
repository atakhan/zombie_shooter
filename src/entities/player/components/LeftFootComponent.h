// LeftFootComponent.h
#ifndef SRC_ENTITIES_PLAYER_COMPONENTS_LEFT_FOOT_COMPONENT_H
#define SRC_ENTITIES_PLAYER_COMPONENTS_LEFT_FOOT_COMPONENT_H

#include <raylib.hpp>
#include "../../../core/Components.h"

struct LeftFootComponent {
    float radius_;
    Vector2 pos_;
    Vector2 idlePos_;
    Vector2 goalPosition_;
    bool moving_;
    Color color_;

    LeftFootComponent(Vector2 pos, Color color)
        : radius_(10.0f)
        , pos_(pos)
        , goalPosition_(pos)
        , idlePos_(pos)
        , moving_(false)
        , color_(color)
        {};
};

#endif // SRC_ENTITIES_PLAYER_COMPONENTS_LEFT_FOOT_COMPONENT_H
