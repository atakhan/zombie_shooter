// LeftFootComponent.h
#ifndef SRC_ENTITIES_PLAYER_COMPONENTS_LEFT_FOOT_COMPONENT_H
#define SRC_ENTITIES_PLAYER_COMPONENTS_LEFT_FOOT_COMPONENT_H

#include <raylib.hpp>
#include "../../../core/Components.h"

struct LeftFootComponent {
    Rectangle bone_;
    Vector2 origin_;
    Vector2 goalPosition_;
    float rotation_;
    bool moving_;

    LeftFootComponent()
        : bone_({0.0f, 0.0f, 0.0f, 0.0f})
        , origin_({ 0.0f, 0.0f })
        , goalPosition_({ 0.0f, 0.0f })
        , rotation_(0.0f)
        , moving_(false)
        {};
};

#endif // SRC_ENTITIES_PLAYER_COMPONENTS_LEFT_FOOT_COMPONENT_H
