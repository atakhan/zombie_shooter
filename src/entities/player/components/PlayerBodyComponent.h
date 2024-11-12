// PlayerBodyComponent.h
#ifndef SRC_ENTITIES_PLAYER_COMPONENTS_PLAYER_BODY_COMPONENT_H
#define SRC_ENTITIES_PLAYER_COMPONENTS_PLAYER_BODY_COMPONENT_H

#include <raylib.hpp>
#include "../../../core/Components.h"

struct PlayerBodyComponent {
    float radius_;
    Vector2 pos_;

    PlayerBodyComponent(Vector2 pos, float radius)
        : radius_(radius)
        , pos_(pos)
        {};
};

#endif // SRC_ENTITIES_PLAYER_COMPONENTS_PLAYER_BODY_COMPONENT_H
