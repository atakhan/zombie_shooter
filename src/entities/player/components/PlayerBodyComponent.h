// PlayerBodyComponent.h
#ifndef SRC_ENTITIES_PLAYER_COMPONENTS_PLAYER_BODY_COMPONENT_H
#define SRC_ENTITIES_PLAYER_COMPONENTS_PLAYER_BODY_COMPONENT_H

#include <raylib.hpp>
#include "../../../core/Components.h"

struct PlayerBodyComponent {
    float radius_;
    float rotation_;
    float shadowRotation_;
    float limit_; // todo: naming?
    Vector2 pos_;
    Vector2 idlePos_;
    Vector2 goalPosition_;
    bool moving_;

    PlayerBodyComponent(Vector2 pos, float rotation, float visionLimit)
        : radius_(10.0f)
        , rotation_(rotation)
        , shadowRotation_(rotation)
        , limit_(visionLimit)
        , pos_(pos)
        , goalPosition_(pos)
        , idlePos_(pos)
        , moving_(false)
        {};
};

#endif // SRC_ENTITIES_PLAYER_COMPONENTS_PLAYER_BODY_COMPONENT_H
